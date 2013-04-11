#include <d2_common.h>

//  < the Circular linked-list, Queue and Stack base linked-list >
//
//  +--------------------+
//  |      +------+      |  prev
//  +--    |      |    <-+
//  (head) | node |
//  +->    |      |    --+
//  |      +------+      |  next
//  +--------------------+
//
//       |         ^
//       | ADD/DEL |
//       v         |
//
//  +-----------------------------------------------------+
//  |      +------+    +------+    +------+    +------+   |  prev
//  +--    |      | <- |      | <- |      | <- |      | <-+
//  (head) | node |    | node |    | .... |    | node |
//  +->    |      | -> |      | -> |      | -> |      | --+
//  |      +------+    +------+    +------+    +------+   |  next
//  +-----------------------------------------------------+
//
//             the general linked-list for d2 project


struct node {
    struct node     *prev;
    struct node     *next;
};

#define d2_list_init_head(list)         \
            struct node list = {&(list),&(list)}

#define d2_list_head_init(list) do  {   \
            (list)->prev = (list);      \
            (list)->next = (list);      \
        }

#define d2_offsetof(type, member)       \
        ((unsigned int) &(((type *)0)->member))

#define d2_get_entry(type, m, addr)     \
        ((char *)addr - d2_offsetof (type, m))

/*
=====================
d2_list_add_head
=====================
*/
void d2_list_add_head (struct node *node, struct node *list)
{
    node->next = list->next;
    node->prev = list;
    list->next->prev = node;
    list->next = node;
}

/*
=====================
d2_list_add_tail
=====================
*/
void d2_list_add_tail (struct node *node, struct node *list)
{
    node->next = list;
    node->prev = list->prev;
    node->prev->next = node;
    list->prev = node;
}

/*
=====================
d2_list_del
=====================
*/
void d2_list_del (struct node *node, struct node *list)
{
    // is head node.
    if (node->prev == list) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
        //node->next = node->prev = NULL;
    }
    // is tail node.
    else if (node->next == list) {
        node->prev->next = node->next;
        list->prev = node->prev;
        //node->next = node->prev = NULL;
    }
    else {
        node->next->prev = node->prev;
        node->prev->next = node->next;
        //node->next = node->prev = NULL;
    }
}

/*
=====================
d2_list_for_each
=====================
*/
#define d2_list_for_each(node, list)    \
        for ((node)  = (list)->next;    \
             (node) != (list);          \
             (node)  = (node)->next)


/*
=====================
d2_is_empty
=====================
*/
d2_bool d2_is_empty (struct node *list)
{
    return ((list->next==list) ? d2_false : d2_true);
    // return ((list->prev==list) ? d2_false : d2_true);
}

/*
=====================
d2_is_last
=====================
*/
d2_bool d2_is_last (struct node *node, struct node *list)
{
    return ((node->next==list && list->next==node) ? d2_true : d2_false);
    // return ((list->prev==node && node->prev==list) ? d2_true : d2_false);
}

//                       
//           pop       |
//       +-------->    |
//  |    |    |        |    |         |
//  | element | <-    -->   |         |
//  | element |        |    | element | <-
//  | element |        |    | element |
//  |_________|        |    |_________|
//     stack                   stack
//
struct node* d2_stack_pop (struct node *stack)
{
    struct node *node = NULL;
    if (!d2_is_empty (stack)) {
        node = stack->next;
        d2_list_del (node, stack);
    }

    return (node);
}
void d2_stack_top (struct node *node, struct node *stack)
{
    node = NULL;
    if (!d2_is_empty (stack)) {
        node = stack->next;
    } 
}

//
//         push        |
//       +---------    |
//  |    |    |        |    |         |
//  |    v    |        |    | element | <-
//  | element | <-    -->   | element |
//  | element |        |    | element |
//  |_________|        |    |_________|
//     stack                   stack
//
void d2_stack_push (struct node *node, struct node *stack)
{
    d2_list_add_head (node, stack);
}

//  QUEUE (fifo)
/*
=====================
d2_queue_enq
=====================
*/
void d2_queue_Inject (struct node *node, struct node *queue)
{
    d2_list_add_tail (node, queue);
}

/*
=====================
d2_queue_deq
=====================
*/
struct node* d2_queue_Enject (struct node *queue)
{
    struct node *node = NULL;

    if (!d2_is_empty (queue)) {
        node = queue->next;
        d2_list_del (node, queue);
    }

    return (node);
}

/////////////////////
/*
=====================
TEST
=====================
*/
typedef struct mystr {
    char        chr;        // character.
    struct node node;       // contain a node for linked-list.
} mystr;

#ifdef _LIST_STANDALONE
main (void)
{
    int i, inc = 97;
    struct node *p;
    mystr       *pstr;

    d2_list_init_head (list);
    if (!d2_is_empty (&list))
        printf ("ture.\n");
    else
        printf ("false.\n");

    for (i=0; i<5; i++) {
        if ((pstr = (mystr *)malloc(sizeof (mystr)))) {
            pstr->chr = inc++;
            d2_list_add_head (&pstr->node, &list);
        }
        else {
            printf ("out of memory.\n");
        }
    }

#if 1
    inc = 0;
    d2_list_for_each(p, &list) {
        if ((pstr = (mystr *)(d2_get_entry(mystr, node, p))))
            printf ("%x, %x, %c\n", p, pstr, pstr->chr);
        inc++;
    }
    printf ("count: %d\n\n", inc);
#endif

#if 1
    d2_list_for_each (p, &list) {
        d2_list_del (p, &list);
        
        if ((pstr = (mystr *)(d2_get_entry(mystr, node, p)))) {
            printf ("%x, %x, %c\n", p, pstr, pstr->chr);
            printf ("count after delete list: %d\n", --inc);
            free (pstr);
        }
    }
    if (!d2_is_empty (&list)) printf ("true.\n"); else printf ("false.\n");
#endif
}
#endif

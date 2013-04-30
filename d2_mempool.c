
//  +------------------------------------------------------+
//  |   +-------+    +-------+    +-------+    +-------+   |  prev
//  +-- |       | <- |       | <- |       | <- |       | <-+
//      | Block |    | Block |    | ..... |    | BList |
//  +-> |       | -> |       | -> |       | -> |       | --+
//  |   +-------+    +-------+    +-------+    +-------+   |  next
//  +------------------------------------------------------+
//
//            block list in the Memory-Management

#define d2_alloc           d2_mempool_alloc
#define d2_free            d2_mempool_free
#define d2_mempool_init(pool, size)        \
                            pool = (d2_mempool_t) malloc (size)
#define d2_mempool_destroy(pool)           \
                            free (pool);    \
                            pool = NULL

typedef enum {
    funused = 0,
    fused
}   block_flag;

// memory management on the heap.
typedef struct d2_memblock_s   d2_memblock_t;
typedef struct d2_mempool_s    d2_mempool_t;

struct d2_memblock_s {
    int              size;
    int              flag;
    d2_memblock_t   *prev;
    d2_memblock_t   *next;
    int             magic;
};

struct d2_mempool_s {
    int              size;
    int              used;
    d2_memblock_t   *curr;
    d2_memblock_t   blist;
};

#ifdef _MEMPOOL_STANDALONE
d2_pool_t         *pool;
#endif

#define     D2_POOL_MAGIC  0x03040102

/*
=====================
d2_mempool_clean
=====================
*/
void d2_mempool_clean (d2_mempool_t *pool, int size) {

    d2_memblock_t *block;

    pool->blist.next  = pool->blist.prev = block = \
    (d2_memblock_t *) ((unsigned char *) pool + sizeof (d2_mempool_t));

    pool->curr        = block;
    pool->size        = size;
    pool->used        = 0;
    pool->blist.size  = 0;
    pool->blist.flag  = 1;
    pool->blist.magic = 0;

    block->next       = block->prev = &pool->blist;
    block->size       = size - sizeof (d2_mempool_t);
    block->flag       = 0;
    block->magic      = D2_POOL_MAGIC;
}

/*
=====================
d2_mempool_check
=====================
*/
void d2_mempool_check (void) {

    d2_memblock_t  *block = pool->blist.next;  // pointer to first block.

    while (block != pool->blist) {

        if ((unsigned char *) block + block->size != \
            (unsigned char *) block->next) {
            // error: block size does not touch the next block.
        }

        if (block->next->prev != block) {
            // next block doesn't have proper back link.
        }

        if (block->flag || !block->next->flag) {
            // error: two consecutive free blocks.
        }

        block = block->next;
    }
}

/*
=====================
d2_mempool_stats
=====================
*/
void d2_mempool_stats (void) {

    unsigned int bsize = 0, asize = 0, nblock = 0;
    d2_memblock_t  *block = pool->blist->next;  // pointer to first block.

    while (block != pool->blist) {

        if (block->flag) {
            bsize += block->size;
            nblock++;
        }

        asize = nblock * sizeof (d2_memblock_t);
        block = block->next;
    }

    printf ("%d memory in %d blocks\n", bsize, nblock);
    printf ("%d memory overhead\n", bsize - asize);
}

/*
=====================
d2_mempool_free
=====================
*/
void d2_mempool_free (void *dptr) {

    d2_memblock_t  *block *base;

    if (!dptr) {
        // TODO: the NULL pointer.
        return;
    }

    base = (d2_memblock_t *) ((unsigned char *)dptr - sizeof (d2_memblock_t));
    if (base->magic != D2_POOL_MAGIC) {
        // TODO: pointer without D2_POOL_MAGIC
        return;
    }

    if (base->flag = 0) {
        // TODO: free a freed pointer.
        return;
    }

    if (*(int *)((unsigned char *) base + base.size - 4) != \
        D2_POOL_MAGIC) {
        // TODO: memory block wrote past end.
        return;
    }

    pool->used -= base->size;
    base->flag = 0;

    // merge.
    block = base->prev; // merge with prev block.
    if (!block->flag) {
        block->size += base->size;
        block->next  = base->next;
        block->next->prev  = block;
        base = block;
    }

    pool->curr = base;

    block = base->next; // merge with next block.
    if (!block->flag) {
        base->size  += block->size;
        base->next   = block->next;
        base->next->prev   = base;
    }
}

/*
=====================
d2_mempool_alloc
=====================
*/
void d2_mempool_alloc (d2_mempool_t *pool, int size) {

    int         remain;
    d2_memblock_t  *base, *curr, *start, *node;

    nalloc = size;
    size  += sizeof (d2_memblock_t);
    size  += 4;
    size   = (size + 3) & ~3;

    base   = curr = pool->curr;
    start  = base->prev;

    do {
        if (curr == start) {
            // TODO: error.
            return (NULL);
        }

        if (curr->flag)
            base = curr = curr->next;
        else
            curr = curr->next;
    }
    while (base->flag || base->size < size)

    // found then allocation.
    remain = base->size - size;

    if (remain > 64) {
        node = (d2_memblock_t *) ((unsigned char *)base + size);
        node->size = remain;
        node->flag = 0;
        node->prev = base;
        node->next = base->next;
        node->magic= D2_POOL_MAGIC;
        node->next->prev = node;

        base->next = node;
        base->size = size;
    }

    pool->curr  = base->next;
    pool->used += base->size;

    base->flag  = 1;
    base->magic = D2_POOL_MAGIC;

    *(int *)((unsigned char *)base + base->size - 4) = D2_POOL_MAGIC;

    return (void *) ((unsigned char *)base + sizeof (d2_memblock_t));
}

#ifdef _MEMPOOL_STANDALONE
typedef struct d2_person_s
{
    char name[64];
    int  index;
    char c;
} d2_person_t;
#endif
#ifdef _MEMPOOL_STANDALONE
int main ()
{
    d2_person_t        p;
    char *              s;
    int                 i;

    d2_pool_init (pool, 1024);

    p = d2_alloc (pool, sizeof (struct d2_person_t));
    strcpy (p->name, "aaaa");
    p->name[4] = '\0';
    p->index   = 1;
    p->c       = 'A';
    d2_free (p);

    p = d2_alloc (pool, sizeof (struct d2_person_t));
    strcpy (p->name, "bbbb");
    p->name[4] = '\0';
    p->index   = 2;
    p->c       = 'B';

    s = d2_alloc (pool, 99);
    strcpy (s, "cccc");
    s[4] = '\0';
    d2_free (s);
    d2_free (p);

    d2_pool_destory (pool);
}
#endif

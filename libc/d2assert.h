
//#ifndef _D2_ASSERT_H
//#define _D2_ASSERT_H

#undef  assert
#ifdef  NDEBUG
    #define assert(test)    ((void) 0)
#else
    void _Assert (char *);
    #define _STR(x) _VAL(x)
    #define _VAL(x) #x
    #define assert(test)    ((test) ? (void) 0 \
        : _Assert (__FILE__":"_STR(__LINE__)" " #test))
#endif

//#endif

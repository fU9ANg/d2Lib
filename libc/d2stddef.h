

#ifndef _D2_STDDEF_H
#define _D2_STDDEF_H

/*
typedef int             _Ptrdifft;
typedef unsigned int    _Sizet;
typedef unsigned short  _Wchart;
#define _NULL           (void *)0
*/

#define NULL    (void *)0

#define offsetof(type, member) \
        ((unsigned int) &(((type *) 0)->member))
#define offset0f(type, member) \
        ((_Sizet) & (((type *) 0)->member))

#ifndef _SIZET
#define _SIZET
typedef unsigned int  size_t;
#endif

/**
#ifndef _WCHART
#define _WCHART
typedef unsigned short wchar_t;
#endif
*/

typedef int   ptrdiff_t;

#endif

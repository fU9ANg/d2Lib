

#ifndef _D2_ERRNO_H
#define _D2_ERRNO_H
/*
#ifndef _YVALS
#include <yvals.h>
#endif
*/
/** FIXME: need update macro of errno from standard c library **/
#define EDOM    _EDOM
#define ERANGE  _ERANGE
#define EFPOS   _EFPOS
/* add yours here */
#define _NERR   _ERRMAX


#define _EDOM   33
#define _ERANGE 34
#define _EFPOS  35
#define _ERRMAX 36

extern int errno;

#endif

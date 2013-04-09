
/*
 *  Written 2010 by fU9ANg
 *  bb.newlife@gmail.com
 */

#ifndef _D2_COMMON_H_INCLUDED
#define _D2_COMMON_H_INCLUDED

// standard c library header
#include <assert.h>
#include <float.h>
#include <math.h>
#include <stdarg.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include <setjmp.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include <locale.h>
#include <signal.h>
#include <stdio.h>
#include <time.h>


typedef     char            byte1;
typedef     short           byte2;
typedef     int             byte4;
typedef     long            bytel;

typedef     unsigned char   ubyte1;
typedef     unsigned short  ubyte2;
typedef     unsigned int    ubyte4;
typedef     unsigned long   ubytel;

typedef enum {
    d2_true = 1,
    d2_false= 0

}   d2_bool;

#endif  // _D2_COMMON_H_INCLUDED


#ifndef _D2_LIMITS_H
#define _D2_LIMITS_H


/* char properties */
#define CHAR_BIT    8
#if _CSIGN
#define CHAR_MAX    127
#define CHAR_MIN    (-127)
#else
#define CHAR_MAX    255
#define CHAR_MIN    0
#endif

/* int properties */
#if _ILONG
#define INT_MAX     2147483647
#define INT_MIN     (-2147483647)
#define UINT_MAX    4294967295
#else
#define INT_MAX     32767
#define INT_MIN     (-32767)
#define UINT_MAX    65536
#endif

/* long properties */
#define LONG_MAX    2147483647
#define LONG_MIN    (-2147483647)

/* multibyte properties */
#define MB_LEN_MAX  16

/* signed char properties */
#define SCHAR_MAX   127
#define SCHAR_MIN   (-127)

/* short properties */
#define SHRT_MAX    32767
#define SHRT_MIN    (-32767)

/* unsigned properties */
#define UCHAR_MAX   255
#define ULONG_MAX   4294967295
#define USHRT_MAX   65535

#endif


/*
 *  Written 2010 by fU9ANg
 *  bb.newlife@gmail.com
 */

#ifndef _D2_STRING_H_INCLUDED
#define _D2_STRING_H_INCLUDED


#include <d2_common.h>
#include <d2_ctype.h>

// common routine for string.
void    d2_strlow       (byte1 *s);
void    d2_strupp       (byte1 *s);
void    d2_reverse      (byte1 *s);
void    d2_nreverse     (byte1 *s, byte4 n);
byte4   d2_strlen       (const byte1 *s);
byte4   d2_strcasecmp   (const byte1 *s1, const byte1 *s2);
byte4   d2_strncmp      (const byte1 *s1, const byte1 *s2, byte4 n);
byte4   d2_strcmp       (const byte1 *s1, const byte1 *s2);
byte1*  d2_strncat      (byte1 *d, const byte1 *s, byte4 n);
byte1*  d2_strlcat      (byte1 *d, const byte1 *s);
byte1*  d2_strucat      (byte1 *d, const byte1 *s);
byte1*  d2_strcat       (byte1 *d, const byte1 *s);
byte1*  d2_strncpy      (byte1 *d, const byte1 *s, byte4 n);
byte1*  d2_strlcpy      (byte1 *d, const byte1 *s);
byte1*  d2_strucpy      (byte1 *d, const byte1 *s);
byte1*  d2_strcpy       (byte1 *d, const byte1 *s);
byte4   d2_strindex     (byte1 s[], byte1 t[]);
byte4   d2_strrindex    (byte1 s[], byte1 t[]);

// find a character in string `s'.
byte1*  d2_strxxxchr    (byte1 *s, byte1 c, byte4 i, byte4 n, byte4 d);
byte1*  d2_strchr       (byte1 *s, byte1 c);
byte1*  d2_strichr      (byte1 *s, byte1 c, byte4 i);
byte1*  d2_strnchr      (byte1 *s, byte1 c, byte4 n);
byte1*  d2_strinchr     (byte1 *s, byte1 c, byte4 i, byte4 n);
byte1*  d2_strchr_r     (byte1 *s, byte1 c);
byte1*  d2_strichr_r    (byte1 *s, byte1 c, byte4 i);
byte1*  d2_strnchr_r    (byte1 *s, byte1 c, byte4 n);
byte1*  d2_strinchr_r   (byte1 *s, byte1 c, byte4 i, byte4 n);

// find a string in string `s'.
byte1*  d2_strxxxstr    (byte1 *s1, byte1 *s2, byte4 i, byte4 n, byte4 d);
byte1*  d2_strstr       (byte1 *s1, byte1 *s2);
byte1*  d2_stristr      (byte1 *s1, byte1 *s2, byte4 i);
byte1*  d2_strnstr      (byte1 *s1, byte1 *s2, byte4 n);
byte1*  d2_strinstr     (byte1 *s1, byte1 *s2, byte4 i, byte4 n);
byte1*  d2_strstr_r     (byte1 *s1, byte1 *s2);
byte1*  d2_stristr_r    (byte1 *s1, byte1 *s2, byte4 i);
byte1*  d2_strnstr_r    (byte1 *s1, byte1 *s2, byte4 n);
byte1*  d2_strinstr_r   (byte1 *s1, byte1 *s2, byte4 i, byte4 n);

#define d2_memcpy(dst, src, n)  \
        (void) memcopy (dst, src, n)
#define d2_memzero(buf, n)      \
        (void) memset (buf, 0x00, n)
#define d2_memset(buf, c, n)    \
        (void) memset (buf, c, n)

#define D2_SET_STRING(string, text) \
        (string).len = sizeof text - 1; \
        (string).str = (ubyte1 *) text
        
#define D2_STRING(string) {     \
        (ubyte1 *) string,   \
        sizeof  string - 1      \
        }

#define D2_NULL_STRING    {     \
        0, NULL                 \
        }
 
#define D2_MEMZERO(buff, n) \
        (void) memset (buff, 0x00, n)

#define D2_MEMSET(buff, c, n) \
        (void) memset (buff, c, n)

typedef struct d2_string_s
{
    ubyte1   *str;
    ubyte4    len;
}   d2_string_t;

#endif	/* _D2_STRING_H_INCLUDED */

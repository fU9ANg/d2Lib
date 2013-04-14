/*
 *  VI: set ts=4; set expandtab; retab  
 *
 *  An implementation routines of encode and decode
 *  for base64
 *
 *  Written 2010 by <H. F. G. fU9ANg>
 *  E-mail: 59 6d 49 75  62 6d 56 33\  H
 *          62 47 6c 6d  5a 55 42 6e\  E
 *          62 57 46 70  62 43 35 6a\  X
 *          62 32 30 3d  [BASE-64   :-)]
 */


#define     NIL -1 /* invalid base64 character */
#define     DEBASE64(c) (isascii((unsigned char)(c)) ? tblBase64[c] : NIL)


/* definition static character table of base64 */
static const char chrBase64[] =
   "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/" ;


/* definition static the base64 map table */
static const char tblBase64[] =
{   /* OCT */
    
    NIL,NIL,NIL,NIL, NIL,NIL,NIL,NIL, NIL,NIL,NIL,NIL, NIL,NIL,NIL,NIL,
    NIL,NIL,NIL,NIL, NIL,NIL,NIL,NIL, NIL,NIL,NIL,NIL, NIL,NIL,NIL,NIL,
    NIL,NIL,NIL,NIL, NIL,NIL,NIL,NIL, NIL,NIL,NIL,076, NIL,NIL,NIL,077,
    064,065,066,067, 070,071,072,073, 074,075,NIL,NIL, NIL,NIL,NIL,NIL,
    NIL,000,001,002, 003,004,005,006, 007,010,011,012, 013,014,015,016,
    017,020,021,022, 023,024,025,026, 027,030,031,NIL, NIL,NIL,NIL,NIL,
    NIL,032,033,034, 035,036,037,040, 041,042,043,044, 045,046,047,050,
    051,052,053,054, 055,056,057,060, 061,062,063,NIL, NIL,NIL,NIL,NIL
};


#include    "d2_base64.h"
/*
 * =====================
 * FuncName   : enBase64
 * Parameters :
 *      out  => pointer for return
 *      in   => pointer for string of ascii
 * Return     : length of base64
 *
 * Description: encode base64 (from char of ascii to base64)
 *
 * Implementation:
 *      +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 *      | 00AAAAAA | 00BBBBBB | 00CCCCCC | 00DDDDDD |   // character of base64
 *      +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 *                            ^
 *                            | conversion
 *                            |
 *      +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 *      |   AAAAAABB   |   BBBBCCCC   |   CCDDDDDD  |   // character of ascii
 *      +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 * =====================
 */
int enBase64(unsigned char* out, const char* in)
{
    unsigned int len = strlen(in);

    for(; len >= 3; len -= 3)
    {
        *out++ = chrBase64[in[0] >> 2];
        *out++ = chrBase64[((in[0] << 4) & 0x30) | (in[1] >> 4)];
        *out++ = chrBase64[((in[1] << 2) & 0x3c) | (in[2] >> 6)];
        *out++ = chrBase64[in[2] & 0x3f];
        in += 3;
    }

    /* fill good string of base64 */
    if(len > 0)
    {
        unsigned char offset;

        *out++ = chrBase64[in[0] >> 2];
        offset = (in[0] << 4) & 060;
        if(len > 1)
            offset |= in[1] >> 4;
        *out++ = chrBase64[offset];
        *out++ = (len > 1) ? chrBase64[((in[1] << 2) & 074)] : '=';
        *out++ = '=';
    }
    *out = 000;

    return(len);
}

/*
 * =====================
 * FuncName   : deBase64
 * Parameters :
 *      out  => pointer for return
 *      in   => pointer for string of base64
 * Return     : length of ascii
 *
 * Description: decode base64 (from char of base64 to ascii)
 *
 * Implementation:
 *      +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 *      | 00AAAAAA | 00BBBBBB | 00CCCCCC | 00DDDDDD |   // character of base64
 *      +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 *                            |
 *                            | conversion
 *                            V
 *      +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 *      |   AAAAAABB   |   BBBBCCCC   |   CCDDDDDD  |   // character of ascii
 *      +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 * =====================
 */
int deBase64(unsigned char* out, const char* in)
{
    unsigned int len = 0;
    register unsigned char d1, d2, d3, d4;

    while(*in && *in != '=')
    {
        d1 = in[0];
        if(DEBASE64(d1) == NIL) return(-1);

        d2 = in[1];
        if(DEBASE64(d2) == NIL) return(-1);

        d3 = in[2];
        if(d3 != '=' && DEBASE64(d3) == NIL) return(-1);

        d4 = in[3];
        if(d4 != '=' && DEBASE64(d4) == NIL) return(-1);

        in += 4;
        *out++ = (DEBASE64(d1) << 2) | (DEBASE64(d2) >> 4);
        len++;
        if(d3 != '=')
        {
            *out++ = ((DEBASE64(d2) << 4) & 0xf0) | (DEBASE64(d3) >> 2);
            len++;
            if(d4 != '=')
            {
                *out++ = ((DEBASE64(d3) << 6) & 0xc0) | DEBASE64(d4);
                len++;
            }
        }
    }
    *out = 000;
    return(len);
}
/* end of encode and decode for base64 */


#ifdef  _BASE_STANDALONE
/*
 * for debugger
 *
 * like this on shell:
 * $ cc -o base64 base64.c -g -D _BASE_STANDALONE
 * $ ./base64
 */
#include    <stdio.h>
#include    <fcntl.h>
#include    <sys/mman.h>
#include    <sys/stat.h>

int main(int argc, char** argv)
{
    unsigned char out[64];

    enBase64(out, "bb.newlife@gmail.com");
    printf("ENBASE64 =\"%s\"\n", out);
    deBase64(out, "c2Fp bGlu Z190 ZXN0 MDJA ZGVt by5j b210 eHSy 4srU");
    printf("DEBASE64 =\"%s\"\n", out);

    return(0);
}

#endif  /* _BASE_STANDALONE */

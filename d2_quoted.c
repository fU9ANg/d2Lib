/*
 *  VI: set ts=4; set expandtab; retab  
 *
 *  An interface routines of encode and decode
 *  for quoted-printable.
 *
 *  Written 2010 by <H. F. G. fU9ANg>
 */

#include    "d2_quoted.h"

/* definition a quoted-printable map table */
static unsigned char tblHex[] = "0123456789ABCDEF";

/* E N C O D E */
char enQuoted(unsigned char* out, const char* in)
{
    unsigned short icnt = 0;

    while(*in)
    {
        if(((*in >= 33) && (*in <= 126)) && (*in != 61))
            out[icnt++] = *in;
        else
        {
            out[icnt++] = '=';
            out[icnt++] = tblHex[(unsigned char)*in >> 4];
            out[icnt++] = tblHex[(unsigned char)*in & 0x0f];
        }
        in++;
    }
    out[icnt] = 000;

    return(0);
}

static unsigned char unHex(unsigned char c)
{
    if((c >= '0') && (c <= '9'))
        return(c - '0');
    else if((c >= 'a') && (c <= 'f'))
        return(c - 'a' + 10);
    else if((c >= 'A') && (c <= 'F'))
        return(c - 'A' + 10);
    else

        return(16); /* invalid hex character */

}

/* D E C O D E */
char deQuoted(char* out, const unsigned char* in)
{
    unsigned char  c1, c2;
    unsigned short icnt = 0;

    while(*in)
    {
        if(*in == '=')
        {
            c1 = unHex(*++in);
            c2 = unHex(*++in);
            if((c1 < 15) && (c2 < 15))  /* check invalid hex character */
            out[icnt++] = c1 * 16 + c2;
        }
        else
            out[icnt++] = *in++;
    }
    out[icnt] = 000;

    return(0);
}


#ifdef  _QP_STANDALONE
/*
 * for debugger
 *
 * like this on shell:
 * $ cc -o quoted quoted.c -g -D _QP_STANDALONE -D _EN_QUOTED
 * $ ./quoted
 */

#include    <stdio.h>
main()
{
    getchar();
    char out[2048];

    #ifdef  _EN_QUOTED
        char strq[] = "miKeÂó¿ËmiKer,miKing";
        enQuoted(out, strq);
    #endif

    #ifdef  _DE_QUOTED
        char strq[] = "miKe=C2=F3=BF=CBmiKer,miKing";
        deQuoted(out, strq);
    #endif

    printf("%s\n", out);
}

#endif /* _QP_STANDALONE */

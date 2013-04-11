#include <d2_ctype.h>
#include <d2_common.h>

/*
 * Author: fU9ANg
 * Date  : 04/24/2011
 * Desc  : convert a datatype to an othertype.
 */


/*
 * Call  : char s[]="hello"; d2_atoa (s) => "olleh"
 * Desc  : reverse string
 */
void d2_atoa (unsigned char *s)
{
    int getlen (unsigned char *s) {
        int n = 0;
        void len () {
            if (*s++ && ++n)
                len();
        }
        len();
        return (n);
    }

    void reverse_ (unsigned char *p1, unsigned char *p2) {
        unsigned char c;
        void _reverse () {
            if (p1 < p2) {
                c = *p1;
                *p1++ = *p2;
                *p2-- = c;
                _reverse();
            }
        }
        _reverse();
    }

    reverse_ (s, (s + getlen (s) - 1));
}

/*
 * Call  : d2_atoi ("-12345") => -12345
 * Desc  : convert string s to integer
 */
int d2_atoi (unsigned char *s)
{
    int n = 0, f = 0;

    if (!s) return (0);
    if (*s++ == '-') f = 1;
        
    void a2i (unsigned char *s) {
        n = n * 10 + (*s - '0');
        if (* (s + 1))
            a2i (++s);
    }
    a2i (s);

    return (f ? -n : n);
}

/*
 * Call  : d2_itoa (-12345, s) => "-12345"
 * Desc  : convert integer i to string s
 */
void d2_itoa (int i, unsigned char *s)
{
#define SIGN(i, s)  \
    if (i < 0) {    \
        i = -i;     \
        *s++ = '-'; \
    }
    SIGN(i, s);

    void i2a (unsigned int i) {
        if (i / 10) {
            i2a (i / 10);
            *s = i % 10 + '0';
        } else
            *s = i % 10 + '0';
        s++;
    }

    i2a (i);
    *s = '\0';
}

/*
 * Call  : d2_itoi (314159) => 951413
 * Desc  : reverse integer
 */
int d2_itoi (int i)
{
    int n = 0, f = 0;
    if (i < 0) f = 1;
    if (i ==0) return (0);

    void i2i (int i) {
        n = n * 10 + (i % 10);
        if (i / 10)
            i2i (i / 10);
    }

    i2i (i);
    return (n);
}

/*
 * Desc  : convert string s to double
 */
double d2_atof (char s[])
{
    double val, power;
    int i, sign, num, flag;

    for (i = 0; d2_isspace(s[i]); i++) /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; d2_isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; d2_isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
#if 1
    if ((s[i] == 'e') || (s[i] == 'E')) {
        i++;
    }
    if ((s[i] == '-') || (s[i] == '+')) {
        i++;
        if (s[i] == '-')
            flag = -1;
        else
            flag = 1;
    } else
        flag = 1;
        
    for (num = 0; d2_isdigit(s[i]); i++)
        num = num * 10 + (s[i] - '0');
    
    num *= flag;
    while (num < 0) {
        power *= 10;
        num++;
    }

    while (num > 0) {
        val *= 10;
        num--;
    }
#endif

/*
 * Desc  : convert string s to decimal integer.
 * Call  : "87AF" -> 8*16^3 + 7*16^2 + 10*16 + 15 = 34735
 */
byte4 d2_htoi (byte1 *shex, byte4 n)
{
    byte4   v;
    byte1   c;

    for (v=0; n--; shex++) {
        c = *shex;
        if (!c)
            // return (error);
            ;
        if (c >= '0' && c <= '9') {
            v = v * 16 + (c - '0');
            continue;
        }
        c |= 0x20;

        if (c >= 'a' && c <= 'f') {
            v = v * 16 + (c - 'a' + 10);
            continue;
        }

        // TODO: return (error);
    }

    if (v < 0)
        // TODO: return (error);
        ;
    else
        return (v);
}

byte1* d2_str2hex (byte1 *dst, byte1 *src, byte4 n)
{
    static byte1 hextbl[] = "0123456789ABDEF";

    for (; n--; src++) {
        *dst++ = hextbl[*src >> 4];
        *dst++ = hextbl[*src & 0xf];
    }

    return (dst);
}

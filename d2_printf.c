#include <d2_common.h>


#define ALIGN_SIZE(n)           \
        ((sizeof (n) + sizeof (int)-1) & ~(sizeof (int)-1))
#define d2_va_start(ap, v)      \
        (ap = (char *) &v + ALIGN_SIZE (v))
#define d2_va_end(ap)           \
        (ap = (char *) 0)
#define d2_va_arg(ap, t)        \
        (*(t *)((ap += ALIGN_SIZE (t)) - ALIGN_SIZE (t)))


void d2_putc (int fd, char c)
{
    write (fd, &c, 1);
}

void d2_puts (int fd, char *s)
{
    void _puts () {
        if (*s) {
            d2_putc (fd, *s++);
            _puts ();
        }
    }

    _puts ();
}

void d2_putd (int fd, int d)
{
    if (d < 0) {
        d2_putc (fd, '-');
        d = -d;
    }

    if (d/10) {
        d2_putd (fd, d/10);
        d2_putc (fd, d%10 + '0');
    }
    else
        d2_putc (fd, d + '0');
}

void d2_putx (int fd, int x)
{
    char chars[] = "0123456789ABCDEF";

    if (x/16) {
        d2_putx (fd, x/16);
        d2_putc (fd, chars[x%16]);
    }
    else
        d2_putc (fd, chars[x]);
}
#ifdef  _TEST
int d2_printf (const char *fmt, ...)
{
    int     idx = 0, type = 0;
    char c;
    unsigned int *argp = (unsigned int *)(void *)(&fmt + 1);

    while (fmt[idx]) {
        c = fmt[idx++];
        if (c == '%' && !type) {
            type = 1;
            continue;
        }

        if (type == 1) {
            switch (c)
            {
                case 'd':
                    d2_putd (1, *argp++);
                    break;
                case 'x':
                    d2_putx (1, *argp++);
                    break;
                case 'c':
                    d2_putc (1, *argp++);
                    break;
                case 's':
                    d2_puts (1, (char *)*argp++);
                    break;
                case '%':
                    d2_putc (1, '%');
                    break;
                default:
                    return;
            }
            type = 0;
        }
        else
            d2_putc (1, c);
    }
}
#endif


/*
d2_vprintf
d2_printf

d2_vfprintf
d2_fprintf

d2_vsprintf
d2_sprintf

d2_vsnprintf
d2_snprintf
*/
// for STDOUT
byte4 d2_vprintf (const byte1 *fmt, va_list ap)
{
    vprintf (fmt, ap);
}
byte4 d2_printf (const byte1 *fmt, ...)
{
    char * ap;
    d2_va_start (ap, fmt);
    d2_vprintf (fmt, ap);
    va_end (ap);
#if 0
    va_list ap;
    va_start (ap, fmt);
    d2_vprintf (fmt, ap);
    va_end (ap);
#endif
}

// for FILE*
byte4 d2_vfprintf (FILE *stream, const byte1 *fmt, va_list ap)
{
    vfprintf (stream, fmt, ap);
}
byte4 d2_fprintf (FILE *stream, const byte1 *fmt, ...)
{
    va_list ap;
    va_start (ap, fmt);
    d2_vfprintf (stream, fmt, ap);
    va_end (ap);
}

// for CHAR*
byte4 d2_vsprintf (byte1 *str, const byte1 *fmt, va_list ap)
{
    return (vsprintf (str, fmt, ap));
}
byte4 d2_sprintf (byte1 *str, const byte1 *fmt, ...)
{
    va_list ap;
    va_start (ap, fmt);
    d2_vsprintf (str, fmt, ap);
    va_end (ap);
}

// for CHAR* and size
byte4 d2_vsnprintf (byte1 *str, size_t n, const byte1 *fmt, va_list ap)
{
    return (vsnprintf (str, n, fmt, ap));
}
byte4 d2_snprintf (byte1 *str, size_t n, const byte1 *fmt, ...)
{
    va_list ap;

    va_start (ap, fmt);
    d2_vsnprintf (str, n, fmt, ap);
    va_end (ap);
}

// d2_printf ("%x, %c, %s, %d, %f, %t", 16, 'F', "fuck!", 123, 3.12, 123);
// TEST...
#ifdef  _USE_STDARG_H
void d2_printf (char *fmt, ...)
{
    va_list     ap;
    int         p;
    int         i;

    va_start (ap, fmt);
    while (*fmt) {
        if (*fmt=='%' && *(fmt+1)=='d')
            printf ("integer: %d - ", va_arg (ap, int));

        else if (*fmt=='%' && *(fmt+1)=='f')
            printf ("double: %f - ", va_arg (ap, double));

        else if (*fmt=='%' && *(fmt+1)=='c')
            printf ("character: %c - ", (char)va_arg (ap, int));

        else if (*fmt=='%' && *(fmt+1)=='s')
            printf ("string: %s - ", va_arg (ap, char *));

        else if (*fmt=='%' && *(fmt+1)=='x')
            printf ("hex: 0x%x - ", va_arg (ap, int));

        else if (*fmt=='%' && *(fmt+1)=='t') {
            printf ("binary: ");
            if ((p = (int)va_arg (ap, int))) {
                printf ("%d...", p);
                for (; p; p<<=1)
                        putchar (p&0x80000000 ? '1': '0');
            }
        }

        fmt++;
    }
    va_end (ap);

    putchar ('\n');
}
#endif  // _USE_STDARG_H

#ifdef  _PRINT_STANDALONE
int main (int argc, char ** argv)
{
    d2_printf ("%s, %d, %c, %x\n", "abc", 1001, 'F', 0x1024);
}
#endif


#ifdef  _D2_LIBC
#include "d2assert.h"
#include "d2stdarg.h"
#include <stdio.h>
#else
#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#endif

/* type definitions */
typedef struct {
    char c;
}   Cstruct;

static int tryit (const char* fmt, ...)
{
    int ctr = 0;
    va_list  ap;

    va_start (ap, fmt);
    for (; *fmt; ++fmt)
    {
        switch (*fmt)
        {
        case 'i':
            assert (va_arg (ap, int) == ++ctr);
            break;
        case 'd':
            assert (va_arg (ap, double) == ++ctr);
            break;
        case 'p':
            assert (va_arg (ap, char *)[0] == ++ctr);
            break;
        case 's':
            assert (va_arg (ap, Cstruct).c == ++ctr);
        }
    }
    va_end (ap);
    return (ctr);
}

int main (void)
{
    Cstruct x = {3};

    assert (tryit ("iisdi", '\1', 2, x, 4.0, 5) == 5);
    assert (tryit ("") == 0);
    assert (tryit ("pdp", "\1", 2.0, "\3") == 3);
    printf ("sizeof (va_list) = %u\n", sizeof (va_list));
    puts ("SUCCESS testing <stdarg.h>");

    return (0);
}


#ifdef  _D2_LIBC
#include "d2assert.h"
#include "d2errno.h"
//#include "d2math.h"
//#include "d2stdio.h"
#include <math.h>
#include <stdio.h>
#else
#include <assert.h>
#include <errno.h>
#include <math.h>
#include <stdio.h>
#endif

int main ()
{
    assert (errno == 0);
    perror ("No error reported as: ");

    errno = ERANGE;
    assert (errno == ERANGE);
    perror ("Range error reported as: ");

    errno = 0;
    assert (errno == 0);
    sqrt (-1.0);
    assert (errno == EDOM);
    perror ("Domain error reported as: ");
    puts ("SUCCESS testing <errno.h>");

    return (0);
}

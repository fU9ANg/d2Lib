
#define NDEBUG
#ifdef  _D2_LIBC
#include "d2assert.h"
#else
#include <assert.h>
#endif

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

static int val = 0;

static void field_abort (int sig)
{
    if (val == 1)
    {
        puts ("SUCCESS testing <assert.h>");
        exit (EXIT_SUCCESS);
    }
    else
    {
        puts ("FAILURE testing <assert.h>");
        exit (EXIT_FAILURE);
    }
}

static void dummy ()
{
    int i = 0;
    assert (i == 0);
    assert (i == 1);
}

#undef NDEBUG
#ifdef  _D2_LIBC
#include "d2assert.h"
#else
#include <assert.h>
#endif

int main (void)
{
    assert (signal (SIGABRT, &field_abort) != SIG_ERR);
    dummy ();
    assert (val == 0);
    ++val;
    fputs ("Sample assertion failure message -- \n", stderr);
    assert (val == 0);
    puts ("main(): FAILURE testing <assert.h>");

    return (EXIT_FAILURE);
}


#include "d2signal.h"
#include <stdio.h>
#include <stdlib.h>

_Sigfunc* _Sigtable[_NSIG] = {0};

_Sigfunc* (signal) (int sig, _Sigfunc* func)
{
    _Sigfunc* s;

    if (sig <= 0 || _NSIG <= sig || func == SIG_ERR)
        return (SIG_ERR);

    s = _Sigtable[sig];
    _Sigtable[sig] = func;

    return (s);
}

int (raise) (int sig)
{
    _Sigfunc* s;

    if (sig <= 0 || _NSIG <= sig)
        return (-1);

    if ((s = _Sigtable[sig]) != SIG_IGN && s != SIG_DFL)
    {
        _Sigtable[sig] = SIG_DFL;
        (*s) (sig);
    }
    else if (s == SIG_DFL)
    {
        char ac[10], *p;

        switch (sig)
        {
        case SIGABRT:
            p = "abort";
            break;
        case SIGFPE:
            p = "arithmetic error";
            break;
        case SIGILL:
            p = "invalid executable code";
            break;
        case SIGINT:
            p = "interruption";
            break;
        case SIGSEGV:
            p = "invalid storage access";
            break;
        case SIGTERM:
            p = "termination request";
            break;
        default:
            *(p = &ac[(sizeof ac) -1]) = '\0';
            do *--p = sig % 10 + '0';
            while ((sig /= 10) != 0);
            fputs ("signal #", stderr);
        }

        fputs (p, stderr);
        fputs (" -- terminating\n", stderr);
        exit (EXIT_FAILURE);
    }
    return (0);
}

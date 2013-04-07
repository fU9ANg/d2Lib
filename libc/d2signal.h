
#ifndef _D2_SIGNAL_H
#define _D2_SIGNAL_H

#define _SIGABRT    6
#define _SIGMAX     32

/* type definitions */
typedef int     sig_atomic_t;
typedef void    _Sigfunc (int);

/* signal codes */
#define SIGABRT _SIGABRT
#define SIGINT  2
#define SIGILL  4
#define SIGFPE  8
#define SIGSEGV 11
#define SIGTERM 15
#define _NSIG   _SIGMAX

/* signal return values */
#define SIG_DFL (_Sigfunc *)0
#define SIG_ERR (_Sigfunc *)-1
#define SIG_IGN (_Sigfunc *)1

/* declarations */
int raise (int);
_Sigfunc* signal (int, _Sigfunc *);

#endif


#ifndef _D2_STDARG_H
#define _D2_STDARG_H

typedef char*   va_list;

#define ALIGN_SIZE(n) \
        ((sizeof (n) + sizeof (int) -1) & ~(sizeof (int) -1))
#define va_start(ap, v) \
        (void) ((ap) = (char *) &(v) + ALIGN_SIZE (v))
#define va_end(ap) \
        (void) ((ap) = (char *) 0)
#define va_arg(ap, T) \
        (*(T *) ((ap += ALIGN_SIZE (T)) - ALIGN_SIZE (T)))

#endif

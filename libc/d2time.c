


char *      asctime (const struct tm *);
clock_t     clock (void);
char *      ctime (const time_t *);
double      difftime (time_t, time_t);
struct tm * gmtime (const time_t *);
struct tm * localtime (const time_t *);
time_t      mktime (struct tm *);
size_t      strftime (char *, size_t, const char *, \
                      const struct tm *);
time_t      time (time_t *);

//
time_t time (time_t * tod)
{
    time_t t = _Time (NULL) + (70 * 365LU + 17) * 86400;
    if (tod)
        *tod = t;
    return (t);
}

clock_t clock (void)
{
    return ((clock_t) time (NULL));
}

double difftime (time_t t1, time_t t0)
{
    t0 -= _TBIAS, t1 -= _TBIAS;
    return (t0 <= t1 ? (double) (t1-t0) : \
                      -(double) (t0-t1));
}

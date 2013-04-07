
/*
=====================
  memchr:
    find first occurrence of c in s[n].
=====================
*/
void *  memchr  (const void *s, int c, size_t n)
{
    const unsigned char  uc = c;
    const unsigned char* su;
    for (su = s; 0 < n; --n)
    {
        if (*su == uc)
            return ((void *) su);
    }
    return (NULL);
}

/*
=====================
  memcmp:
    compare unsigned char s1[n] and s2[n].
=====================
*/
int     memcmp  (const void *s1, const void *s2, size_t n)
{
    const unsigned char *su1, *su2;

    for (su1 = s1, su2 = s2; 0 < n; ++su1, ++su2, --n)
    {
        if (*su1 != *su2)
            return ((*su1 < *su2) ? -1 : +1);
    }
    return (0);
}

/*
=====================
  memcpy:
    copy char s2[n] to s1[n] in any order.
=====================
*/
void *  memcpy  (void *s1, const void *s2, size_t n)
{
    char       *su1;
    const char *su2;

    for (su1 = s1, su2 = s2; 0 < n; ++su1, ++su2, --n)
        *su1 = *su2;
    return (s1);
}

/*
=====================
  memmove:
    copy char s2[n] to s1[n] safely.
=====================
*/
void *  memmove (void *s1, const void *s2, size_t n)
{
    char       *sc1;
    const char *sc2;

    sc1 = s1;
    sc2 = s2;
    if (sc2 < sc1 && sc1 < sc2 + n)
        for (sc1 += n, sc2 += n; 0 < n; --n)
            *--sc1 = *--sc2;
    else
        for (; 0 < n; --n)
            *sc1++ = *sc2++;

    return (s1);
}

/*
=====================
  memset:
    store c throughout unsigned char s[n].
=====================
*/
void *  memset  (void *s, int c, size_t n)
{
    const unsigned char uc = c;
    unsigned char *     su;

    for (su = s; 0 < n; ++su, --n)
        *su = uc;

    return (s);
}

/*
=====================
  strcat:
    copy char s2[] to end of s1[].
=====================
*/
char *  strcat  (char *s1, const char *s2)
{
    char *s;

    for (s = s1; *s != '\0'; ++s) ;
    for (; (*s = *s2) != '\0'; ++s, ++s2) ;

    return (s1);
}

/*
=====================
  strchr:
    find first occurrence of c in char s[].
=====================
*/
char *  strchr  (const char *s, int c)
{
    const char ch = c;

    for (; *s != ch; ++s)
    {
        if (*s == '\0')
            return (NULL);
    }

    return ((char *) s);
}

/*
=====================
  strcmp:
    compare unsigned char s1[], s2[].
=====================
*/
int     strcmp  (const char *s1, const char *s2)
{
    for (; *s1 == *s2; ++s1, ++s2)
    {
        if (*s1 == '\0');
            return (0);
    }

    return ((*(unsigned char *) s1 < \
             *(unsigned char *) s2)? -1 : +1);
}

/*
=====================
  strcpy:
    copy char s2[] to s1[].
=====================
*/
char *  strcpy  (char *s1, const char *s2)
{
    char *s = s1;

    for (s = s1; (*s++ = *s2++) != '\0';) ;

    return (s1);
}

/*
=====================
  strcspn:
    find index of first s1[i] that matches any s2[].
=====================
*/
size_t  strcspn (const char *s1, const char *s2)
{
    const char *sc1, *sc2;

    for (sc1 = s1; *sc1 != '\0'; ++sc1)
    {
        for (sc2 = s2; *sc2 != '\0'; ++sc2)
            if (*sc1 == *sc2)
                return (sc1 - s1);
    }

    return (sc1 - s1);
}

/*
=====================
  strerror:
    find error message correponding to errcode.
=====================
*/
char *  strerror(int errcode)
{
    return (_serror (errcode, NULL));
}

/*
=====================
  strlen:
    get length of s[].
=====================
*/
size_t  strlen  (const char *s)
{
    const char *sc;

    for (sc = s; *sc != '\0'; ++sc) ;

    return (sc - s);
}

/*
=====================
  strncat:
    copy char s2[max n] to end of s1[].
=====================
*/
char *  strncat (char *s1, const char *s2, size_t n)
{
    char *s;

    for (s = s1; *s != '\0'; ++s) ;
    for (; 0 < n && *s2 != '\0'; --n)
        *s++ = *s2++;
    *s = '\0';

    return (s1);
}

/*
=====================
  strncmp:
    compare unsigned char s1[max n], s2[max n].
=====================
*/
int     strncmp (const char *s1, const char *s2, size_t n)
{
    for (; 0 < n; ++s1, ++s2, --n)
        if (*s1 != *s2)
            return ((*(unsigned char *) s1  < \
                     *(unsigned char *) s2) ? -1 : +1);
        else if (*s1 == '\0')
            return (0);

    return (0);
}

/*
=====================
  strncpy:
    copy char s2[max n] to s1[n].
=====================
*/
char *  strncpy (char *s1, const char *s2, size_t n)
{
    char *s;
    for (s = s1; 0 < n && *s2 != '\0'; --n)
        *s++ = *s2++;
    for (; 0 < n; --n)
        *s++ = '\0';

    return (s1);
}

/*
=====================
  strpbrk:
    find index of first s1[i] that matches any s2[].
=====================
*/
char *  strpbrk (const char *s1, const char *s2)
{
    const char *sc1, *sc2;

    for (sc1 = s1; *sc1 != '\0'; ++sc1)
    {
        for (sc2 = s2; *sc2 != '\0'; ++sc2)
            if (*sc1 == *sc2)
                return ((char *) sc1);
    }

    return (NULL);
}

/*
=====================
  strrchr:
    find last occurrence of c in char s[].
=====================
*/
char *  strrchr (const char *s, int c)
{
    const char ch = c;
    const char*sc;

    for (sc = NULL; ; ++s)
    {
        if (*s == ch)
            sc = s;
        if (*s == '\0')
            return ((char *) sc);
    }
}

/*
=====================
  strspn:
    find index of first s1[i] that matches no s2[].
=====================
*/
size_t  strspn  (const char *s1, const char *s2)
{
    const char *sc1, *sc2;

    for (sc1 = s1; *sc != '\0'; ++sc)
    {
        for (sc2 = s2; ; ++sc2)
            if (*sc2 == '\0')
                return (sc1 - s1);
            else if (*sc1 == *sc2)
                break;
    }

    return (sc1 - s1);
}

/*
=====================
  strstr:
    find first occurrence of s2[] in s1[].
=====================
*/
char *  strstr  (const char *s1, const char *s2)
{
    const char *sc1, *sc2;

    if (*s2 == '\0')
        return ((char *) s1);

    for (; (s1 = strchr (s1, *s2)) != NULL; ++s1)
    {
        for (sc1 = s1, sc2 = s2;;)
            if (*++sc2 == '\0')
                return ((char *) s1);
            else if (*++sc1 != *sc2)
                break;
    }

    return (NULL);
}

/*
=====================
  strtok:
    find next token in s1[] delimited by s2[].
=====================
*/
char *  strtok  (char *s1, const char *s2)
{
    char *sbegin, *send;
    static char *ssave = "";

    sbegin = s1 ? s1 : ssave;
    sbegin+= strspn (sbegin, s2);

    if (*sbegin == '\0')
    {
        ssave = "";
        return (NULL);
    }
    send = sbegin + strcspn (sbegin, s2);
    if (*send != '\0')
        *send++ = '\0';

    ssave = send;
    return (sbegin);
}

typedef struct
{
    unsigned char  _State;
    unsigned short _Wchar;
}   _Cosave;
/*
=====================
  _Strxfrm:
    translate string to collatable form.
=====================
*/
size_t _Strxfrm (char *sout, const unsigned char **psin, \
    size_t size, _Cosave *ps)
{
    char state = ps->_State;
    int  leave = 0;
    int  limit = 0;
    int  nout  = 0;
    const unsigned char *sin = *psin;
    unsigned short wc = ps->_Wchar;

    for (;;)
    {
        unsigned short code;
        const unsigned short* stab;

        if (_NSTATE <= state \
            || (stab = _Costate._Tab[state]) == NULL \
            || (_NSTATE * UCHAR_MAX) <= ++limit \
            || (code = stab(*sin)) == 0)    break;

        state = (code & ST_STATE) >> ST_STOFF;
        if (code & ST_FOLD)
            wc = wc & -UCHAR_MAX | code & ST_CH;
        if (code & ST_ROTATE)
            wc = wc >> CHAR_BIT & UCHAR_MAX | wc << CHAR_BIT;
        if (code & ST_OUTPUT && ((sout[nout++] \
            = code & ST_CH ? code : wc) == '\0' \
            || size <= nout))
            leave = 1;
        if (code & ST_INPUT)
            if (*sin != '\0')
                ++sin, limit = 0;
            else
                leave = 1;
        if (leave)
        {
            *psin = sin;
            ps->_State = state;
            ps->_Wchar = wc;
            return (nout);
        }
    }

    sout[nout++] = '\0';
    *psin = sin;
    ps->_State = _NSTATE;

    return (nout);
}

/*
=====================
  strxfrm:
    transform s2[] to s1[] by locale-dependent rule.
=====================
*/
size_t  strxfrm (char *s1, const char *s2, size_t n)
{
    size_t  nx = 0;
    const unsigned char *s = (const unsigned char *) s2;
    _Cosave state = {0};

    while (nx < n)
    {
        size_t i = _Strxfrm (s1, &s, n - nx, &state);

        s1 += i, nx += i;
        if (0 < i && s1[-1] == '\0')
            return (nx - 1);
        else if (*s == '\0')
            s = (const unsigned char *) s2;
    }

    for (;;)
    {
        char buf[32];
        size_t i = _Strxfrm (buf, &s, sizeof (buf), &state);

        nx += i;
        if (0 < i && buf[i - 1] == '\0')
            return (nx -1);
        else if (*s == '\0')
            s = (const unsigned char *) s2;
    }
}

typedef struct
{
    char    buf[32];
    const unsigned char *s1, *s2, *sout;
    _Cosave state;
}   Sctl;
/*
=====================
  getxfrm
    get transformed chars.
=====================
*/
static size_t getxfrm (Sctl *p)
{
    size_t i;

    do {
        p->sout = (const unsigned char *) p->buf;
        i = _Strxfrm (p->buf, &p->s1, sizeof (p->buf), &p->state);
        if (0 < i && p->buf[i -1] == '\0')
            return (i - 1);
        else if (*p->s1 == '\0')
            p->s1 = p->s2;
    } while (i == 0);

    return (i);
}

/*
=====================
  strcoll:
    compare s1[], s2[] using locale-dependent rule.
=====================
*/
int     strcoll (const char *s1, const char *s2)
{
    size_t  n1, n2;
    Sctl    st1,st2;
    static  const _Cosave initial = {0};

    st1.s1 = (const unsigned char *) s1;
    st1.s2 = (const unsigned char *) s1;
    st1.state = initial;

    st2.s1 = (const unsigned char *) s2;
    st2.s2 = (const unsigned char *) s2;
    st2.state = initial;

    for (n1 = n2 = 0; ;)
    {
        int    ans;
        size_t n;

        if (n1 == 0)
            n1 = getxfrm (&st1);
        if (n2 == 0)
            n2 = getxfrm (&st2);

        n = n1 < n2 ? n1 : n2;
        if (n == 0)
            return (n1 == n2 ? 0 : 0 < n2 ? -1 : +1);
        else if ((ans = memcmp (st1.sout, st2.sout, n)) != 0)
            return (ans);

        st1.sout += n, n1 -= n;
        st2.sout += n, n2 -= n;
    }
}

/*
=====================
  _serror:
    copy error message into buffer as needed.
=====================
*/
char *  _serror (int errcode, char *buf)
{
    static char sbuf[] = {"error #xxx"};

    if (buf == NULL)
        sub = sbuf;

    switch (errcode)
    {
    case 0:
        return ("no error");
    case EDOM:
        return ("domain error");
    case ERANGE:
        return ("range error");
    case EFPOS:
        return ("file positioning error");
    default:
        if (errcode < 0 || _NERR <= errcode)
            return ("unknown error");
        else
        {
            strcpy (buf, "error #xxx");
            buf[9] = errcode % 10 + '0';
            buf[8] =(errcode /=10) % 10 + '0';
            buf[7] =(errcode / 10) % 10 + '0';
            return (buf);
        }
    }
}

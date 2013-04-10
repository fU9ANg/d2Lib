# if 0
main()
{
    char dest[64] = "abcDEFHGGGGG";
    //printf ("%s\n", strncpy_ (dest, "DEFGHI097826djkcnhsyr", 10));
    //printf ("%s\n", strcpy_ (dest, "DEFGHI"));
    //printf ("%s\n", strncat_ (dest, "12345abcdefghijklmn", 10));
    //printf ("%s\n", strcat_ (dest, "678900000"));
    /*
    if ((i = strncmp_ ("abcd!", "abcD", 4)) == 0)
        printf("%dEQ_1\n", i);
    if ((i = strcmp_ ("abcd!", "abcD")) == 0)
        printf("%dEQ_1\n", i);
    if ((i = strcasecmp_ ("AbcefABC", "abceFabc")) == 0)
        printf("%dEQ_2\n", i);
    if ((i = strcasecmp_ ("abcde", "abcdE")) == 0)
        printf("%dEQ_3.\n", i);
    i=strlen_("abcdefgh\n");
        printf("%d", i);
        */
}
#endif
#include <d2_common.h>
#include <d2_string.h>
#include <d2_ctype.h>

byte4 d2_strrindex (byte1 s[], byte1 t[])
{
    int i, j, k, l;
    i = d2_strlen (s) - 1;
    l = d2_strlen (t) - 1;

    for (; i != -1; i--) {
        for (j=i,k=l; ((k!=-1)&&(s[j]==t[k])); j--,k--) ;
        if (k == -1)
            return (j + 2);
    }

    return (-1);
}


byte1* d2_strncpy (byte1 *d, const byte1 *s, byte4 n)
{
#ifdef D2_ITERATION

    char *t = d;
    //d += d2_strlen (d);
    while (*s && (n-- > 0))
        *d++ = *s++;
    *d = '\0';

    return (t);

#elif  D2_TAILRECUR

    char *t = d;
    //d += d2_strlen (d);
    void cpynstr () {
        if (*s && (n-- > 0)) {
            *d++ = *s++;
            cpynstr();
        } else
            *d = '\0';
    }
    cpynstr ();

    return (t);

#else  /* D2_RECURSION */

	if (*s && (n-- > 0)) {
		*d = *s;
		d2_strncpy (d+1, s+1, n);
	} else
		*d = '\0';
	return (d);

#endif
}


byte4 d2_strncmp (const byte1 *s1, const byte1 *s2, byte4 n)
{
#ifdef D2_ITERATION

    int d = 0;
    while (*s1 == *s2++) {
        if (*s1++ == '\0') return (0);
        if (++d == n) return (0);
    }

    return (*s1 - *--s2);

#elif  D2_TAILRECUR

    int i = 0, d = 0;

    void cmpnstr () {
        if (*s1 == *s2++) {
            if (*s1++ == '\0') i = 0;
            else if (++d == n) i = 0;
            else
                cmpnstr ();
        } else
            i = *s1 - *--s2;
    }
    cmpnstr();

    return (i);

#else  /* D2_RECURSION */

    if (*s1 == *s2++) {
        if (*s1++ == '\0')
            return (0);
        else if (--n == 0)
            return (0);
        else
            return (d2_strncmp (s1, s2, n));
    } else
        return (*s1 - *--s2);

#endif

}


byte1* d2_strncat (byte1 *d, const byte1 *s, byte4 n)
{
#ifdef D2_ITERATION

    char *t = d;
    d += d2_strlen (d);
    while (*s && (n-- > 0))
        *d++ = *s++;
    *d = '\0';

    return (t);

#elif  D2_TAILRECUR

    char *t = d;
    d += d2_strlen (d);
    void catnstr () {
        if (*s && (n-- > 0)) {
            *d++ = *s++;
            catnstr();
        } else
            *d = '\0';
    }

    catnstr ();
    return (t);

#else  /* D2_RECURSION */

	if (*s && (n-- > 0)) {
		*(d + d2_strlen (d)) = *s;
		d2_strncat (d, s+1, n);
	} else
		*(d + d2_strlen (d)) = '\0';

	return (d);

#endif
}


byte4 d2_strlen (const byte1 *s)
{

#ifdef D2_ITERATION
    int n=0;
    while (*s++)
        n++;

    return (n);

#elif  D2_TAILRECUR
    int n=0;
    void getlen () {
        if (*s++) {
            n++;
            getlen ();
        }
    }
    getlen ();
    return (n);

#else  /* D2_RECURSION */
    if (*s)
        return (1 + d2_strlen (++s));
#endif

}


byte4 d2_strindex (byte1 s[], byte1 t[])
{
    int i, j, k;

    for (i=0; s[i]!='\0'; i++) {

        for (j=i,k=0; t[k]!='\0'&&s[j]==t[k]; k++,j++);

        if (k>0 && t[k]=='\0')
            return (i);
    }

    return (-1);
}


byte1* d2_strlcpy (byte1 *d, const byte1 *s)
{
    byte1 *t = d;
    while (*s)
        *d++ = d2_tolower (*s++);
    *d = '\0';

    return (t);
}


byte1* d2_strucpy (byte1 *d, const byte1 *s)
{
    byte1 *t = d;
    while (*s)
        *d++ = d2_toupper (*s++);
    *d = '\0';

    return (t);
}


byte1* d2_strcpy (byte1 *d, const byte1 *s)
{
#ifdef D2_ITERATION
    byte1 *t = d;
    while (*s)
        *d++ = *s++;
    *d = '\0';

    return (t);

#elif  D2_TAILRECUR
    char *t = d;
    void copystr() {
        if (*s) {
            *d++ = *s++;
            copystr();
        } else
            *d='\0';
    }
    copystr();

    return (t);
#else  /* D2_RECURSION */
	if (*s) {
		*d = *s;
		d2_strcpy (d+1, s+1);
	} else
		*d = '\0';

	return (d);
#endif
}


byte4 d2_strcmp (const byte1 *s1, const byte1 *s2)
{
#ifdef D2_ITERATION
    while (*s1 == *s2++)
        if (*s1++ == '\0')
            return (0);

    return (*s1 - *--s2);

#elif  D2_TAILRECUR
    int i = 0;

    void cmpstr () {
        if (*s1 == *s2++) {
            if (*s1++ == '\0') i = 0;
            else
                cmpstr ();
        } else
            i = *s1 - *--s2;
    }
    cmpstr();

    return (i);

#else  /* D2_RECURSION */
    if (*s1 == *s2++) {

        if (*s1++ == '\0')
            return (0);
        else
            return (d2_strcmp (s1, s2));
    } else
        return (*s1 - *--s2);

#endif

}


byte1* d2_strlcat (byte1 *d, const byte1 *s)
{
    byte1 *t = d;
    d += d2_strlen (d);
    while (*s)
        *d = d2_tolower (*s++);
    *d = '\0';

    return (t);
}


byte1* d2_strucat (byte1 *d, const byte1 *s)
{
    byte1 *t = d;
    d += d2_strlen (d);
    while (*s)
        *d = d2_toupper (*s++);
    *d = '\0';

    return (t);
}


byte1* d2_strcat (byte1 *d, const byte1 *s)
{
#ifdef D2_ITERATION

    char *t = d;
    d += d2_strlen (d);
    while (*s)
        *d++ = *s++;
    *d = '\0';

    return (t);

#elif  D2_TAILRECUR

    char *t = d;
    d += d2_strlen (d);
    void catstr () {
        if (*s) {
            *d++ = *s++;
            catstr();
        } else
            *d = '\0';
    }
    catstr();

    return (t);

#else  /* D2_RECURSION */
	
	if (*s) {
		*(d + d2_strlen (d)) = *s;
		d2_strcat (d, s+1);
	} else
		*(d + d2_strlen (d)) = '\0';

	return (d);
	
#endif
}


byte4 d2_strcasecmp (const byte1 *s1, const byte1 *s2)
{
    while (*s1) {
        if (*s1 == *s2) goto cont;
        else {
            if (d2_isalpha (*s1) && d2_isalpha (*s2)) {
                if (d2_islower (*s1)) {
                    if (*s1 - 32 == *s2) goto cont;
                }
                else if (d2_isupper (*s1)) {
                    if (*s1 + 32 == *s2) goto cont;
                }
                else
                    return (*s1 - *s2);
            } else
                return (*s1 - *s2);
        }
cont:
        s1++; s2++;
    }

    if (*s2)
        return (*s1 - *s2);
    else
        return (0);
}

// new
void d2_strupp (byte1 *s)
{
    while (*s) {
        *s = d2_toupper (*s);
        s++;
    }
}

void d2_strlow (byte1 *s)
{
    while (*s) {
        *s = d2_tolower (*s);
        s++;
    }
}

void d2_nreverse (byte1 *s, byte4 n)
{
    byte1   *p1, *p2, tmp;

    for (p1=s, p2=s+d2_strlen(s)-1; p1<p2 && n; p1++,p2--,n--) {
        tmp = *p1;
        *p1 = *p2;
        *p2 = tmp;
    }
}

void d2_reverse (byte1 *s)
{
    d2_nreverse (s, d2_strlen (s));
}

// strchr
byte1* d2_strxxxchr (byte1 *s, byte1 c, byte4 i, byte4 n, byte4 d)
{
    byte4   inc = 0;
    byte1*  ps  = s;
    byte1*  ptr = NULL;

    s = d ? s+d2_strlen (s) : s;
    do {
        if (*s == c) {
            inc++;
            ptr = s;
        }

        if (inc == i)
            return (ptr);

        if (d ? (s==ps) : (*s==0)) goto nil;
        s = d ? s-1 : s+1;

    } while (n--);

nil:
    return (NULL);
}

byte1* d2_strchr (byte1 *s, byte1 c)
{
    return (d2_strxxxchr (s, c, 1, d2_strlen (s), 0));
}

byte1* d2_strichr (byte1 *s, byte1 c, byte4 i)
{
    return (d2_strxxxchr (s, c, i, d2_strlen (s), 0));
}

byte1* d2_strnchr (byte1 *s, byte1 c, byte4 n)
{
    return (d2_strxxxchr (s, c, 1, n, 0));
}

byte1* d2_strinchr (byte1 *s, byte1 c, byte4 i, byte4 n)
{
    return (d2_strxxxchr (s, c, i, n, 0));
}
//
//
byte1* d2_strchr_r (byte1 *s, byte1 c)
{
    return (d2_strxxxchr (s, c, 1, d2_strlen (s), 1));
}

byte1* d2_strichr_r (byte1 *s, byte1 c, byte4 i)
{
    return (d2_strxxxchr (s, c, i, d2_strlen (s), 1));
}

byte1* d2_strnchr_r (byte1 *s, byte1 c, byte4 n)
{
    return (d2_strxxxchr (s, c, 1, n, 1));
}

byte1* d2_strinchr_r (byte1 *s, byte1 c, byte4 i, byte4 n)
{
    return (d2_strxxxchr (s, c, i, n, 1));
}

#ifdef  _TEST_STRCHR_MAIN
main () {
             /*012345678901234567890123456789*/
    char s[]= "RaBDFEgsaRlslsdfdrRadcRafdadrER";
    char s2[]= "abcd";
    char c  = 'R';
    char*ps = NULL;
    printf ("%s\n", (ps=d2_strxxxchr (s, c, 1, d2_strlen (s), 1)) ? ps : ("null"));
    printf ("%s\n", (ps=d2_strxxxchr (s, c, 2, d2_strlen (s), 1)) ? ps : ("null"));
    printf ("%s\n", (ps=d2_strxxxchr (s, c, 3, d2_strlen (s), 1)) ? ps : ("null"));
    printf ("%s\n", (ps=d2_strxxxchr (s, c, 4, d2_strlen (s), 1)) ? ps : ("null"));
    printf ("%s\n", (ps=d2_strxxxchr (s, c, 5, d2_strlen (s), 1)) ? ps : ("null"));
    printf ("\n\n");
    printf ("%s\n", (ps=d2_strxxxchr (s, c, 1, d2_strlen (s), 0)) ? ps : ("null"));
    printf ("%s\n", (ps=d2_strxxxchr (s, c, 2, d2_strlen (s), 0)) ? ps : ("null"));
    printf ("%s\n", (ps=d2_strxxxchr (s, c, 3, d2_strlen (s), 0)) ? ps : ("null"));
    printf ("%s\n", (ps=d2_strxxxchr (s, c, 4, d2_strlen (s), 0)) ? ps : ("null"));
    printf ("%s\n", (ps=d2_strxxxchr (s, c, 5, d2_strlen (s), 0)) ? ps : ("null"));
    printf ("\n\n\n");
    printf ("%s\n", (ps=d2_strxxxchr (s, c, 1, 10, 1)) ? ps : ("null"));
    printf ("%s\n", (ps=d2_strxxxchr (s, c, 2, 10, 1)) ? ps : ("null"));
    printf ("%s\n", (ps=d2_strxxxchr (s, c, 3, 10, 1)) ? ps : ("null"));
    printf ("%s\n", (ps=d2_strxxxchr (s, c, 4, 10, 1)) ? ps : ("null"));
    printf ("%s\n", (ps=d2_strxxxchr (s, c, 5, 10, 1)) ? ps : ("null"));
    printf ("\n\n");
    printf ("%s\n", (ps=d2_strxxxchr (s, c, 1, 10, 0)) ? ps : ("null"));
    printf ("%s\n", (ps=d2_strxxxchr (s, c, 2, 10, 0)) ? ps : ("null"));
    printf ("%s\n", (ps=d2_strxxxchr (s, c, 3, 10, 0)) ? ps : ("null"));
    printf ("%s\n", (ps=d2_strxxxchr (s, c, 4, 10, 0)) ? ps : ("null"));
    printf ("%s\n", (ps=d2_strxxxchr (s, c, 5, 10, 0)) ? ps : ("null"));
}
#endif  // _TEST_STRCHR_MAIN

// strstr
byte1* d2_strxxxstr (byte1 *s1, byte1 *s2, byte4 i, byte4 n, byte4 d)
{
    int             ii, jj, kk;
    int             inc = 0;
    int             ns1 = n;
    int             ns2 = strlen (s2)-1;
    byte1*          ps1 = s1;
    byte1*          ps2 = s2;

    ii = d?strlen(s1):0;

    while (ns1--) {

        for (jj=ii,kk=d?ns2:0;(d?(&s2[kk]!=ps2):(s2[kk]))&&s1[jj]==s2[kk];d?kk--:kk++,d?jj--:jj++);
            if (d?(kk==0):(kk>0)&&d?(&s2[kk]==ps2):(!s2[kk]))
                inc++;

        if (inc == i)
            return (&s1[d?jj:ii]);

        if (d?&s1[ii]==ps1:!s1[ii])
            return (NULL);

        d?ii--:ii++;
    }

    return (NULL);
    #if 0
    while (ns1--) {

        for (jj=ii,kk=0; s2[kk]!='\0'&&s1[jj]==s2[kk]; kk++,jj++);

        if (kk>0 && s2[kk]=='\0')
            inc++;

        if (inc == i)
            return (&s1[ii]);

        if (!s1[ii])
            return (NULL);

        ii++;
    }

    return (NULL);
    #endif
}


byte1*  d2_strstr (byte1 *s1, byte1 *s2)
{
    return (d2_strxxxstr (s1, s2, 1, strlen (s1), 0));
}


byte1*  d2_stristr (byte1 *s1, byte1 *s2, byte4 i)
{
    return (d2_strxxxstr (s1, s2, i, strlen (s1), 0));
}


byte1*  d2_strnstr (byte1 *s1, byte1 *s2, byte4 n)
{
    return (d2_strxxxstr (s1, s2, 1, n, 0));
}


byte1*  d2_strinstr (byte1 *s1, byte1 *s2, byte4 i, byte4 n)
{
    return (d2_strxxxstr (s1, s2, i, n, 0));
}


byte1*  d2_strstr_r (byte1 *s1, byte1 *s2)
{
    return (d2_strxxxstr (s1, s2, 1, strlen (s1), 1));
}


byte1*  d2_stristr_r (byte1 *s1, byte1 *s2, byte4 i)
{
    return (d2_strxxxstr (s1, s2, i, strlen (s1), 1));
}


byte1*  d2_strnstr_r (byte1 *s1, byte1 *s2, byte4 n)
{
    return (d2_strxxxstr (s1, s2, 1, n, 1));
}


byte1*  d2_strinstr_r (byte1 *s1, byte1 *s2, byte4 i, byte4 n)
{
    return (d2_strxxxstr (s1, s2, i, n, 1));
}

#ifdef  _TEST_STRSTR_MAIN
main () {
    char s1[] = "#lwskdfja#lwsmmwoxmra;nznr#lwj3la#lwacmar#lw";
    char s2[] = "#lw";
    char *p = NULL;

    printf ("%s\n", ((p=d2_strxxxstr(s1, s2, 1, strlen (s1), 1)) ? p : "nuLL"));
    printf ("%s\n", ((p=d2_strxxxstr(s1, s2, 2, strlen (s1), 1)) ? p : "nuLL"));
    printf ("%s\n", ((p=d2_strxxxstr(s1, s2, 3, strlen (s1), 1)) ? p : "nuLL"));
    printf ("%s\n", ((p=d2_strxxxstr(s1, s2, 4, strlen (s1), 1)) ? p : "nuLL"));
    printf ("%s\n", ((p=d2_strxxxstr(s1, s2, 5, strlen (s1), 1)) ? p : "nuLL"));
    printf ("%s\n", ((p=d2_strxxxstr(s1, s2, 6, strlen (s1), 1)) ? p : "nuLL"));
    printf ("\n\n\n");
    printf ("%s\n", ((p=d2_strxxxstr(s1, s2, 1, strlen (s1), 0)) ? p : "nuLL"));
    printf ("%s\n", ((p=d2_strxxxstr(s1, s2, 2, strlen (s1), 0)) ? p : "nuLL"));
    printf ("%s\n", ((p=d2_strxxxstr(s1, s2, 3, strlen (s1), 0)) ? p : "nuLL"));
    printf ("%s\n", ((p=d2_strxxxstr(s1, s2, 4, strlen (s1), 0)) ? p : "nuLL"));
    printf ("%s\n", ((p=d2_strxxxstr(s1, s2, 5, strlen (s1), 0)) ? p : "nuLL"));
    printf ("%s\n", ((p=d2_strxxxstr(s1, s2, 6, strlen (s1), 0)) ? p : "nuLL"));
}
#endif  // _TEST_STRSTR_MAIN

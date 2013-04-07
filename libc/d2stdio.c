
#include <stdlib.h>
#include "d2stdio.h"

void    clearerr (FILE *)
{
}

int     fclose (FILE *);
int     feof (FILE *);
int     ferror (FILE *);
int     fflush (FILE *);
int     fgetc  (FILE *);
int     fgetpos (FILE *, fpos_t *);
char *  fgets (char *, int, FILE *);
FILE *  fopen (const char *name, const char *mods)
{
    FILE *  str;
    size_t  i;

    for (i = 0; i < FOPEN_MAX; ++i)
    {
        if (_Files[i] == NULL)
        {
            str = malloc (sizeof (FILE));
            if (str == NULL)
                return (NULL);
            _Files[i] = str;
            str->_Mode = _MALFIL;
            break;
        }
        else if (_Files[i]->_Mode == 0)
        {
            str = _Files[i];
            break;
        }
    }

    if (FOPEN_MAX <= i)
        return (NULL);

    return (_Foprep (name, mods, str));
}

int     fprintf (FILE *, const char *, ...);
int     fputs (const char *, FILE *);
size_t  fread (void *, size_t, size_t, FILE *);
FILE *  freopen (const char *, const char *, FILE *);
int     fscanf (FILE *, const char *, ...);

int     fseek (FILE *, long, int);
int     fsetpos (FILE *, const fpos_t *);
long    ftell (FILE *);
size_t  fwrite (const void *, size_t, size_t, FILE *);
int     getc (FILE *);
int     getchar (void);
char *  gets (char *);
void    perror (const char *);
int     printf (const char *, ...);
int     putc (int, FILE *);
int     putchar (int);
int     puts (const char *);
int     remove (const char *);
int     rename (const char *, const char *);
void    rewind (FILE *);
int     scanf (const char *, ...);
void    setbuf (FILE *, char *);
int     setvbuf (FILE *, char *, int, size_t);
int     sprintf (char *, const char *, ...);
int     sscanf (const char *, const char *, ...);
FILE *  tmpfile (void);
char *  tmpnam (char *);
int     ungetc (int, FILE *);
int     vfprintf (FILE *, const char *, char *);
int     vprintf (const char *, char *);
int     vsprintf (char *, const char *, char *);
long    _Fgpos (FILE *, fpos_t *);
int     _Fspos (FILE *, const fpos_t *, long, int);

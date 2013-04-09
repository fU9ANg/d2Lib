/*
 *  VI: set ts=4; set expandtab; retab  
 *
 *  An implementation routines for pattern matching in
 *  use
 *   ________
 *  | |    \ \
 *  | |     ) )
 *  | |    / /
 *  | |    \ \           _  _
 *  | |     ) )         | \/ |
 *  |_|____/_/  byer -  |_||_| oore algorithms.
 *
 *  Written 2010 by <H. F. G. fU9ANg>
 */


#ifdef  _BM_STANDALONE
#include    <stdio.h>
#include    <stdlib.h>
#endif /* _BM_STANDALONE */

#include    <string.h>

static void getJump(unsigned char* patt, int *tbl)
{
    int i, length = strlen(patt);

    for (i = 1; i < 256; i++)       /* fill common value for tbl */
        tbl[i] = length;

    for (i = 0; i < length -1; i++) /* fill special value of tbl */
        tbl[(int) patt[i]] = length -i -1;
}

/*
 * =====================
 * FuncName   : bmMatch
 * Parameters :
 *      txt  => main string
 *      patt => sub string
 * Return     :
 *      -1   => not found
 *      len  => pattern found at location
 *
 * Description: pattern matching in strings use Boyer-Moore method.
 *
 * Example:
 *      +---------------------------------------------+
 *      | PatternMatchingInStringsUseBoyerMooreMethod | // main string
 *      +---------------------------------------------+
 *      +------------+
 *      | BoyerMoore |                                  // sub  string
 *      +------------+
 *
 * Implementation:
 *      +------------+
 *      | BoyerMoore |
 *      +------------+
 *            || (compare)
 *      +------------+------------+------------+---------+--------+
 *      | PatternMat | chingInStr | ingsUseBoy | erMoore | Method |
 *      +------------+------------+------------+---------+--------+
 *      |<- step 1 ->|
 *                   |<- step 2 ->|
 *                                |<- step 3 ->|
 *                                        |<-  step 4  ->|     // found
 *
 * =====================
 */
int bmMatch(unsigned char* txt, unsigned char* patt)
{
    int tbl[256];
    int len1 = strlen(txt);
    int len2 = strlen(patt);
    int i, j, k;

    getJump(patt, tbl);  /* set the jump table */

    for (i = len2-1; i < len1;)
    {
        for (j =len2-1,k=i; j>=0 && txt[k]==patt[j]; k--,j--) ;
        if  (j < 0)     /* found */
            return(k+1);
        else
            i += tbl[txt[i]];
    }

    return(-1);
}

#ifdef  _BM_STANDALONE
/*
 * for debugger
 *
 * like this on shell:
 * $ cc -o bm bm.c -g _D _BM_STANDALONE
 * $ ./bm
 */
int main(int argc, char** agrv)
{
    unsigned char txt[] = "PatternMatchingInStringsUseBoyerMooreMethod";
    unsigned char pat[] = "BoyerMoore";
    int ret;

    if ((ret = bmMatch(txt, pat)) >= 0)
        printf("pattern found at location %d.\n", ret);
    else
        printf("pattern NOT FOUND.\n");

    if ((ret = bmMatch(txt + 28, pat)) >= 0)
        printf("pattern found at location %d.\n", ret);
    else
        printf("pattern NOT FOUND.\n");

    return 0;
}

#endif /* _BM_STANDALONE */

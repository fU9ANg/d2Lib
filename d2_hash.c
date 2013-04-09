#include <d2_hash.h>
#include <d2_common.h>


/*
=====================
based of 'Arash Partow' hash function.
=====================
*/
ubytel ap_hash (ubytel magic, const ubyte1 *str, ubyte4 len)
{
    ubytel  i = 0, h = 0xAAAAAAAA;
    for (i=0; i<len; str++, i++) {
        h ^= ((i&1) == 0) ? ((h << 7) ^ (*str) * (h >> 3)) \
                          : (~((h << 11) + ((*str) ^ (h >> 5))));
    }

    return (magic + h);
}


/*
=====================
based of 'BP' hash function
=====================
*/
ubytel bp_hash (ubytel magic, const ubyte1 *str, ubyte4 len)
{
    ubytel  h = 0, i = 0;

    for (i=0; i<len; str++, i++)
        h = h << 7 ^ (*str);

    return (magic + h);
}


/*
=====================
based of 'Justin Sobel' hash function.
=====================
*/
ubytel js_hash (ubytel magic, const ubyte1 *str, ubyte4 len)
{
    ubytel  i = 0, h = 1315423911;
    for (i=0; i<len; i++, str++)
        h ^= ((h<< 5) + (*str) + (h >> 2));

    return (magic + h);
}


/*
=====================
based of 'Robert Sedgwicks' hash function.
=====================
*/
ubytel rs_hash (ubytel magic, const ubyte1 *str, ubyte4 len)
{
    ubytel  b = 378551;
    ubytel  a = 63689;
    ubytel  h = 0, i = 0;

    for (i=0; i<len; str++, i++) {
        h = h * a + (*str);
        a*= b;
    }

    return (magic + h);
}


/*
=====================
based of 'Donald E. Knuth' hash function.
=====================
*/
ubytel dek_hash (ubytel magic, const ubyte1 *str, ubyte4 len)
{
    ubytel  h = len, i = 0;

    for (i=0; i<len; str++, i++)
        h = ((h << 5) ^ (h >> 27)) ^ (*str);

    return (magic + h);
}


/*
=====================
based of 'Daniel J. Bernstein' hash function.
=====================
*/
ubytel djb_hash (ubytel magic, const ubyte1 *str, ubyte4 len)
{
    ubytel  h = 5381, i = 0;

    for (i=0; i<len; str++, i++)
        h = ((h << 5) + h) + (*str);

    return (magic + h);
}


/*
=====================
based of 'Extended Library Function On Unix' hash function.
=====================
*/
ubytel elf_hash (ubytel magic, const ubyte1 *str, ubyte4 len)
{
    ubytel  h = 0, x = 0, i = 0;

    for (i=0; i<len; str++, i++) {
        h = (h << 4) + (*str);
        if ((x = h & 0xF0000000L) != 0)
            h ^= (x >> 24);
        h &= ~x;
    }

    return (magic + h);
}


/*
=====================
based of 'Unix system' hash function.
=====================
*/
ubytel fnv_hash (ubytel magic, const ubyte1 *str, ubyte4 len)
{
    const   ubytel fnv_prime = 0x811C9DC5;
    ubytel  h = 0, i = 0;

    for (i=0; i<len; str++, i++) {
        h *= fnv_prime;
        h ^= (*str);
    }

    return (magic + h);
}


/*
=====================
based of 'Peter J. Weinberger' hash function.
=====================
*/
ubytel pjw_hash (ubytel magic, const ubyte1 *str, ubyte4 len)
{
#define BITS32 0xffffffff
    const ubytel total_bits = (ubytel) (sizeof (ubytel) * 8);
    const ubytel three_quar = (ubytel) ((total_bits * 3) / 4);
    const ubytel one_eighth = (ubytel) (total_bits / 8);
    const ubytel high_bits  = (ubytel) (BITS32) << (total_bits - one_eighth);

    ubytel  h = 0, tst = 0, i = 0;

    for (i=0; i<len; str++, i++) {
        h = (h << one_eighth) + (*str);
        if ((tst = h & high_bits) != 0)
            h = ((h ^ (tst >> three_quar)) & (~high_bits));
    }
#undef  BIT32
    return (magic + h);
}


/*
=====================
based of 'Brian Kernighan & Dennis Ritchie' hash function.
=====================
*/
ubytel bkdr_hash (ubytel magic, const ubyte1 *str, ubyte4 len)
{
    ubytel  seed = 131;     // such as: 31 131 1313 13131 131313 etc.
    ubytel  h = 0, i = 0;

    for (i=0; i<len; str++, i++)
        h = (h * seed) + (*str);

    return (magic + h);
}


/*
=====================
based of 'SDBM Project' hash function.
=====================
*/
ubytel sdbm_hash (ubytel magic, const ubyte1 *str, ubyte4 len)
{
    ubytel  h = 0, i = 0;

    for (i=0; i<len; str++, i++)
        h = (*str) + (h << 6) + (h << 16) - h;

    return (magic + h);
}


//
//
//
// TEST
#ifdef  _HASH_FUNC_TEST

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char **argv)
{
    const ubyte1* key = "172.16.10.101-80 172.16.xxx.xxx-yyyy";

    printf ("[==== HASH FUNCTION ALGORITHMS TEST ====]\n");
    printf ("Key:\t%s\n", key);

    printf ("[AP]\tFunction Value: %u\n", ap_hash (0, key, strlen (key)));
    printf ("[BP]\tFunction Value: %u\n", bp_hash (0, key, strlen (key)));
    printf ("[JS]\tFunction Value: %u\n", js_hash (0, key, strlen (key)));
    printf ("[RS]\tFunction Value: %u\n", rs_hash (0, key, strlen (key)));

    printf ("[DEK]\tFunction Value: %u\n", dek_hash (0, key, strlen (key)));
    printf ("[DJB]\tFunction Value: %u\n", djb_hash (0, key, strlen (key)));
    printf ("[ELF]\tFunction Value: %u\n", elf_hash (0, key, strlen (key)));
    printf ("[FNV]\tFunction Value: %u\n", fnv_hash (0, key, strlen (key)));
    printf ("[PJW]\tFunction Value: %u\n", pjw_hash (0, key, strlen (key)));

    printf ("[BKDR]\tFunction Value: %u\n", bkdr_hash (0, key, strlen (key)));
    printf ("[SDBM]\tFunction Value: %u\n", sdbm_hash (0, key, strlen (key)));

    exit (1);
}

#endif  // _HASH_FUNC_TEST

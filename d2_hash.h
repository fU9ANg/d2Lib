#ifndef _D2_HASH_H
#define _D2_HASH_H


#include <d2_common.h>

// callback function prototype
typedef ubytel (*hash_handle)   (ubytel magic, const ubyte1 *str, ubyte4 len);

// general purpose hash function algorithms
extern  ubytel  ap_hash         (ubytel magic, const ubyte1 *str, ubyte4 len);
extern  ubytel  bp_hash         (ubytel magic, const ubyte1 *str, ubyte4 len);
extern  ubytel  js_hash         (ubytel magic, const ubyte1 *str, ubyte4 len);
extern  ubytel  rs_hash         (ubytel magic, const ubyte1 *str, ubyte4 len);

extern  ubytel  dek_hash        (ubytel magic, const ubyte1 *str, ubyte4 len);
extern  ubytel  djb_hash        (ubytel magic, const ubyte1 *str, ubyte4 len);
extern  ubytel  elf_hash        (ubytel magic, const ubyte1 *str, ubyte4 len);
extern  ubytel  fnv_hash        (ubytel magic, const ubyte1 *str, ubyte4 len);
extern  ubytel  pjw_hash        (ubytel magic, const ubyte1 *str, ubyte4 len);

extern  ubytel  bkdr_hash       (ubytel magic, const ubyte1 *str, ubyte4 len);
extern  ubytel  sdbm_hash       (ubytel magic, const ubyte1 *str, ubyte4 len);


#endif  // _D2_HASH_H

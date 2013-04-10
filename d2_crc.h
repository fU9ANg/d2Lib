#ifndef _D2_CRC_H
#define _D2_CRC_H

#include <d2_common.h>

// CRC-8
void    d2_crc8_init        (ubyte1 *crc);
void    d2_crc8_update      (ubyte1 *crc, const void *data, int len);
void    d2_crc8_finish      (ubyte1 *crc);
ubyte1  d2_crc8_checksum    (const void *data, int len);

// CRC-16
void    d2_crc16_init       (ubyte2 *crc);
void    d2_crc16_update     (ubyte2 *crc, const void *data, int len);
void    d2_crc16_finish     (ubyte2 *crc);
ubyte1  d2_crc16_checksum   (const void *data, int len);

// CRC-32
void    d2_crc32_init       (ubytel *crc);
void    d2_crc32_update     (ubytel *crc, const void *data, int len);
void    d2_crc32_finish     (ubytel *crc);
ubyte1  d2_crc32_checksum   (const void *data, int len);


#endif  //_D2_CRC_H

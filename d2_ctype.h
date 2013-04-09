
/*
 *  Written 2010 by fU9ANg
 *  bb.newlife@gmail.com
 */

#ifndef _D2_CTYPE_H_INCLUDED
#ifndef _D2_CTYPE_H_INCLUDED


#define     LOW     0x01                    // lower
#define     UPP     0x02                    // upper
#define     DIG     0x04                    // digits
#define     XDI     0x08                    // hex digits
#define     SPA     0x10                    // space
#define     PUN     0x20                    // punctuation
#define     CNT     0x40                    // control

extern char ascii_tbl[];

//
// define macro for character operation
//
#define d2_isascii(c)  \
        ((char)c <= 0x7F)                   // ascii character

#define d2_islower(c)  \
        (ascii_tbl[c] & LOW)                // lower-case character

#define d2_isupper(c)  \
        (ascii_tbl[c] & UPP)                // upper-case character

#define d2_isalpha(c)  \
        (ascii_tbl[c] & (LOW|UPP))          // alphabetic character

#define d2_isalnum(c)  \
        (ascii_tbl[c] & (LOW|UPP|DIG))      // alphabetic character and number

#define d2_isprint(c)  \
        (ascii_tbl[c] & (LOW|UPP|DIG|PUN))  // printable character

#define d2_isdigit(c)  \
        (ascii_tbl[c] & DIG)                // digits character

#define d2_isspace(c)  \
        (ascii_tbl[c] & SPA)                // ' ','\t','\r','\n','\v','\f' char

#define d2_ispunct(c)  \
        (ascii_tbl[c] & PUN)                // punctuation symbol character

#define d2_iscntrl(c)  \
        (ascii_tbl[c] & CNT)                // control character in ascii

#define d2_isxdigit(c) \
        (ascii_tbl[c] & XDI)                // hexadecimal digits

#define d2_toascii(c)  \
        ((char)((c) & 0x7F))                // convert to ascii character

#define d2_tolower(c)  \
        ((c) + 0x20)                        // convert to lower character

#define d2_toupper(c)  \
        ((c) - 0x20)                        // convert to upper character


#endif  // _D2_CTYPE_H_INCLUDED

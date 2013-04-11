/*
 *  VI: set ts=4; set expandtab; retab  
 *
 *  An interface routines of encode and decode
 *  for quoted-printable.
 *
 *  Written 2010 by <H. F. G. fU9ANg>
 */


#ifndef _QUOTED_H
#define _QUOTED_H

char enQuoted(unsigned char* out, const char* in);
char deQuoted(char* out, const unsigned char* in);

#endif  /* _QUOTED_H */


/*
 *  Written 2010 by fU9ANg
 *  bb.newlife@gmail.com
 */

#include <d2_type.h>

/*
+num+alpha+upper+lower+digit+xdigit+space+punct+alnum+print+cntrl+ascii+char+
|000|     |     |     |     |      |     |     |     |     |  y  |  y  |NUL |
|001|     |     |     |     |      |     |     |     |     |  y  |  y  |SOH |
|002|     |     |     |     |      |     |     |     |     |  y  |  y  |STX |
|003|     |     |     |     |      |     |     |     |     |  y  |  y  |ETX |
|004|     |     |     |     |      |     |     |     |     |  y  |  y  |EOT |
|005|     |     |     |     |      |     |     |     |     |  y  |  y  |ENQ |
|006|     |     |     |     |      |     |     |     |     |  y  |  y  |ACK |
|007|     |     |     |     |      |     |     |     |     |  y  |  y  |\a  |
|008|     |     |     |     |      |     |     |     |     |  y  |  y  |\b  |
|009|     |     |     |     |      |  y  |     |     |     |     |  y  |\t  |
|010|     |     |     |     |      |  y  |     |     |     |     |  y  |\n  |
|011|     |     |     |     |      |  y  |     |     |     |     |  y  |\v  |
|012|     |     |     |     |      |  y  |     |     |     |     |  y  |\f  |
|013|     |     |     |     |      |  y  |     |     |     |     |  y  |\r  |
|014|     |     |     |     |      |     |     |     |     |  y  |  y  |SO  |
|015|     |     |     |     |      |     |     |     |     |  y  |  y  |SI  |
|016|     |     |     |     |      |     |     |     |     |  y  |  y  |DLE |
|017|     |     |     |     |      |     |     |     |     |  y  |  y  |DC1 |
|018|     |     |     |     |      |     |     |     |     |  y  |  y  |DC2 |
|019|     |     |     |     |      |     |     |     |     |  y  |  y  |DC3 |
|020|     |     |     |     |      |     |     |     |     |  y  |  y  |DC4 |
|021|     |     |     |     |      |     |     |     |     |  y  |  y  |NAK |
|022|     |     |     |     |      |     |     |     |     |  y  |  y  |SYN |
|023|     |     |     |     |      |     |     |     |     |  y  |  y  |ETB |
|024|     |     |     |     |      |     |     |     |     |  y  |  y  |CAN |
|025|     |     |     |     |      |     |     |     |     |  y  |  y  |EM  |
|026|     |     |     |     |      |     |     |     |     |  y  |  y  |SUB |
|027|     |     |     |     |      |     |     |     |     |  y  |  y  |ESC |
|028|     |     |     |     |      |     |     |     |     |  y  |  y  |FS  |
|029|     |     |     |     |      |     |     |     |     |  y  |  y  |GS  |
|030|     |     |     |     |      |     |     |     |     |  y  |  y  |RS  |
|031|     |     |     |     |      |     |     |     |     |  y  |  y  |US  |
|032|     |     |     |     |      |  y  |     |     |     |     |  y  |    |
|033|     |     |     |     |      |     |  y  |     |  y  |     |  y  |!   |
|034|     |     |     |     |      |     |  y  |     |  y  |     |  y  |"   |
|035|     |     |     |     |      |     |  y  |     |  y  |     |  y  |#   |
|036|     |     |     |     |      |     |  y  |     |  y  |     |  y  |$   |
|037|     |     |     |     |      |     |  y  |     |  y  |     |  y  |%   |
|038|     |     |     |     |      |     |  y  |     |  y  |     |  y  |&   |
|039|     |     |     |     |      |     |  y  |     |  y  |     |  y  |'   |
|040|     |     |     |     |      |     |  y  |     |  y  |     |  y  |(   |
|041|     |     |     |     |      |     |  y  |     |  y  |     |  y  |)   |
|042|     |     |     |     |      |     |  y  |     |  y  |     |  y  |*   |
|043|     |     |     |     |      |     |  y  |     |  y  |     |  y  |+   |
|044|     |     |     |     |      |     |  y  |     |  y  |     |  y  |,   |
|045|     |     |     |     |      |     |  y  |     |  y  |     |  y  |-   |
|046|     |     |     |     |      |     |  y  |     |  y  |     |  y  |.   |
|047|     |     |     |     |      |     |  y  |     |  y  |     |  y  |/   |
|048|     |     |     |  y  |  y   |     |     |  y  |  y  |     |  y  |0   |
|049|     |     |     |  y  |  y   |     |     |  y  |  y  |     |  y  |1   |
|050|     |     |     |  y  |  y   |     |     |  y  |  y  |     |  y  |2   |
|051|     |     |     |  y  |  y   |     |     |  y  |  y  |     |  y  |3   |
|052|     |     |     |  y  |  y   |     |     |  y  |  y  |     |  y  |4   |
|053|     |     |     |  y  |  y   |     |     |  y  |  y  |     |  y  |5   |
|054|     |     |     |  y  |  y   |     |     |  y  |  y  |     |  y  |6   |
|055|     |     |     |  y  |  y   |     |     |  y  |  y  |     |  y  |7   |
|056|     |     |     |  y  |  y   |     |     |  y  |  y  |     |  y  |8   |
|057|     |     |     |  y  |  y   |     |     |  y  |  y  |     |  y  |9   |
|058|     |     |     |     |      |     |  y  |     |  y  |     |  y  |:   |
|059|     |     |     |     |      |     |  y  |     |  y  |     |  y  |;   |
|060|     |     |     |     |      |     |  y  |     |  y  |     |  y  |<   |
|061|     |     |     |     |      |     |  y  |     |  y  |     |  y  |=   |
|062|     |     |     |     |      |     |  y  |     |  y  |     |  y  |>   |
|063|     |     |     |     |      |     |  y  |     |  y  |     |  y  |?   |
|064|     |     |     |     |      |     |  y  |     |  y  |     |  y  |@   |
|065|  y  |  y  |     |     |  y   |     |     |  y  |  y  |     |  y  |A   |
|066|  y  |  y  |     |     |  y   |     |     |  y  |  y  |     |  y  |B   |
|067|  y  |  y  |     |     |  y   |     |     |  y  |  y  |     |  y  |C   |
|068|  y  |  y  |     |     |  y   |     |     |  y  |  y  |     |  y  |D   |
|069|  y  |  y  |     |     |  y   |     |     |  y  |  y  |     |  y  |E   |
|070|  y  |  y  |     |     |  y   |     |     |  y  |  y  |     |  y  |F   |
|071|  y  |  y  |     |     |      |     |     |  y  |  y  |     |  y  |G   |
|072|  y  |  y  |     |     |      |     |     |  y  |  y  |     |  y  |H   |
|073|  y  |  y  |     |     |      |     |     |  y  |  y  |     |  y  |I   |
|074|  y  |  y  |     |     |      |     |     |  y  |  y  |     |  y  |J   |
|075|  y  |  y  |     |     |      |     |     |  y  |  y  |     |  y  |K   |
|076|  y  |  y  |     |     |      |     |     |  y  |  y  |     |  y  |L   |
|077|  y  |  y  |     |     |      |     |     |  y  |  y  |     |  y  |M   |
|078|  y  |  y  |     |     |      |     |     |  y  |  y  |     |  y  |N   |
|079|  y  |  y  |     |     |      |     |     |  y  |  y  |     |  y  |O   |
|080|  y  |  y  |     |     |      |     |     |  y  |  y  |     |  y  |P   |
|081|  y  |  y  |     |     |      |     |     |  y  |  y  |     |  y  |Q   |
|082|  y  |  y  |     |     |      |     |     |  y  |  y  |     |  y  |R   |
|083|  y  |  y  |     |     |      |     |     |  y  |  y  |     |  y  |S   |
|084|  y  |  y  |     |     |      |     |     |  y  |  y  |     |  y  |T   |
|085|  y  |  y  |     |     |      |     |     |  y  |  y  |     |  y  |U   |
|086|  y  |  y  |     |     |      |     |     |  y  |  y  |     |  y  |V   |
|087|  y  |  y  |     |     |      |     |     |  y  |  y  |     |  y  |W   |
|088|  y  |  y  |     |     |      |     |     |  y  |  y  |     |  y  |X   |
|089|  y  |  y  |     |     |      |     |     |  y  |  y  |     |  y  |Y   |
|090|  y  |  y  |     |     |      |     |     |  y  |  y  |     |  y  |Z   |
|091|     |     |     |     |      |     |  y  |     |  y  |     |  y  |[   |
|092|     |     |     |     |      |     |  y  |     |  y  |     |  y  |\   |
|093|     |     |     |     |      |     |  y  |     |  y  |     |  y  |]   |
|094|     |     |     |     |      |     |  y  |     |  y  |     |  y  |^   |
|095|     |     |     |     |      |     |  y  |     |  y  |     |  y  |_   |
|096|     |     |     |     |      |     |  y  |     |  y  |     |  y  |`   |
|097|  y  |     |  y  |     |  y   |     |     |  y  |  y  |     |  y  |a   |
|098|  y  |     |  y  |     |  y   |     |     |  y  |  y  |     |  y  |b   |
|099|  y  |     |  y  |     |  y   |     |     |  y  |  y  |     |  y  |c   |
|100|  y  |     |  y  |     |  y   |     |     |  y  |  y  |     |  y  |d   |
|101|  y  |     |  y  |     |  y   |     |     |  y  |  y  |     |  y  |e   |
|102|  y  |     |  y  |     |  y   |     |     |  y  |  y  |     |  y  |f   |
|103|  y  |     |  y  |     |      |     |     |  y  |  y  |     |  y  |g   |
|104|  y  |     |  y  |     |      |     |     |  y  |  y  |     |  y  |h   |
|105|  y  |     |  y  |     |      |     |     |  y  |  y  |     |  y  |i   |
|106|  y  |     |  y  |     |      |     |     |  y  |  y  |     |  y  |j   |
|107|  y  |     |  y  |     |      |     |     |  y  |  y  |     |  y  |k   |
|108|  y  |     |  y  |     |      |     |     |  y  |  y  |     |  y  |l   |
|109|  y  |     |  y  |     |      |     |     |  y  |  y  |     |  y  |m   |
|110|  y  |     |  y  |     |      |     |     |  y  |  y  |     |  y  |n   |
|111|  y  |     |  y  |     |      |     |     |  y  |  y  |     |  y  |o   |
|112|  y  |     |  y  |     |      |     |     |  y  |  y  |     |  y  |p   |
|113|  y  |     |  y  |     |      |     |     |  y  |  y  |     |  y  |q   |
|114|  y  |     |  y  |     |      |     |     |  y  |  y  |     |  y  |r   |
|115|  y  |     |  y  |     |      |     |     |  y  |  y  |     |  y  |s   |
|116|  y  |     |  y  |     |      |     |     |  y  |  y  |     |  y  |t   |
|117|  y  |     |  y  |     |      |     |     |  y  |  y  |     |  y  |u   |
|118|  y  |     |  y  |     |      |     |     |  y  |  y  |     |  y  |v   |
|119|  y  |     |  y  |     |      |     |     |  y  |  y  |     |  y  |w   |
|120|  y  |     |  y  |     |      |     |     |  y  |  y  |     |  y  |x   |
|121|  y  |     |  y  |     |      |     |     |  y  |  y  |     |  y  |y   |
|122|  y  |     |  y  |     |      |     |     |  y  |  y  |     |  y  |z   |
|123|     |     |     |     |      |     |  y  |     |  y  |     |  y  |{   |
|124|     |     |     |     |      |     |  y  |     |  y  |     |  y  ||   |
|125|     |     |     |     |      |     |  y  |     |  y  |     |  y  |}   |
|126|     |     |     |     |      |     |  y  |     |  y  |     |  y  |~   |
|127|     |     |     |     |      |     |     |     |     |  y  |  y  |DEL |
-----------------------------------------------------------------------------
*/

char ascii_tbl[] = {

/* 000~007 */ CNT,    CNT,    CNT,    CNT,    CNT,    CNT,    CNT,    CNT,
/* 008~015 */ CNT,    SPA,    SPA,    SPA,    SPA,    SPA,    CNT,    CNT,
/* 016~023 */ CNT,    CNT,    CNT,    CNT,    CNT,    CNT,    CNT,    CNT,
/* 024~031 */ CNT,    CNT,    CNT,    CNT,    CNT,    CNT,    CNT,    CNT,
/* 032~039 */ SPA,    PUN,    PUN,    PUN,    PUN,    PUN,    PUN,    PUN,
/* 040~047 */ PUN,    PUN,    PUN,    PUN,    PUN,    PUN,    PUN,    PUN,
/* 048~055 */ DIG|XDI,DIG|XDI,DIG|XDI,DIG|XDI,DIG|XDI,DIG|XDI,DIG|XDI,DIG|XDI,
/* 056~063 */ DIG|XDI,DIG|XDI,PUN,    PUN,    PUN,    PUN,    PUN,    PUN,
/* 064~071 */ PUN,    UPP|XDI,UPP|XDI,UPP|XDI,UPP|XDI,UPP|XDI,UPP|XDI,UPP,
/* 072~079 */ UPP,    UPP,    UPP,    UPP,    UPP,    UPP,    UPP,    UPP,
/* 080~087 */ UPP,    UPP,    UPP,    UPP,    UPP,    UPP,    UPP,    UPP,
/* 088~095 */ UPP,    UPP,    UPP,    PUN,    PUN,    PUN,    PUN,    PUN,
/* 096~103 */ PUN,    LOW|XDI,LOW|XDI,LOW|XDI,LOW|XDI,LOW|XDI,LOW|XDI,LOW,
/* 104~111 */ LOW,    LOW,    LOW,    LOW,    LOW,    LOW,    LOW,    LOW,
/* 112~119 */ LOW,    LOW,    LOW,    LOW,    LOW,    LOW,    LOW,    LOW,
/* 120~127 */ LOW,    LOW,    LOW,    PUN,    PUN,    PUN,    PUN,    CNT

};

/** TODO NOT FINISHED!!!
 * */

#ifndef __CTYPE_CP866_HPP__
#define __CTYPE_CP866_HPP__

#include <locale>

using namespace std;

/**@brief ctype facet for cp866 encoding*/
template<class Ch>
class ctype_cp866 : public ctype<Ch>
{
  public:
    typedef Ch char_type;
    typedef typename ctype<Ch>::mask mask;

    enum{
      space = ctype<Ch>::space,
      print = ctype<Ch>::print,
      cntrl = ctype<Ch>::cntrl,
      upper = ctype<Ch>::upper,
      lower = ctype<Ch>::lower,
      alpha = ctype<Ch>::alpha,
      digit = ctype<Ch>::digit,
      punct = ctype<Ch>::punct,
      xdigit= ctype<Ch>::xdigit,
      alnum = alpha | digit,
      graph = alnum | punct
    };

    explicit ctype_cp866(size_t r = 0)
    {
      masks[0]   = cntrl;
      masks[1]   = cntrl;
      masks[2]   = cntrl;
      masks[3]   = cntrl;
      masks[4]   = cntrl;
      masks[5]   = cntrl;
      masks[6]   = cntrl;
      masks[7]   = cntrl;
      masks[8]   = cntrl;
      masks[9]   = space| cntrl;
      masks[10]  = space| cntrl;
      masks[11]  = space| cntrl;
      masks[12]  = space| cntrl;
      masks[13]  = space| cntrl;
      masks[14]  = cntrl;
      masks[15]  = cntrl;
      masks[16]  = cntrl;
      masks[17]  = cntrl;
      masks[18]  = cntrl;
      masks[19]  = cntrl;
      masks[20]  = cntrl;
      masks[21]  = cntrl;
      masks[22]  = cntrl;
      masks[23]  = cntrl;
      masks[24]  = cntrl;
      masks[25]  = cntrl;
      masks[26]  = cntrl;
      masks[27]  = cntrl;
      masks[28]  = cntrl;
      masks[29]  = cntrl;
      masks[30]  = cntrl;
      masks[31]  = cntrl;
      masks[32]  = space| print;
      masks[33]  = print| punct;
      masks[34]  = print| punct;
      masks[35]  = print| punct;
      masks[36]  = print| punct;
      masks[37]  = print| punct;
      masks[38]  = print| punct;
      masks[39]  = print| punct;
      masks[40]  = print| punct;
      masks[41]  = print| punct;
      masks[42]  = print| punct;
      masks[43]  = print| punct;
      masks[44]  = print| punct;
      masks[45]  = print| punct;
      masks[46]  = print| punct;
      masks[47]  = print| punct;
      masks[48]  = print| digit| xdigit;
      masks[49]  = print| digit| xdigit;
      masks[50]  = print| digit| xdigit;
      masks[51]  = print| digit| xdigit;
      masks[52]  = print| digit| xdigit;
      masks[53]  = print| digit| xdigit;
      masks[54]  = print| digit| xdigit;
      masks[55]  = print| digit| xdigit;
      masks[56]  = print| digit| xdigit;
      masks[57]  = print| digit| xdigit;
      masks[58]  = print| punct;
      masks[59]  = print| punct;
      masks[60]  = print| punct;
      masks[61]  = print| punct;
      masks[62]  = print| punct;
      masks[63]  = print| punct;
      masks[64]  = print| punct;
      masks[65]  = print| upper| alpha| xdigit;
      masks[66]  = print| upper| alpha| xdigit;
      masks[67]  = print| upper| alpha| xdigit;
      masks[68]  = print| upper| alpha| xdigit;
      masks[69]  = print| upper| alpha| xdigit;
      masks[70]  = print| upper| alpha| xdigit;
      masks[71]  = print| upper| alpha;
      masks[72]  = print| upper| alpha;
      masks[73]  = print| upper| alpha;
      masks[74]  = print| upper| alpha;
      masks[75]  = print| upper| alpha;
      masks[76]  = print| upper| alpha;
      masks[77]  = print| upper| alpha;
      masks[78]  = print| upper| alpha;
      masks[79]  = print| upper| alpha;
      masks[80]  = print| upper| alpha;
      masks[81]  = print| upper| alpha;
      masks[82]  = print| upper| alpha;
      masks[83]  = print| upper| alpha;
      masks[84]  = print| upper| alpha;
      masks[85]  = print| upper| alpha;
      masks[86]  = print| upper| alpha;
      masks[87]  = print| upper| alpha;
      masks[88]  = print| upper| alpha;
      masks[89]  = print| upper| alpha;
      masks[90]  = print| upper| alpha;
      masks[91]  = print| punct;
      masks[92]  = print| punct;
      masks[93]  = print| punct;
      masks[94]  = print| punct;
      masks[95]  = print| punct;
      masks[96]  = print| punct;
      masks[97]  = print| lower| alpha| xdigit;
      masks[98]  = print| lower| alpha| xdigit;
      masks[99]  = print| lower| alpha| xdigit;
      masks[100] = print| lower| alpha| xdigit;
      masks[101] = print| lower| alpha| xdigit;
      masks[102] = print| lower| alpha| xdigit;
      masks[103] = print| lower| alpha;
      masks[104] = print| lower| alpha;
      masks[105] = print| lower| alpha;
      masks[106] = print| lower| alpha;
      masks[107] = print| lower| alpha;
      masks[108] = print| lower| alpha;
      masks[109] = print| lower| alpha;
      masks[110] = print| lower| alpha;
      masks[111] = print| lower| alpha;
      masks[112] = print| lower| alpha;
      masks[113] = print| lower| alpha;
      masks[114] = print| lower| alpha;
      masks[115] = print| lower| alpha;
      masks[116] = print| lower| alpha;
      masks[117] = print| lower| alpha;
      masks[118] = print| lower| alpha;
      masks[119] = print| lower| alpha;
      masks[120] = print| lower| alpha;
      masks[121] = print| lower| alpha;
      masks[122] = print| lower| alpha;
      masks[123] = print| punct;
      masks[124] = print| punct;
      masks[125] = print| punct;
      masks[126] = print| punct;
      masks[127] = cntrl;
      masks[0x3e]	0x003e	#GREATER-THAN SIGN
      masks[0x3f]	0x003f	#QUESTION MARK
      masks[0x40]	0x0040	#COMMERCIAL AT
      masks[0x41]	0x0041	#LATIN CAPITAL LETTER A
      masks[0x42]	0x0042	#LATIN CAPITAL LETTER B
      masks[0x43]	0x0043	#LATIN CAPITAL LETTER C
      masks[0x44]	0x0044	#LATIN CAPITAL LETTER D
      masks[0x45]	0x0045	#LATIN CAPITAL LETTER E
      masks[0x46]	0x0046	#LATIN CAPITAL LETTER F
      masks[0x47]	0x0047	#LATIN CAPITAL LETTER G
      masks[0x48]	0x0048	#LATIN CAPITAL LETTER H
      masks[0x49]	0x0049	#LATIN CAPITAL LETTER I
      masks[0x4a]	0x004a	#LATIN CAPITAL LETTER J
      masks[0x4b]	0x004b	#LATIN CAPITAL LETTER K
      masks[0x4c]	0x004c	#LATIN CAPITAL LETTER L
      masks[0x4d]	0x004d	#LATIN CAPITAL LETTER M
      masks[0x4e]	0x004e	#LATIN CAPITAL LETTER N
      masks[0x4f]	0x004f	#LATIN CAPITAL LETTER O
      masks[0x50]	0x0050	#LATIN CAPITAL LETTER P
      masks[0x51]	0x0051	#LATIN CAPITAL LETTER Q
      masks[0x52]	0x0052	#LATIN CAPITAL LETTER R
      masks[0x53]	0x0053	#LATIN CAPITAL LETTER S
      masks[0x54]	0x0054	#LATIN CAPITAL LETTER T
      masks[0x55]	0x0055	#LATIN CAPITAL LETTER U
      masks[0x56]	0x0056	#LATIN CAPITAL LETTER V
      masks[0x57]	0x0057	#LATIN CAPITAL LETTER W
      masks[0x58]	0x0058	#LATIN CAPITAL LETTER X
      masks[0x59]	0x0059	#LATIN CAPITAL LETTER Y
      masks[0x5a]	0x005a	#LATIN CAPITAL LETTER Z
      masks[0x5b]	0x005b	#LEFT SQUARE BRACKET
      masks[0x5c]	0x005c	#REVERSE SOLIDUS
      masks[0x5d]	0x005d	#RIGHT SQUARE BRACKET
      masks[0x5e]	0x005e	#CIRCUMFLEX ACCENT
      masks[0x5f]	0x005f	#LOW LINE
      masks[0x60]	0x0060	#GRAVE ACCENT
      masks[0x61]	0x0061	#LATIN SMALL LETTER A
      masks[0x62]	0x0062	#LATIN SMALL LETTER B
      masks[0x63]	0x0063	#LATIN SMALL LETTER C
      masks[0x64]	0x0064	#LATIN SMALL LETTER D
      masks[0x65]	0x0065	#LATIN SMALL LETTER E
      masks[0x66]	0x0066	#LATIN SMALL LETTER F
      masks[0x67]	0x0067	#LATIN SMALL LETTER G
      masks[0x68]	0x0068	#LATIN SMALL LETTER H
      masks[0x69]	0x0069	#LATIN SMALL LETTER I
      masks[0x6a]	0x006a	#LATIN SMALL LETTER J
      masks[0x6b]	0x006b	#LATIN SMALL LETTER K
      masks[0x6c]	0x006c	#LATIN SMALL LETTER L
      masks[0x6d]	0x006d	#LATIN SMALL LETTER M
      masks[0x6e]	0x006e	#LATIN SMALL LETTER N
      masks[0x6f]	0x006f	#LATIN SMALL LETTER O
      masks[0x70]	0x0070	#LATIN SMALL LETTER P
      masks[0x71]	0x0071	#LATIN SMALL LETTER Q
      masks[0x72]	0x0072	#LATIN SMALL LETTER R
      masks[0x73]	0x0073	#LATIN SMALL LETTER S
      masks[0x74]	0x0074	#LATIN SMALL LETTER T
      masks[0x75]	0x0075	#LATIN SMALL LETTER U
      masks[0x76]	0x0076	#LATIN SMALL LETTER V
      masks[0x77]	0x0077	#LATIN SMALL LETTER W
      masks[0x78]	0x0078	#LATIN SMALL LETTER X
      masks[0x79]	0x0079	#LATIN SMALL LETTER Y
      masks[0x7a]	0x007a	#LATIN SMALL LETTER Z
      masks[0x7b]	0x007b	#LEFT CURLY BRACKET
      masks[0x7c]	0x007c	#VERTICAL LINE
      masks[0x7d]	0x007d	#RIGHT CURLY BRACKET
      masks[0x7e]	0x007e	#TILDE
      masks[0x7f]	0x007f	#DELETE
      masks[0x80]	0x0410	#CYRILLIC CAPITAL LETTER A
      masks[0x81]	0x0411	#CYRILLIC CAPITAL LETTER BE
      masks[0x82]	0x0412	#CYRILLIC CAPITAL LETTER VE
      masks[0x83]	0x0413	#CYRILLIC CAPITAL LETTER GHE
      masks[0x84]	0x0414	#CYRILLIC CAPITAL LETTER DE
      masks[0x85]	0x0415	#CYRILLIC CAPITAL LETTER IE
      masks[0x86]	0x0416	#CYRILLIC CAPITAL LETTER ZHE
      masks[0x87]	0x0417	#CYRILLIC CAPITAL LETTER ZE
      masks[0x88]	0x0418	#CYRILLIC CAPITAL LETTER I
      masks[0x89]	0x0419	#CYRILLIC CAPITAL LETTER SHORT I
      masks[0x8a]	0x041a	#CYRILLIC CAPITAL LETTER KA
      masks[0x8b]	0x041b	#CYRILLIC CAPITAL LETTER EL
      masks[0x8c]	0x041c	#CYRILLIC CAPITAL LETTER EM
      masks[0x8d]	0x041d	#CYRILLIC CAPITAL LETTER EN
      masks[0x8e]	0x041e	#CYRILLIC CAPITAL LETTER O
      masks[0x8f]	0x041f	#CYRILLIC CAPITAL LETTER PE
      masks[0x90]	0x0420	#CYRILLIC CAPITAL LETTER ER
      masks[0x91]	0x0421	#CYRILLIC CAPITAL LETTER ES
      masks[0x92]	0x0422	#CYRILLIC CAPITAL LETTER TE
      masks[0x93]	0x0423	#CYRILLIC CAPITAL LETTER U
      masks[0x94]	0x0424	#CYRILLIC CAPITAL LETTER EF
      masks[0x95]	0x0425	#CYRILLIC CAPITAL LETTER HA
      masks[0x96]	0x0426	#CYRILLIC CAPITAL LETTER TSE
      masks[0x97]	0x0427	#CYRILLIC CAPITAL LETTER CHE
      masks[0x98]	0x0428	#CYRILLIC CAPITAL LETTER SHA
      masks[0x99]	0x0429	#CYRILLIC CAPITAL LETTER SHCHA
      masks[0x9a]	0x042a	#CYRILLIC CAPITAL LETTER HARD SIGN
      masks[0x9b]	0x042b	#CYRILLIC CAPITAL LETTER YERU
      masks[0x9c]	0x042c	#CYRILLIC CAPITAL LETTER SOFT SIGN
      masks[0x9d]	0x042d	#CYRILLIC CAPITAL LETTER E
      masks[0x9e]	0x042e	#CYRILLIC CAPITAL LETTER YU
      masks[0x9f]	0x042f	#CYRILLIC CAPITAL LETTER YA
      masks[0xa0]	0x0430	#CYRILLIC SMALL LETTER A
      masks[0xa1]	0x0431	#CYRILLIC SMALL LETTER BE
      masks[0xa2]	0x0432	#CYRILLIC SMALL LETTER VE
      masks[0xa3]	0x0433	#CYRILLIC SMALL LETTER GHE
      masks[0xa4]	0x0434	#CYRILLIC SMALL LETTER DE
      masks[0xa5]	0x0435	#CYRILLIC SMALL LETTER IE
      masks[0xa6]	0x0436	#CYRILLIC SMALL LETTER ZHE
      masks[0xa7]	0x0437	#CYRILLIC SMALL LETTER ZE
      masks[0xa8]	0x0438	#CYRILLIC SMALL LETTER I
      masks[0xa9]	0x0439	#CYRILLIC SMALL LETTER SHORT I
      masks[0xaa]	0x043a	#CYRILLIC SMALL LETTER KA
      masks[0xab]	0x043b	#CYRILLIC SMALL LETTER EL
      masks[0xac]	0x043c	#CYRILLIC SMALL LETTER EM
      masks[0xad]	0x043d	#CYRILLIC SMALL LETTER EN
      masks[0xae]	0x043e	#CYRILLIC SMALL LETTER O
      masks[0xaf]	0x043f	#CYRILLIC SMALL LETTER PE
      masks[0xb0]	0x2591	#LIGHT SHADE
      masks[0xb1]	0x2592	#MEDIUM SHADE
      masks[0xb2]	0x2593	#DARK SHADE
      masks[0xb3]	0x2502	#BOX DRAWINGS LIGHT VERTICAL
      masks[0xb4]	0x2524	#BOX DRAWINGS LIGHT VERTICAL AND LEFT
      masks[0xb5]	0x2561	#BOX DRAWINGS VERTICAL SINGLE AND LEFT DOUBLE
      masks[0xb6]	0x2562	#BOX DRAWINGS VERTICAL DOUBLE AND LEFT SINGLE
      masks[0xb7]	0x2556	#BOX DRAWINGS DOWN DOUBLE AND LEFT SINGLE
      masks[0xb8]	0x2555	#BOX DRAWINGS DOWN SINGLE AND LEFT DOUBLE
      masks[0xb9]	0x2563	#BOX DRAWINGS DOUBLE VERTICAL AND LEFT
      masks[0xba]	0x2551	#BOX DRAWINGS DOUBLE VERTICAL
      masks[0xbb]	0x2557	#BOX DRAWINGS DOUBLE DOWN AND LEFT
      masks[0xbc]	0x255d	#BOX DRAWINGS DOUBLE UP AND LEFT
      masks[0xbd]	0x255c	#BOX DRAWINGS UP DOUBLE AND LEFT SINGLE
0xbe	0x255b	#BOX DRAWINGS UP SINGLE AND LEFT DOUBLE
0xbf	0x2510	#BOX DRAWINGS LIGHT DOWN AND LEFT
0xc0	0x2514	#BOX DRAWINGS LIGHT UP AND RIGHT
0xc1	0x2534	#BOX DRAWINGS LIGHT UP AND HORIZONTAL
0xc2	0x252c	#BOX DRAWINGS LIGHT DOWN AND HORIZONTAL
0xc3	0x251c	#BOX DRAWINGS LIGHT VERTICAL AND RIGHT
0xc4	0x2500	#BOX DRAWINGS LIGHT HORIZONTAL
0xc5	0x253c	#BOX DRAWINGS LIGHT VERTICAL AND HORIZONTAL
0xc6	0x255e	#BOX DRAWINGS VERTICAL SINGLE AND RIGHT DOUBLE
0xc7	0x255f	#BOX DRAWINGS VERTICAL DOUBLE AND RIGHT SINGLE
0xc8	0x255a	#BOX DRAWINGS DOUBLE UP AND RIGHT
0xc9	0x2554	#BOX DRAWINGS DOUBLE DOWN AND RIGHT
0xca	0x2569	#BOX DRAWINGS DOUBLE UP AND HORIZONTAL
0xcb	0x2566	#BOX DRAWINGS DOUBLE DOWN AND HORIZONTAL
0xcc	0x2560	#BOX DRAWINGS DOUBLE VERTICAL AND RIGHT
0xcd	0x2550	#BOX DRAWINGS DOUBLE HORIZONTAL
0xce	0x256c	#BOX DRAWINGS DOUBLE VERTICAL AND HORIZONTAL
0xcf	0x2567	#BOX DRAWINGS UP SINGLE AND HORIZONTAL DOUBLE
0xd0	0x2568	#BOX DRAWINGS UP DOUBLE AND HORIZONTAL SINGLE
0xd1	0x2564	#BOX DRAWINGS DOWN SINGLE AND HORIZONTAL DOUBLE
0xd2	0x2565	#BOX DRAWINGS DOWN DOUBLE AND HORIZONTAL SINGLE
0xd3	0x2559	#BOX DRAWINGS UP DOUBLE AND RIGHT SINGLE
0xd4	0x2558	#BOX DRAWINGS UP SINGLE AND RIGHT DOUBLE
0xd5	0x2552	#BOX DRAWINGS DOWN SINGLE AND RIGHT DOUBLE
0xd6	0x2553	#BOX DRAWINGS DOWN DOUBLE AND RIGHT SINGLE
0xd7	0x256b	#BOX DRAWINGS VERTICAL DOUBLE AND HORIZONTAL SINGLE
0xd8	0x256a	#BOX DRAWINGS VERTICAL SINGLE AND HORIZONTAL DOUBLE
0xd9	0x2518	#BOX DRAWINGS LIGHT UP AND LEFT
0xda	0x250c	#BOX DRAWINGS LIGHT DOWN AND RIGHT
0xdb	0x2588	#FULL BLOCK
0xdc	0x2584	#LOWER HALF BLOCK
0xdd	0x258c	#LEFT HALF BLOCK
0xde	0x2590	#RIGHT HALF BLOCK
0xdf	0x2580	#UPPER HALF BLOCK
0xe0	0x0440	#CYRILLIC SMALL LETTER ER
0xe1	0x0441	#CYRILLIC SMALL LETTER ES
0xe2	0x0442	#CYRILLIC SMALL LETTER TE
0xe3	0x0443	#CYRILLIC SMALL LETTER U
0xe4	0x0444	#CYRILLIC SMALL LETTER EF
0xe5	0x0445	#CYRILLIC SMALL LETTER HA
0xe6	0x0446	#CYRILLIC SMALL LETTER TSE
0xe7	0x0447	#CYRILLIC SMALL LETTER CHE
0xe8	0x0448	#CYRILLIC SMALL LETTER SHA
0xe9	0x0449	#CYRILLIC SMALL LETTER SHCHA
0xea	0x044a	#CYRILLIC SMALL LETTER HARD SIGN
0xeb	0x044b	#CYRILLIC SMALL LETTER YERU
0xec	0x044c	#CYRILLIC SMALL LETTER SOFT SIGN
0xed	0x044d	#CYRILLIC SMALL LETTER E
0xee	0x044e	#CYRILLIC SMALL LETTER YU
0xef	0x044f	#CYRILLIC SMALL LETTER YA
0xf0	0x0401	#CYRILLIC CAPITAL LETTER IO
0xf1	0x0451	#CYRILLIC SMALL LETTER IO
0xf2	0x0404	#CYRILLIC CAPITAL LETTER UKRAINIAN IE
0xf3	0x0454	#CYRILLIC SMALL LETTER UKRAINIAN IE
0xf4	0x0407	#CYRILLIC CAPITAL LETTER YI
0xf5	0x0457	#CYRILLIC SMALL LETTER YI
0xf6	0x040e	#CYRILLIC CAPITAL LETTER SHORT U
0xf7	0x045e	#CYRILLIC SMALL LETTER SHORT U
0xf8	0x00b0	#DEGREE SIGN
0xf9	0x2219	#BULLET OPERATOR
0xfa	0x00b7	#MIDDLE DOT
0xfb	0x221a	#SQUARE ROOT
0xfc	0x2116	#NUMERO SIGN
0xfd	0x00a4	#CURRENCY SIGN
0xfe	0x25a0	#BLACK SQUARE
0xff	0x00a0	#NO-BREAK SPACE

    }

    ~ctype_cp866()
    {}

  protected:
    virtual bool do_is(mask m, Ch c) const
    {
      if( 0 <= c && c <= 127 )
        return ctype<Ch>::do_is(m, c);
      else if( -128 <= c && c < 0 )
        return ext_table[static_cast<size_t>(c*-1)] & m;
      else
        return false;
    };

    virtual const Ch* do_is(const Ch* b, const Ch* e, mask* v) const
    {
      while(b != e)
      {
        if( -128 <= *b && *b < 0 )
          *v = ext_table[static_cast<size_t>(*b*(-1))];
        else
          do_is(b, b+1, v);
        ++b;
        ++v;
      }
      return b;
    }

    virtual const Ch* do_scan_is(mask m, const Ch* b, const Ch* e) const
    {
      while(b != e && !do_is(m,*b)) ++b;
      return b;
    }

    virtual const Ch* do_scan_not(mask m, const Ch* b, const Ch* e) const
    {
      while(b != e && do_is(m,*b)) ++b;
      return b;
    }

    virtual Ch do_toupper(Ch c) const
    {
      if( 0 <= c && c <= 127 )
      {
        return ctype<Ch>::do_toupper(c);
      }
      else if( -128 <= c && c < 0 && do_is(lower, c))
      {
        if( c != -66 && c != -77 && c != -95 && c != -125 )
          return c - 32;
        else if( c == -125 )
          return -127;
        else
          return c - 1;
      }
      else
      {
        return c;
      }
    }

    virtual const Ch* do_toupper(Ch* b, const Ch* e) const
    {
      for(; b!=e; ++b)
        *b = do_toupper(*b);
      return e;
    }

    virtual Ch do_tolower(Ch c) const
    {
      if( 0 <= c && c <= 127 )
      {
        return ctype<Ch>::do_tolower(c);
      }
      else if( -128 <= c && c < 0 && do_is(upper, c))
      {
        if( c != -67 && c != -78 && c != -96 && c != -127 )
          return c + 32;
        else if( c == -127 )
          return -125;
        else
          return c + 1;
      }
      else
      {
        return c;
      }
    }

    virtual const Ch* do_tolower(Ch* b, const Ch* e) const
    {
      for(; b!=e; ++b)
        *b = do_tolower(*b);
      return e;
    }
/*
    Ch do_widen(char c) const;
    {
      if( 0 <= c <= 127 )
        return ctype::widen(c);
      else if( -128 <= c < 0 )
        return ext_table[static_cast<size_t>(c*-1)] & m;
      else
        return false;
    }

    const char* widen(const char* b, const char* e, Ch* b2) const;
    char narrow(Ch c, char def) const;
    const Ch* narrow(const Ch* b, const Ch* e, char def, char* b2) const;
*/
  private:
    ctype_cp866(const ctype_cp866&);
    void operator=(const ctype_cp866&);
    mask masks[256];
};

#endif // __CTYPE_CP866_H__

#ifndef __CTYPE_CP1251_HPP__
#define __CTYPE_CP1251_HPP__

#include <locale>

using namespace std;

/**@brief ctype facet modification for cp1251*/
template<class Ch>
class ctype_cp1251 : public ctype<Ch>
{
  public:
    typedef Ch char_type;
    typedef typename ctype<Ch>::mask mask;

    enum{
      lower = ctype<Ch>::lower,
      upper = ctype<Ch>::upper,
      punct = ctype<Ch>::punct,
      alpha = ctype<Ch>::alpha
    };

    explicit ctype_cp1251(size_t r = 0)
    {
      ext_table[0] = 0;
      for(size_t i = 1; i <= 32; i++)
        ext_table[i] = lower | alpha;
      for(size_t i = 33; i <= 64; i++)
        ext_table[i] = upper | alpha;
      ext_table[65]  = lower | alpha; ext_table[66]  = lower | alpha;
      ext_table[67]  = upper | alpha; ext_table[68]  = alpha;
      ext_table[69]  = punct;         ext_table[70]  = lower | alpha;
      ext_table[71]  = punct;         ext_table[72]  = lower | alpha;
      ext_table[73]  = punct;         ext_table[74]  = punct;
      ext_table[75]  = alpha;         ext_table[76]  = lower | alpha;
      ext_table[77]  = lower | alpha; ext_table[78]  = upper | alpha;
      ext_table[79]  = punct;         ext_table[80]  = punct;
      ext_table[81]  = upper | alpha; ext_table[82]  = punct;
      ext_table[83]  = punct;         ext_table[84]  = punct;
      ext_table[85]  = punct;         ext_table[86]  = upper | alpha;
      ext_table[87]  = punct;         ext_table[88]  = upper | alpha;
      ext_table[89]  = punct;         ext_table[90]  = punct;
      ext_table[91]  = upper | alpha; ext_table[92]  = punct;
      ext_table[93]  = upper | alpha; ext_table[94]  = lower | alpha;
      ext_table[95]  = upper | alpha; ext_table[96]  = punct;
      ext_table[97]  = lower | alpha; ext_table[98]  = lower | alpha;
      ext_table[99]  = lower | alpha; ext_table[100] = lower | alpha;
      ext_table[101] = punct;         ext_table[102] = lower | alpha;
      ext_table[103] = punct;         ext_table[104] = punct;
      ext_table[105] = punct;         ext_table[106] = punct;
      ext_table[107] = punct;         ext_table[108] = punct;
      ext_table[109] = punct;         ext_table[110] = punct;
      ext_table[111] = punct;         ext_table[112] = lower | alpha;
      ext_table[113] = upper | alpha; ext_table[114] = upper | alpha;
      ext_table[115] = upper | alpha; ext_table[116] = upper | alpha;
      ext_table[117] = punct;         ext_table[118] = upper | alpha;
      ext_table[119] = punct;         ext_table[120] = punct;
      ext_table[121] = punct;         ext_table[122] = punct;
      ext_table[123] = punct;         ext_table[124] = punct;
      ext_table[125] = lower | alpha; ext_table[126] = punct;
      ext_table[127] = upper | alpha; ext_table[128] = upper | alpha;
    }

    ~ctype_cp1251()
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
      if(!do_is(lower, c))
        return c;
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
      if(!do_is(upper, c))
        return c;
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
/*  MARKED DEPRECATED
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
    ctype_cp1251(const ctype_cp1251&);
    void operator=(const ctype_cp1251&);
    mask ext_table[128];
};

#endif // __CTYPE_CP1251_HPP__

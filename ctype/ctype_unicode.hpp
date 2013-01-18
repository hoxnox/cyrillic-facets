#ifndef __CTYPE_UNICODE_HPP__
#define __CTYPE_UNICODE_HPP__

#include <locale>
#include <map>

using namespace std;

/**@brief ctype facet modification for unicode cyrillic (basic russian
 * alphabet and cyrillic extensions) symbols
 *
 * See ctype facet decl*/
class ctype_unicode : public ctype<wchar_t>
{
  public:
    typedef ctype<wchar_t>::mask mask;

    enum{
      lower = ctype<wchar_t>::lower,
      upper = ctype<wchar_t>::upper,
      alpha = ctype<wchar_t>::alpha,
      print = ctype<wchar_t>::print
    };

    explicit ctype_unicode(size_t r = 0)
      : std::ctype<wchar_t>(r)
    {
      // initializing masks map
      for(wchar_t i = 0x400; i <= 0x40F; i++)
        masks[i] = upper | alpha | print;
      for(wchar_t i = 0x410; i <= 0x42F; i++)
        masks[i] = upper | alpha | print;
      for(wchar_t i = 0x430; i <= 0x44F; i++)
        masks[i] = lower | alpha | print;
      for(wchar_t i = 0x450; i <= 0x45F; i++)
        masks[i] = lower | alpha | print;
    }

    ~ctype_unicode()
    {}

  protected:
    virtual bool do_is(mask m, wchar_t c) const
    {
      std::map<mask, wchar_t>::const_iterator msk = masks.find(c);
      if(msk != masks.end())
        return (msk->second & m) != 0;
      else
        return ctype<wchar_t>::do_is(m,c);
    };

    virtual const wchar_t* do_is(const wchar_t* b,
                                 const wchar_t* e,
                                 mask* v)
    const
    {
      while(b != e)
      {
        std::map<mask, wchar_t>::const_iterator msk = masks.find(*b);
        if(msk != masks.end())
          *v = msk->first;
        else
          ctype<wchar_t>::do_is(b, b+1, v);
        ++b;
        ++v;
      }
      return b;
    }

    virtual const wchar_t* do_scan_is(mask m,
                                      const wchar_t* b,
                                      const wchar_t* e)
    const
    {
      while(b != e && !do_is(m,*b)) ++b;
      return b;
    }

    virtual const wchar_t* do_scan_not(mask m,
                                       const wchar_t* b,
                                       const wchar_t* e)
    const
    {
      while(b != e && do_is(m,*b)) ++b;
      return b;
    }

    virtual wchar_t do_toupper(wchar_t c) const
    {
      std::map<mask, wchar_t>::const_iterator msk = masks.find(c);
      if( msk != masks.end() )
      {
        if( this->do_is(lower,c) )
        {
          // cyrillic extensions
          if(0x450 <= c && c <= 0x45F)
            return c - 0x50;
          // basic russian alphabet
          else if(0x430 <= c && c <= 0x44F)
            return c - 0x20;
        }
        else
        {
          return c;
        }
      }
      return ctype<wchar_t>::do_toupper(c);
    }

    virtual const wchar_t* do_toupper(wchar_t* b, const wchar_t* e) const
    {
      for(; b!=e; ++b)
        *b = do_toupper(*b);
      return e;
    }

    virtual wchar_t do_tolower(wchar_t c) const
    {
      std::map<mask, wchar_t>::const_iterator msk = masks.find(c);
      if( msk != masks.end() )
      {
        if( this->do_is(upper,c) )
        {
          // cyrillic extensions
          if(0x400 <= c && c <= 0x40F)
            return c + 0x50;
          // basic russian alphabet
          else if(0x410 <= c && c <= 0x42F)
            return c + 0x20;
        }
        else
        {
          return c;
        }
      }
      return ctype<wchar_t>::do_tolower(c);
    }

    virtual const wchar_t* do_tolower(wchar_t* b, const wchar_t* e) const
    {
      for(; b!=e; ++b)
        *b = do_tolower(*b);
      return e;
    }

	/* marked deprecated
    wchar_t do_widen(char c) const
    {
      if(static_cast<unsigned char>(c) <= 127)
        return static_cast<wchar_t>(c);
      else
        return 0;
    }

    const char* do_widen(const char* b, const char* e, wchar_t* b2)
    const
    {
      while(b != e)
      {
        *b2 = do_widen(*b);
        ++b;
        ++b2;
      }
      return b;
    }

    char do_narrow(wchar_t c, char def) const
    {
      if(0 <= c && c <= 127)
        return static_cast<char>(c);
      else
        return def;
    }

    const wchar_t* do_narrow(const wchar_t* b, const wchar_t* e,
        char def, char* b2) const
    {
      while(b != e)
      {
        *b2 = do_narrow(*b, def);
        ++b;
        ++b2;
      }
      return b;
    }*/

  private:
    ctype_unicode(const ctype_unicode&);
    void operator=(const ctype_unicode&);
    std::map<mask, wchar_t> masks;
};

#endif // __CTYPE_UNICODE_HPP__

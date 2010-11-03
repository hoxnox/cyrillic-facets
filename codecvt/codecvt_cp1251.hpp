#ifndef __CODECVT_CP1251_HPP__
#define __CODECVT_CP1251_HPP__

#include <locale>
#include <map>

/**@brief Facet is used to convert cyrillic char strings in cp1251 
 * encoding into UNICODE*/
template<class I, class E, class State>
class codecvt_cp1251 : public std::codecvt<I, E, State>
{
  public:

    typedef typename std::codecvt_base::result result;
    const result ok, partial, error, noconv;

    explicit codecvt_cp1251(size_t r=0)
      : std::codecvt<I, E, State>(r),
        ok(std::codecvt_base::ok),
        partial(std::codecvt_base::partial),
        error(std::codecvt_base::error),
        noconv(std::codecvt_base::noconv)
    {
      // extended cyrillic
      in_tab[0xA8] = 0x401;  out_tab[0x401] = 0xA8;
      in_tab[0xB8] = 0x451;  out_tab[0x451] = 0xB8;
      in_tab[0x80] = 0x402;  out_tab[0x402] = 0x80;
      in_tab[0x90] = 0x452;  out_tab[0x452] = 0x90;
      in_tab[0x81] = 0x403;  out_tab[0x403] = 0x81;
      in_tab[0x83] = 0x453;  out_tab[0x453] = 0x83;
      in_tab[0xAA] = 0x404;  out_tab[0x404] = 0xAA;
      in_tab[0xBA] = 0x454;  out_tab[0x454] = 0xBA;
      in_tab[0xBD] = 0x405;  out_tab[0x405] = 0xBD;
      in_tab[0xBE] = 0x455;  out_tab[0x455] = 0xBE;
      in_tab[0xB2] = 0x406;  out_tab[0x406] = 0xB2;
      in_tab[0xB3] = 0x456;  out_tab[0x456] = 0xB3;
      in_tab[0xAF] = 0x407;  out_tab[0x407] = 0xAF;
      in_tab[0xBF] = 0x457;  out_tab[0x457] = 0xBF;
      in_tab[0xA3] = 0x408;  out_tab[0x408] = 0xA3;
      in_tab[0xBC] = 0x458;  out_tab[0x458] = 0xBC;
      in_tab[0x8A] = 0x409;  out_tab[0x409] = 0x8A;
      in_tab[0x9A] = 0x459;  out_tab[0x459] = 0x9A;
      in_tab[0x8C] = 0x40A;  out_tab[0x40A] = 0x8C;
      in_tab[0x9C] = 0x45A;  out_tab[0x45A] = 0x9C;
      in_tab[0x8E] = 0x40B;  out_tab[0x40B] = 0x8E;
      in_tab[0x9E] = 0x45B;  out_tab[0x45B] = 0x9E;
      in_tab[0x8D] = 0x40C;  out_tab[0x40C] = 0x8D;
      in_tab[0x9D] = 0x45C;  out_tab[0x45C] = 0x9D;
      in_tab[0xA1] = 0x40E;  out_tab[0x40E] = 0xA1;
      in_tab[0xA2] = 0x45E;  out_tab[0x45E] = 0xA2;
      in_tab[0x8F] = 0x40F;  out_tab[0x40F] = 0x8F;
      in_tab[0x9F] = 0x45F;  out_tab[0x45F] = 0x9F;
    }

    ~codecvt_cp1251()
    {
    }

protected:
  virtual result do_in(State&,
               const E* from, const E* from_end, const E* &from_next,
               I* to, I* to_end, I* &to_next)
    const
  {
    while(from != from_end)
    {
      if(to == to_end)
      {
        from_next = from;
        to_next = to;
        return partial;
      }
      // ASCII
      if(0 <= *from && *from <= 0x7F)
      {
        *to = static_cast<I>(*from);
      }
      else if(0xC0 <= static_cast<unsigned char>(*from)
                   && static_cast<unsigned char>(*from) <=0xFF)
      {
        *to = static_cast<I>(static_cast<unsigned char>(*from) + 0x350);
      }
      else
      {
        typename std::map<E, I>::const_iterator s;
        s = in_tab.lower_bound(*from);
        if(s == in_tab.end())
        {
          from_next = from + 1;
          return error;
        }
        if(to == to_end)
        {
          to_next = to_end;
          return error;
        }
        *to = s->second;
      }
      ++to;
      ++from;
    }
    from_next = from_end;
    to_next = to;
    return ok;
  }

  virtual result do_out(State&,
                const I* from, const I* from_end, const I* &from_next,
                E* to, E* to_end, E* &to_next)
    const
  {
    while(from != from_end)
    {
      if(to == to_end)
      {
        from_next = from;
        to_next = to;
        return partial;
      }
      if(0 <= *from && *from <= 0x7F)
      {
        *to = static_cast<unsigned char>(*from);
      }
      else if(0x410 <= static_cast<wchar_t>(*from)
                    && static_cast<wchar_t>(*from) <=0x44F)
      {
        *to = static_cast<char>(static_cast<wchar_t>(*from) - 0x350);
      }
      else
      {
        typename std::map<I, E>::const_iterator s;
        s = out_tab.lower_bound(*from);
        if(s == out_tab.end())
        {
          from_next = from + 1;
          return error;
        }
        if(to == to_end)
        {
          to_next = to_end;
          return error;
        }
        *to = s->second;
      }
      ++to;
      ++from;
    }
    from_next = from_end;
    to_next = to;
    return ok;
  }

  virtual int do_encoding() const throw()
  {
    return 1;
  }

  virtual bool do_always_noconv() const throw()
  {
    return false;
  }
      /*
  virtual int do_length(State& s, const E* from, const E* from_end, size_t max) const
  {
    return codecvt<I, E, State>::do_length(s, from, from_end, max);
  }

  virtual int do_max_length() const throw()
  {
    return codecvt<I, E, State>::do_max_length();
  }
     */
private:
  std::map<E, I> in_tab;
  std::map<I, E> out_tab;

};

#endif // __CODECVT_CP1251__


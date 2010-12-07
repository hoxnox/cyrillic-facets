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
      in_tab[(unsigned)0x80] = 0x0402; out_tab[0x0402] = (unsigned)0x80;
      in_tab[(unsigned)0x81] = 0x0403; out_tab[0x0403] = (unsigned)0x81;
      in_tab[(unsigned)0x82] = 0x201A; out_tab[0x201A] = (unsigned)0x82;
      in_tab[(unsigned)0x83] = 0x0453; out_tab[0x0453] = (unsigned)0x83;
      in_tab[(unsigned)0x84] = 0x201E; out_tab[0x201E] = (unsigned)0x84;
      in_tab[(unsigned)0x85] = 0x2026; out_tab[0x2026] = (unsigned)0x85;
      in_tab[(unsigned)0x86] = 0x2020; out_tab[0x2020] = (unsigned)0x86;
      in_tab[(unsigned)0x87] = 0x2021; out_tab[0x2021] = (unsigned)0x87;
      in_tab[(unsigned)0x88] = 0x20AC; out_tab[0x20AC] = (unsigned)0x88;
      in_tab[(unsigned)0x89] = 0x2030; out_tab[0x2030] = (unsigned)0x89;
      in_tab[(unsigned)0x8A] = 0x0409; out_tab[0x0409] = (unsigned)0x8A;
      in_tab[(unsigned)0x8B] = 0x2039; out_tab[0x2039] = (unsigned)0x8B;
      in_tab[(unsigned)0x8C] = 0x040A; out_tab[0x040A] = (unsigned)0x8C;
      in_tab[(unsigned)0x8D] = 0x040C; out_tab[0x040C] = (unsigned)0x8D;
      in_tab[(unsigned)0x8E] = 0x040B; out_tab[0x040B] = (unsigned)0x8E;
      in_tab[(unsigned)0x8F] = 0x040F; out_tab[0x040F] = (unsigned)0x8F;
      in_tab[(unsigned)0x90] = 0x0452; out_tab[0x0452] = (unsigned)0x90;
      in_tab[(unsigned)0x91] = 0x2018; out_tab[0x2018] = (unsigned)0x91;
      in_tab[(unsigned)0x92] = 0x2019; out_tab[0x2019] = (unsigned)0x92;
      in_tab[(unsigned)0x93] = 0x201C; out_tab[0x201C] = (unsigned)0x93;
      in_tab[(unsigned)0x94] = 0x201D; out_tab[0x201D] = (unsigned)0x94;
      in_tab[(unsigned)0x95] = 0x2022; out_tab[0x2022] = (unsigned)0x95;
      in_tab[(unsigned)0x96] = 0x2013; out_tab[0x2013] = (unsigned)0x96;
      in_tab[(unsigned)0x97] = 0x2014; out_tab[0x2014] = (unsigned)0x97;
  //  in_tab[(unsigned)0x98] =       ;                   
      in_tab[(unsigned)0x99] = 0x2122; out_tab[0x2122] = (unsigned)0x99;
      in_tab[(unsigned)0x9A] = 0x0459; out_tab[0x0459] = (unsigned)0x9A;
      in_tab[(unsigned)0x9B] = 0x203A; out_tab[0x203A] = (unsigned)0x9B;
      in_tab[(unsigned)0x9C] = 0x045A; out_tab[0x045A] = (unsigned)0x9C;
      in_tab[(unsigned)0x9D] = 0x045C; out_tab[0x045C] = (unsigned)0x9D;
      in_tab[(unsigned)0x9E] = 0x045B; out_tab[0x045B] = (unsigned)0x9E;
      in_tab[(unsigned)0x9F] = 0x045F; out_tab[0x045F] = (unsigned)0x9F;
      in_tab[(unsigned)0xA0] = 0x00A0; out_tab[0x00A0] = (unsigned)0xA0;
      in_tab[(unsigned)0xA1] = 0x040E; out_tab[0x040E] = (unsigned)0xA1;
      in_tab[(unsigned)0xA2] = 0x045E; out_tab[0x045E] = (unsigned)0xA2;
      in_tab[(unsigned)0xA3] = 0x0408; out_tab[0x0408] = (unsigned)0xA3;
      in_tab[(unsigned)0xA4] = 0x00A4; out_tab[0x00A4] = (unsigned)0xA4;
      in_tab[(unsigned)0xA5] = 0x0490; out_tab[0x0490] = (unsigned)0xA5;
      in_tab[(unsigned)0xA6] = 0x00A6; out_tab[0x00A6] = (unsigned)0xA6;
      in_tab[(unsigned)0xA7] = 0x00A7; out_tab[0x00A7] = (unsigned)0xA7;
      in_tab[(unsigned)0xA8] = 0x0401; out_tab[0x0401] = (unsigned)0xA8;
      in_tab[(unsigned)0xA9] = 0x00A9; out_tab[0x00A9] = (unsigned)0xA9;
      in_tab[(unsigned)0xAA] = 0x0404; out_tab[0x0404] = (unsigned)0xAA;
      in_tab[(unsigned)0xAB] = 0x00AB; out_tab[0x00AB] = (unsigned)0xAB;
      in_tab[(unsigned)0xAC] = 0x00AC; out_tab[0x00AC] = (unsigned)0xAC;
      in_tab[(unsigned)0xAD] = 0x00AD; out_tab[0x00AD] = (unsigned)0xAD;
      in_tab[(unsigned)0xAE] = 0x00AE; out_tab[0x00AE] = (unsigned)0xAE;
      in_tab[(unsigned)0xAF] = 0x0407; out_tab[0x0407] = (unsigned)0xAF;
      in_tab[(unsigned)0xB0] = 0x00B0; out_tab[0x00B0] = (unsigned)0xB0;
      in_tab[(unsigned)0xB1] = 0x00B1; out_tab[0x00B1] = (unsigned)0xB1;
      in_tab[(unsigned)0xB2] = 0x0406; out_tab[0x0406] = (unsigned)0xB2;
      in_tab[(unsigned)0xB3] = 0x0456; out_tab[0x0456] = (unsigned)0xB3;
      in_tab[(unsigned)0xB4] = 0x0491; out_tab[0x0491] = (unsigned)0xB4;
      in_tab[(unsigned)0xB5] = 0x00B5; out_tab[0x00B5] = (unsigned)0xB5;
      in_tab[(unsigned)0xB6] = 0x00B6; out_tab[0x00B6] = (unsigned)0xB6;
      in_tab[(unsigned)0xB7] = 0x00B7; out_tab[0x00B7] = (unsigned)0xB7;
      in_tab[(unsigned)0xB8] = 0x0451; out_tab[0x0451] = (unsigned)0xB8;
      in_tab[(unsigned)0xB9] = 0x2116; out_tab[0x2116] = (unsigned)0xB9;
      in_tab[(unsigned)0xBA] = 0x0454; out_tab[0x0454] = (unsigned)0xBA;
      in_tab[(unsigned)0xBB] = 0x00BB; out_tab[0x00BB] = (unsigned)0xBB;
      in_tab[(unsigned)0xBC] = 0x0458; out_tab[0x0458] = (unsigned)0xBC;
      in_tab[(unsigned)0xBD] = 0x0405; out_tab[0x0405] = (unsigned)0xBD;
      in_tab[(unsigned)0xBE] = 0x0455; out_tab[0x0455] = (unsigned)0xBE;
      in_tab[(unsigned)0xBF] = 0x0457; out_tab[0x0457] = (unsigned)0xBF;
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
        from_next = ++from;
        to_next = to;
        return partial;
      }
      // ASCII
      if((unsigned)*from <= 0x7F)
      {
        *to = static_cast<I>(*from);
      }
      else if(0xC0 <= (unsigned)(*from)
                   && (unsigned)(*from) <=0xFF)
      {
        *to = static_cast<I>((unsigned)(*from) + 0x350);
      }
      else
      {
        typename std::map<E, I>::const_iterator s;
        s = in_tab.lower_bound(*from);
        if(s->first != *from || s == in_tab.end())
        {
          // ok from and to is not endings
          from_next = ++from;
          to_next = ++to;
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
        from_next = ++from;
        to_next = to;
        return partial;
      }
      if(0 <= *from && *from <= 0x7F)
      {
        *to = (unsigned)(*from);
      }
      else if(0x410 <= (unsigned)(*from)
                    && (unsigned)(*from) <=0x44F)
      {
        *to = static_cast<E>(static_cast<I>(*from) - 0x350);
      }
      else
      {
        typename std::map<I, E>::const_iterator s;
        s = out_tab.lower_bound(*from);
        if( s->first != *from || s == out_tab.end())
        {
          // ok from and to is not endings
          from_next = ++from;
          to_next = ++to;
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


#ifndef __CODECVT_CP1251_HPP__
#define __CODECVT_CP1251_HPP__

#include <locale>
#include <map>

/**@brief Facet is used to convert cyrillic char strings in cp1251
 * encoding into UNICODE*/
class codecvt_cp1251 : public std::codecvt<wchar_t, char, mbstate_t>
{
  public:

    typedef typename std::codecvt_base::result result;
    const result ok, partial, error, noconv;

    explicit codecvt_cp1251(size_t r=0)
      : std::codecvt<wchar_t, char, mbstate_t>(r),
        ok(std::codecvt_base::ok),
        partial(std::codecvt_base::partial),
        error(std::codecvt_base::error),
        noconv(std::codecvt_base::noconv)
    {
      // UNICODE -> CP1251 tab, extended part without alpha
      out_tab[0x0402] = static_cast<unsigned char>(0x80);
      out_tab[0x0403] = static_cast<unsigned char>(0x81);
      out_tab[0x201A] = static_cast<unsigned char>(0x82);
      out_tab[0x0453] = static_cast<unsigned char>(0x83);
      out_tab[0x201E] = static_cast<unsigned char>(0x84);
      out_tab[0x2026] = static_cast<unsigned char>(0x85);
      out_tab[0x2020] = static_cast<unsigned char>(0x86);
      out_tab[0x2021] = static_cast<unsigned char>(0x87);
      out_tab[0x20AC] = static_cast<unsigned char>(0x88);
      out_tab[0x2030] = static_cast<unsigned char>(0x89);
      out_tab[0x0409] = static_cast<unsigned char>(0x8A);
      out_tab[0x2039] = static_cast<unsigned char>(0x8B);
      out_tab[0x040A] = static_cast<unsigned char>(0x8C);
      out_tab[0x040C] = static_cast<unsigned char>(0x8D);
      out_tab[0x040B] = static_cast<unsigned char>(0x8E);
      out_tab[0x040F] = static_cast<unsigned char>(0x8F);
      out_tab[0x0452] = static_cast<unsigned char>(0x90);
      out_tab[0x2018] = static_cast<unsigned char>(0x91);
      out_tab[0x2019] = static_cast<unsigned char>(0x92);
      out_tab[0x201C] = static_cast<unsigned char>(0x93);
      out_tab[0x201D] = static_cast<unsigned char>(0x94);
      out_tab[0x2022] = static_cast<unsigned char>(0x95);
      out_tab[0x2013] = static_cast<unsigned char>(0x96);
      out_tab[0x2014] = static_cast<unsigned char>(0x97);
      //out_tab[    ] = static_cast<unsigned char>(0x98);
      out_tab[0x2122] = static_cast<unsigned char>(0x99);
      out_tab[0x0459] = static_cast<unsigned char>(0x9A);
      out_tab[0x203A] = static_cast<unsigned char>(0x9B);
      out_tab[0x045A] = static_cast<unsigned char>(0x9C);
      out_tab[0x045C] = static_cast<unsigned char>(0x9D);
      out_tab[0x045B] = static_cast<unsigned char>(0x9E);
      out_tab[0x045F] = static_cast<unsigned char>(0x9F);
      out_tab[0x00A0] = static_cast<unsigned char>(0xA0);
      out_tab[0x040E] = static_cast<unsigned char>(0xA1);
      out_tab[0x045E] = static_cast<unsigned char>(0xA2);
      out_tab[0x0408] = static_cast<unsigned char>(0xA3);
      out_tab[0x00A4] = static_cast<unsigned char>(0xA4);
      out_tab[0x0490] = static_cast<unsigned char>(0xA5);
      out_tab[0x00A6] = static_cast<unsigned char>(0xA6);
      out_tab[0x00A7] = static_cast<unsigned char>(0xA7);
      out_tab[0x0401] = static_cast<unsigned char>(0xA8);
      out_tab[0x00A9] = static_cast<unsigned char>(0xA9);
      out_tab[0x0404] = static_cast<unsigned char>(0xAA);
      out_tab[0x00AB] = static_cast<unsigned char>(0xAB);
      out_tab[0x00AC] = static_cast<unsigned char>(0xAC);
      out_tab[0x00AD] = static_cast<unsigned char>(0xAD);
      out_tab[0x00AE] = static_cast<unsigned char>(0xAE);
      out_tab[0x0407] = static_cast<unsigned char>(0xAF);
      out_tab[0x00B0] = static_cast<unsigned char>(0xB0);
      out_tab[0x00B1] = static_cast<unsigned char>(0xB1);
      out_tab[0x0406] = static_cast<unsigned char>(0xB2);
      out_tab[0x0456] = static_cast<unsigned char>(0xB3);
      out_tab[0x0491] = static_cast<unsigned char>(0xB4);
      out_tab[0x00B5] = static_cast<unsigned char>(0xB5);
      out_tab[0x00B6] = static_cast<unsigned char>(0xB6);
      out_tab[0x00B7] = static_cast<unsigned char>(0xB7);
      out_tab[0x0451] = static_cast<unsigned char>(0xB8);
      out_tab[0x2116] = static_cast<unsigned char>(0xB9);
      out_tab[0x0454] = static_cast<unsigned char>(0xBA);
      out_tab[0x00BB] = static_cast<unsigned char>(0xBB);
      out_tab[0x0458] = static_cast<unsigned char>(0xBC);
      out_tab[0x0405] = static_cast<unsigned char>(0xBD);
      out_tab[0x0455] = static_cast<unsigned char>(0xBE);
      out_tab[0x0457] = static_cast<unsigned char>(0xBF);
      // CP1251 -> UNICODE tab, extended part without alpha
      in_tab[static_cast<unsigned char>(0x80)] = 0x0402;
      in_tab[static_cast<unsigned char>(0x81)] = 0x0403;
      in_tab[static_cast<unsigned char>(0x82)] = 0x201A;
      in_tab[static_cast<unsigned char>(0x83)] = 0x0453;
      in_tab[static_cast<unsigned char>(0x84)] = 0x201E;
      in_tab[static_cast<unsigned char>(0x85)] = 0x2026;
      in_tab[static_cast<unsigned char>(0x86)] = 0x2020;
      in_tab[static_cast<unsigned char>(0x87)] = 0x2021;
      in_tab[static_cast<unsigned char>(0x88)] = 0x20AC;
      in_tab[static_cast<unsigned char>(0x89)] = 0x2030;
      in_tab[static_cast<unsigned char>(0x8A)] = 0x0409;
      in_tab[static_cast<unsigned char>(0x8B)] = 0x2039;
      in_tab[static_cast<unsigned char>(0x8C)] = 0x040A;
      in_tab[static_cast<unsigned char>(0x8D)] = 0x040C;
      in_tab[static_cast<unsigned char>(0x8E)] = 0x040B;
      in_tab[static_cast<unsigned char>(0x8F)] = 0x040F;
      in_tab[static_cast<unsigned char>(0x90)] = 0x0452;
      in_tab[static_cast<unsigned char>(0x91)] = 0x2018;
      in_tab[static_cast<unsigned char>(0x92)] = 0x2019;
      in_tab[static_cast<unsigned char>(0x93)] = 0x201C;
      in_tab[static_cast<unsigned char>(0x94)] = 0x201D;
      in_tab[static_cast<unsigned char>(0x95)] = 0x2022;
      in_tab[static_cast<unsigned char>(0x96)] = 0x2013;
      in_tab[static_cast<unsigned char>(0x97)] = 0x2014;
      //in_tab[static_cast<unsigned char>(0x98)] =     ;
      in_tab[static_cast<unsigned char>(0x99)] = 0x2122;
      in_tab[static_cast<unsigned char>(0x9A)] = 0x0459;
      in_tab[static_cast<unsigned char>(0x9B)] = 0x203A;
      in_tab[static_cast<unsigned char>(0x9C)] = 0x045A;
      in_tab[static_cast<unsigned char>(0x9D)] = 0x045C;
      in_tab[static_cast<unsigned char>(0x9E)] = 0x045B;
      in_tab[static_cast<unsigned char>(0x9F)] = 0x045F;
      in_tab[static_cast<unsigned char>(0xA0)] = 0x00A0;
      in_tab[static_cast<unsigned char>(0xA1)] = 0x040E;
      in_tab[static_cast<unsigned char>(0xA2)] = 0x045E;
      in_tab[static_cast<unsigned char>(0xA3)] = 0x0408;
      in_tab[static_cast<unsigned char>(0xA4)] = 0x00A4;
      in_tab[static_cast<unsigned char>(0xA5)] = 0x0490;
      in_tab[static_cast<unsigned char>(0xA6)] = 0x00A6;
      in_tab[static_cast<unsigned char>(0xA7)] = 0x00A7;
      in_tab[static_cast<unsigned char>(0xA8)] = 0x0401;
      in_tab[static_cast<unsigned char>(0xA9)] = 0x00A9;
      in_tab[static_cast<unsigned char>(0xAA)] = 0x0404;
      in_tab[static_cast<unsigned char>(0xAB)] = 0x00AB;
      in_tab[static_cast<unsigned char>(0xAC)] = 0x00AC;
      in_tab[static_cast<unsigned char>(0xAD)] = 0x00AD;
      in_tab[static_cast<unsigned char>(0xAE)] = 0x00AE;
      in_tab[static_cast<unsigned char>(0xAF)] = 0x0407;
      in_tab[static_cast<unsigned char>(0xB0)] = 0x00B0;
      in_tab[static_cast<unsigned char>(0xB1)] = 0x00B1;
      in_tab[static_cast<unsigned char>(0xB2)] = 0x0406;
      in_tab[static_cast<unsigned char>(0xB3)] = 0x0456;
      in_tab[static_cast<unsigned char>(0xB4)] = 0x0491;
      in_tab[static_cast<unsigned char>(0xB5)] = 0x00B5;
      in_tab[static_cast<unsigned char>(0xB6)] = 0x00B6;
      in_tab[static_cast<unsigned char>(0xB7)] = 0x00B7;
      in_tab[static_cast<unsigned char>(0xB8)] = 0x0451;
      in_tab[static_cast<unsigned char>(0xB9)] = 0x2116;
      in_tab[static_cast<unsigned char>(0xBA)] = 0x0454;
      in_tab[static_cast<unsigned char>(0xBB)] = 0x00BB;
      in_tab[static_cast<unsigned char>(0xBC)] = 0x0458;
      in_tab[static_cast<unsigned char>(0xBD)] = 0x0405;
      in_tab[static_cast<unsigned char>(0xBE)] = 0x0455;
      in_tab[static_cast<unsigned char>(0xBF)] = 0x0457;
    }

    ~codecvt_cp1251()
    {
    }


protected:


  virtual result do_in(mbstate_t&,
                       const char* from,
                       const char* from_end,
                       const char* &from_next,
                       wchar_t* to,
                       wchar_t* to_end,
                       wchar_t* &to_next)
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
      if(static_cast<unsigned char>(*from) <= 0x7F)
      {
        *to = static_cast<wchar_t>(*from);
      }
      else if(0xC0 <= static_cast<unsigned char>(*from)
                   && static_cast<unsigned char>(*from) <=0xFF)
      {
        *to = static_cast<wchar_t>(
                static_cast<unsigned char>(*from) + 0x350);
      }
      else
      {
        typename std::map<char, wchar_t>::const_iterator s;
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


  virtual result do_out(mbstate_t&,
                        const wchar_t* from,
                        const wchar_t* from_end,
                        const wchar_t* &from_next,
                        char* to,
                        char* to_end,
                        char* &to_next)
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
        *to = static_cast<unsigned char>(*from);
      }
      else if(0x410 <= static_cast<unsigned char>(*from)
                    && static_cast<unsigned char>(*from) <=0x44F)
      {
        *to = static_cast<char>(static_cast<wchar_t>(*from) - 0x350);
      }
      else
      {
        typename std::map<wchar_t, char>::const_iterator s;
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
  std::map<char, wchar_t> in_tab;
  std::map<wchar_t, char> out_tab;

};

#endif // __CODECVT_CP1251__


#ifndef __CODECVT_CP1251_HPP__
#define __CODECVT_CP1251_HPP__

#include <locale>
#include <map>

/**@brief Facet is used to convert cyrillic char strings in cp1251
 * encoding into UNICODE*/
class codecvt_cp1251 : public std::codecvt<wchar_t, char, mbstate_t>
{
  public:

    typedef std::codecvt_base::result result;
    const result ok, partial, error, noconv;

    explicit codecvt_cp1251(size_t r=0)
      : std::codecvt<wchar_t, char, mbstate_t>(r),
        ok(std::codecvt_base::ok),
        partial(std::codecvt_base::partial),
        error(std::codecvt_base::error),
        noconv(std::codecvt_base::noconv)
    {
      // UNICODE -> CP1251 tab, extended part without alpha
<<<<<<< HEAD
      out_tab[0x0402] = 0x80;     in_tab[0x80] = 0x0402;
      out_tab[0x0403] = 0x81;     in_tab[0x81] = 0x0403;
      out_tab[0x201A] = 0x82;     in_tab[0x82] = 0x201A;
      out_tab[0x0453] = 0x83;     in_tab[0x83] = 0x0453;
      out_tab[0x201E] = 0x84;     in_tab[0x84] = 0x201E;
      out_tab[0x2026] = 0x85;     in_tab[0x85] = 0x2026;
      out_tab[0x2020] = 0x86;     in_tab[0x86] = 0x2020;
      out_tab[0x2021] = 0x87;     in_tab[0x87] = 0x2021;
      out_tab[0x20AC] = 0x88;     in_tab[0x88] = 0x20AC;
      out_tab[0x2030] = 0x89;     in_tab[0x89] = 0x2030;
      out_tab[0x0409] = 0x8A;     in_tab[0x8A] = 0x0409;
      out_tab[0x2039] = 0x8B;     in_tab[0x8B] = 0x2039;
      out_tab[0x040A] = 0x8C;     in_tab[0x8C] = 0x040A;
      out_tab[0x040C] = 0x8D;     in_tab[0x8D] = 0x040C;
      out_tab[0x040B] = 0x8E;     in_tab[0x8E] = 0x040B;
      out_tab[0x040F] = 0x8F;     in_tab[0x8F] = 0x040F;
      out_tab[0x0452] = 0x90;     in_tab[0x90] = 0x0452;
      out_tab[0x2018] = 0x91;     in_tab[0x91] = 0x2018;
      out_tab[0x2019] = 0x92;     in_tab[0x92] = 0x2019;
      out_tab[0x201C] = 0x93;     in_tab[0x93] = 0x201C;
      out_tab[0x201D] = 0x94;     in_tab[0x94] = 0x201D;
      out_tab[0x2022] = 0x95;     in_tab[0x95] = 0x2022;
      out_tab[0x2013] = 0x96;     in_tab[0x96] = 0x2013;
      out_tab[0x2014] = 0x97;     in_tab[0x97] = 0x2014;
      //out_tab[    ] = 0x98;   //in_tab[0x98] =     ;  
      out_tab[0x2122] = 0x99;     in_tab[0x99] = 0x2122;
      out_tab[0x0459] = 0x9A;     in_tab[0x9A] = 0x0459;
      out_tab[0x203A] = 0x9B;     in_tab[0x9B] = 0x203A;
      out_tab[0x045A] = 0x9C;     in_tab[0x9C] = 0x045A;
      out_tab[0x045C] = 0x9D;     in_tab[0x9D] = 0x045C;
      out_tab[0x045B] = 0x9E;     in_tab[0x9E] = 0x045B;
      out_tab[0x045F] = 0x9F;     in_tab[0x9F] = 0x045F;
      out_tab[0x00A0] = 0xA0;     in_tab[0xA0] = 0x00A0;
      out_tab[0x040E] = 0xA1;     in_tab[0xA1] = 0x040E;
      out_tab[0x045E] = 0xA2;     in_tab[0xA2] = 0x045E;
      out_tab[0x0408] = 0xA3;     in_tab[0xA3] = 0x0408;
      out_tab[0x00A4] = 0xA4;     in_tab[0xA4] = 0x00A4;
      out_tab[0x0490] = 0xA5;     in_tab[0xA5] = 0x0490;
      out_tab[0x00A6] = 0xA6;     in_tab[0xA6] = 0x00A6;
      out_tab[0x00A7] = 0xA7;     in_tab[0xA7] = 0x00A7;
      out_tab[0x0401] = 0xA8;     in_tab[0xA8] = 0x0401;
      out_tab[0x00A9] = 0xA9;     in_tab[0xA9] = 0x00A9;
      out_tab[0x0404] = 0xAA;     in_tab[0xAA] = 0x0404;
      out_tab[0x00AB] = 0xAB;     in_tab[0xAB] = 0x00AB;
      out_tab[0x00AC] = 0xAC;     in_tab[0xAC] = 0x00AC;
      out_tab[0x00AD] = 0xAD;     in_tab[0xAD] = 0x00AD;
      out_tab[0x00AE] = 0xAE;     in_tab[0xAE] = 0x00AE;
      out_tab[0x0407] = 0xAF;     in_tab[0xAF] = 0x0407;
      out_tab[0x00B0] = 0xB0;     in_tab[0xB0] = 0x00B0;
      out_tab[0x00B1] = 0xB1;     in_tab[0xB1] = 0x00B1;
      out_tab[0x0406] = 0xB2;     in_tab[0xB2] = 0x0406;
      out_tab[0x0456] = 0xB3;     in_tab[0xB3] = 0x0456;
      out_tab[0x0491] = 0xB4;     in_tab[0xB4] = 0x0491;
      out_tab[0x00B5] = 0xB5;     in_tab[0xB5] = 0x00B5;
      out_tab[0x00B6] = 0xB6;     in_tab[0xB6] = 0x00B6;
      out_tab[0x00B7] = 0xB7;     in_tab[0xB7] = 0x00B7;
      out_tab[0x0451] = 0xB8;     in_tab[0xB8] = 0x0451;
      out_tab[0x2116] = 0xB9;     in_tab[0xB9] = 0x2116;
      out_tab[0x0454] = 0xBA;     in_tab[0xBA] = 0x0454;
      out_tab[0x00BB] = 0xBB;     in_tab[0xBB] = 0x00BB;
      out_tab[0x0458] = 0xBC;     in_tab[0xBC] = 0x0458;
      out_tab[0x0405] = 0xBD;     in_tab[0xBD] = 0x0405;
      out_tab[0x0455] = 0xBE;     in_tab[0xBE] = 0x0455;
      out_tab[0x0457] = 0xBF;     in_tab[0xBF] = 0x0457;
=======
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
>>>>>>> 76915525ccfd763c294d5b178d4662633dc6de14
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
<<<<<<< HEAD
      const unsigned char ufrom = static_cast<unsigned char>(*from);
      // ASCII
      if(ufrom <= 0x7F)
        *to = static_cast<wchar_t>(*from);
      else if(0xC0 <= ufrom)
        *to = static_cast<wchar_t>(ufrom + 0x350);
      else
      {
        std::map<unsigned char, wchar_t>::const_iterator s;
        s = in_tab.lower_bound(ufrom);
        if(s->first != ufrom || s == in_tab.end())
        {
=======
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
        std::map<char, wchar_t>::const_iterator s;
        s = in_tab.lower_bound(*from);
        if(s->first != *from || s == in_tab.end())
        {
          // ok from and to is not endings
>>>>>>> 76915525ccfd763c294d5b178d4662633dc6de14
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
<<<<<<< HEAD
        *to = static_cast<unsigned char>(*from);
      else if(0x410 <= *from && *from <=0x44F)
        *to = static_cast<unsigned char>(*from - 0x350);
      else
      {
        std::map<wchar_t, unsigned char>::const_iterator s;
=======
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
        std::map<wchar_t, char>::const_iterator s;
>>>>>>> 76915525ccfd763c294d5b178d4662633dc6de14
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
<<<<<<< HEAD
  std::map<unsigned char, wchar_t> in_tab;
  std::map<wchar_t, unsigned char> out_tab;
=======
  std::map<char, wchar_t> in_tab;
  std::map<wchar_t, char> out_tab;
>>>>>>> 76915525ccfd763c294d5b178d4662633dc6de14

};

#endif // __CODECVT_CP1251__


#ifndef __CODECVT_CP866_HPP__
#define __CODECVT_CP866_HPP__

#include <locale>
#include <map>

/**@brief Facet is used to convert ciryllic char strings in cp866
 * encodings into UNICODE*/
class codecvt_cp866 : public std::codecvt<wchar_t, char, mbstate_t>
{
  public:

    typedef std::codecvt_base::result result;
    const result ok, partial, error, noconv;

    explicit codecvt_cp866(size_t r=0)
      : std::codecvt<wchar_t, char, mbstate_t>(r),
        ok(std::codecvt_base::ok),
        partial(std::codecvt_base::partial),
        error(std::codecvt_base::error),
        noconv(std::codecvt_base::noconv)
    {
      //  UNICODE -> CP866 table (extended part)
<<<<<<< HEAD
      out_tab[0x2591] = 0xb0;   in_tab[0xb0] = 0x2591;
      out_tab[0x2592] = 0xb1;   in_tab[0xb1] = 0x2592;
      out_tab[0x2593] = 0xb2;   in_tab[0xb2] = 0x2593;
      out_tab[0x2502] = 0xb3;   in_tab[0xb3] = 0x2502;
      out_tab[0x2524] = 0xb4;   in_tab[0xb4] = 0x2524;
      out_tab[0x2561] = 0xb5;   in_tab[0xb5] = 0x2561;
      out_tab[0x2562] = 0xb6;   in_tab[0xb6] = 0x2562;
      out_tab[0x2556] = 0xb7;   in_tab[0xb7] = 0x2556;
      out_tab[0x2555] = 0xb8;   in_tab[0xb8] = 0x2555;
      out_tab[0x2563] = 0xb9;   in_tab[0xb9] = 0x2563;
      out_tab[0x2551] = 0xba;   in_tab[0xba] = 0x2551;
      out_tab[0x2557] = 0xbb;   in_tab[0xbb] = 0x2557;
      out_tab[0x255d] = 0xbc;   in_tab[0xbc] = 0x255d;
      out_tab[0x255c] = 0xbd;   in_tab[0xbd] = 0x255c;
      out_tab[0x255b] = 0xbe;   in_tab[0xbe] = 0x255b;
      out_tab[0x2510] = 0xbf;   in_tab[0xbf] = 0x2510;
      out_tab[0x2514] = 0xc0;   in_tab[0xc0] = 0x2514;
      out_tab[0x2534] = 0xc1;   in_tab[0xc1] = 0x2534;
      out_tab[0x252c] = 0xc2;   in_tab[0xc2] = 0x252c;
      out_tab[0x251c] = 0xc3;   in_tab[0xc3] = 0x251c;
      out_tab[0x2500] = 0xc4;   in_tab[0xc4] = 0x2500;
      out_tab[0x253c] = 0xc5;   in_tab[0xc5] = 0x253c;
      out_tab[0x255e] = 0xc6;   in_tab[0xc6] = 0x255e;
      out_tab[0x255f] = 0xc7;   in_tab[0xc7] = 0x255f;
      out_tab[0x255a] = 0xc8;   in_tab[0xc8] = 0x255a;
      out_tab[0x2554] = 0xc9;   in_tab[0xc9] = 0x2554;
      out_tab[0x2569] = 0xca;   in_tab[0xca] = 0x2569;
      out_tab[0x2566] = 0xcb;   in_tab[0xcb] = 0x2566;
      out_tab[0x2560] = 0xcc;   in_tab[0xcc] = 0x2560;
      out_tab[0x2550] = 0xcd;   in_tab[0xcd] = 0x2550;
      out_tab[0x256c] = 0xce;   in_tab[0xce] = 0x256c;
      out_tab[0x2567] = 0xcf;   in_tab[0xcf] = 0x2567;
      out_tab[0x2568] = 0xd0;   in_tab[0xd0] = 0x2568;
      out_tab[0x2564] = 0xd1;   in_tab[0xd1] = 0x2564;
      out_tab[0x2565] = 0xd2;   in_tab[0xd2] = 0x2565;
      out_tab[0x2559] = 0xd3;   in_tab[0xd3] = 0x2559;
      out_tab[0x2558] = 0xd4;   in_tab[0xd4] = 0x2558;
      out_tab[0x2552] = 0xd5;   in_tab[0xd5] = 0x2552;
      out_tab[0x2553] = 0xd6;   in_tab[0xd6] = 0x2553;
      out_tab[0x256b] = 0xd7;   in_tab[0xd7] = 0x256b;
      out_tab[0x256a] = 0xd8;   in_tab[0xd8] = 0x256a;
      out_tab[0x2518] = 0xd9;   in_tab[0xd9] = 0x2518;
      out_tab[0x250c] = 0xda;   in_tab[0xda] = 0x250c;
      out_tab[0x2588] = 0xdb;   in_tab[0xdb] = 0x2588;
      out_tab[0x2584] = 0xdc;   in_tab[0xdc] = 0x2584;
      out_tab[0x258c] = 0xdd;   in_tab[0xdd] = 0x258c;
      out_tab[0x2590] = 0xde;   in_tab[0xde] = 0x2590;
      out_tab[0x2580] = 0xdf;   in_tab[0xdf] = 0x2580;
      out_tab[0x0401] = 0xf0;   in_tab[0xf0] = 0x0401;
      out_tab[0x0451] = 0xf1;   in_tab[0xf1] = 0x0451;
      out_tab[0x0404] = 0xf2;   in_tab[0xf2] = 0x0404;
      out_tab[0x0454] = 0xf3;   in_tab[0xf3] = 0x0454;
      out_tab[0x0407] = 0xf4;   in_tab[0xf4] = 0x0407;
      out_tab[0x0457] = 0xf5;   in_tab[0xf5] = 0x0457;
      out_tab[0x040e] = 0xf6;   in_tab[0xf6] = 0x040e;
      out_tab[0x045e] = 0xf7;   in_tab[0xf7] = 0x045e;
      out_tab[0x00b0] = 0xf8;   in_tab[0xf8] = 0x00b0;
      out_tab[0x2219] = 0xf9;   in_tab[0xf9] = 0x2219;
      out_tab[0x00b7] = 0xfa;   in_tab[0xfa] = 0x00b7;
      out_tab[0x221a] = 0xfb;   in_tab[0xfb] = 0x221a;
      out_tab[0x2116] = 0xfc;   in_tab[0xfc] = 0x2116;
      out_tab[0x00a4] = 0xfd;   in_tab[0xfd] = 0x00a4;
      out_tab[0x25a0] = 0xfe;   in_tab[0xfe] = 0x25a0;
      out_tab[0x00a0] = 0xff;   in_tab[0xff] = 0x00a0;
=======
      out_tab[0x2591] = static_cast<unsigned char>(0xb0);
      out_tab[0x2592] = static_cast<unsigned char>(0xb1);
      out_tab[0x2593] = static_cast<unsigned char>(0xb2);
      out_tab[0x2502] = static_cast<unsigned char>(0xb3);
      out_tab[0x2524] = static_cast<unsigned char>(0xb4);
      out_tab[0x2561] = static_cast<unsigned char>(0xb5);
      out_tab[0x2562] = static_cast<unsigned char>(0xb6);
      out_tab[0x2556] = static_cast<unsigned char>(0xb7);
      out_tab[0x2555] = static_cast<unsigned char>(0xb8);
      out_tab[0x2563] = static_cast<unsigned char>(0xb9);
      out_tab[0x2551] = static_cast<unsigned char>(0xba);
      out_tab[0x2557] = static_cast<unsigned char>(0xbb);
      out_tab[0x255d] = static_cast<unsigned char>(0xbc);
      out_tab[0x255c] = static_cast<unsigned char>(0xbd);
      out_tab[0x255b] = static_cast<unsigned char>(0xbe);
      out_tab[0x2510] = static_cast<unsigned char>(0xbf);
      out_tab[0x2514] = static_cast<unsigned char>(0xc0);
      out_tab[0x2534] = static_cast<unsigned char>(0xc1);
      out_tab[0x252c] = static_cast<unsigned char>(0xc2);
      out_tab[0x251c] = static_cast<unsigned char>(0xc3);
      out_tab[0x2500] = static_cast<unsigned char>(0xc4);
      out_tab[0x253c] = static_cast<unsigned char>(0xc5);
      out_tab[0x255e] = static_cast<unsigned char>(0xc6);
      out_tab[0x255f] = static_cast<unsigned char>(0xc7);
      out_tab[0x255a] = static_cast<unsigned char>(0xc8);
      out_tab[0x2554] = static_cast<unsigned char>(0xc9);
      out_tab[0x2569] = static_cast<unsigned char>(0xca);
      out_tab[0x2566] = static_cast<unsigned char>(0xcb);
      out_tab[0x2560] = static_cast<unsigned char>(0xcc);
      out_tab[0x2550] = static_cast<unsigned char>(0xcd);
      out_tab[0x256c] = static_cast<unsigned char>(0xce);
      out_tab[0x2567] = static_cast<unsigned char>(0xcf);
      out_tab[0x2568] = static_cast<unsigned char>(0xd0);
      out_tab[0x2564] = static_cast<unsigned char>(0xd1);
      out_tab[0x2565] = static_cast<unsigned char>(0xd2);
      out_tab[0x2559] = static_cast<unsigned char>(0xd3);
      out_tab[0x2558] = static_cast<unsigned char>(0xd4);
      out_tab[0x2552] = static_cast<unsigned char>(0xd5);
      out_tab[0x2553] = static_cast<unsigned char>(0xd6);
      out_tab[0x256b] = static_cast<unsigned char>(0xd7);
      out_tab[0x256a] = static_cast<unsigned char>(0xd8);
      out_tab[0x2518] = static_cast<unsigned char>(0xd9);
      out_tab[0x250c] = static_cast<unsigned char>(0xda);
      out_tab[0x2588] = static_cast<unsigned char>(0xdb);
      out_tab[0x2584] = static_cast<unsigned char>(0xdc);
      out_tab[0x258c] = static_cast<unsigned char>(0xdd);
      out_tab[0x2590] = static_cast<unsigned char>(0xde);
      out_tab[0x2580] = static_cast<unsigned char>(0xdf);
      out_tab[0x0401] = static_cast<unsigned char>(0xf0);
      out_tab[0x0451] = static_cast<unsigned char>(0xf1);
      out_tab[0x0404] = static_cast<unsigned char>(0xf2);
      out_tab[0x0454] = static_cast<unsigned char>(0xf3);
      out_tab[0x0407] = static_cast<unsigned char>(0xf4);
      out_tab[0x0457] = static_cast<unsigned char>(0xf5);
      out_tab[0x040e] = static_cast<unsigned char>(0xf6);
      out_tab[0x045e] = static_cast<unsigned char>(0xf7);
      out_tab[0x00b0] = static_cast<unsigned char>(0xf8);
      out_tab[0x2219] = static_cast<unsigned char>(0xf9);
      out_tab[0x00b7] = static_cast<unsigned char>(0xfa);
      out_tab[0x221a] = static_cast<unsigned char>(0xfb);
      out_tab[0x2116] = static_cast<unsigned char>(0xfc);
      out_tab[0x00a4] = static_cast<unsigned char>(0xfd);
      out_tab[0x25a0] = static_cast<unsigned char>(0xfe);
      out_tab[0x00a0] = static_cast<unsigned char>(0xff);
      // CP866 -> UNICODE extended part
      in_tab[static_cast<unsigned char>(0xb0)] = 0x2591;
      in_tab[static_cast<unsigned char>(0xb1)] = 0x2592;
      in_tab[static_cast<unsigned char>(0xb2)] = 0x2593;
      in_tab[static_cast<unsigned char>(0xb3)] = 0x2502;
      in_tab[static_cast<unsigned char>(0xb4)] = 0x2524;
      in_tab[static_cast<unsigned char>(0xb5)] = 0x2561;
      in_tab[static_cast<unsigned char>(0xb6)] = 0x2562;
      in_tab[static_cast<unsigned char>(0xb7)] = 0x2556;
      in_tab[static_cast<unsigned char>(0xb8)] = 0x2555;
      in_tab[static_cast<unsigned char>(0xb9)] = 0x2563;
      in_tab[static_cast<unsigned char>(0xba)] = 0x2551;
      in_tab[static_cast<unsigned char>(0xbb)] = 0x2557;
      in_tab[static_cast<unsigned char>(0xbc)] = 0x255d;
      in_tab[static_cast<unsigned char>(0xbd)] = 0x255c;
      in_tab[static_cast<unsigned char>(0xbe)] = 0x255b;
      in_tab[static_cast<unsigned char>(0xbf)] = 0x2510;
      in_tab[static_cast<unsigned char>(0xc0)] = 0x2514;
      in_tab[static_cast<unsigned char>(0xc1)] = 0x2534;
      in_tab[static_cast<unsigned char>(0xc2)] = 0x252c;
      in_tab[static_cast<unsigned char>(0xc3)] = 0x251c;
      in_tab[static_cast<unsigned char>(0xc4)] = 0x2500;
      in_tab[static_cast<unsigned char>(0xc5)] = 0x253c;
      in_tab[static_cast<unsigned char>(0xc6)] = 0x255e;
      in_tab[static_cast<unsigned char>(0xc7)] = 0x255f;
      in_tab[static_cast<unsigned char>(0xc8)] = 0x255a;
      in_tab[static_cast<unsigned char>(0xc9)] = 0x2554;
      in_tab[static_cast<unsigned char>(0xca)] = 0x2569;
      in_tab[static_cast<unsigned char>(0xcb)] = 0x2566;
      in_tab[static_cast<unsigned char>(0xcc)] = 0x2560;
      in_tab[static_cast<unsigned char>(0xcd)] = 0x2550;
      in_tab[static_cast<unsigned char>(0xce)] = 0x256c;
      in_tab[static_cast<unsigned char>(0xcf)] = 0x2567;
      in_tab[static_cast<unsigned char>(0xd0)] = 0x2568;
      in_tab[static_cast<unsigned char>(0xd1)] = 0x2564;
      in_tab[static_cast<unsigned char>(0xd2)] = 0x2565;
      in_tab[static_cast<unsigned char>(0xd3)] = 0x2559;
      in_tab[static_cast<unsigned char>(0xd4)] = 0x2558;
      in_tab[static_cast<unsigned char>(0xd5)] = 0x2552;
      in_tab[static_cast<unsigned char>(0xd6)] = 0x2553;
      in_tab[static_cast<unsigned char>(0xd7)] = 0x256b;
      in_tab[static_cast<unsigned char>(0xd8)] = 0x256a;
      in_tab[static_cast<unsigned char>(0xd9)] = 0x2518;
      in_tab[static_cast<unsigned char>(0xda)] = 0x250c;
      in_tab[static_cast<unsigned char>(0xdb)] = 0x2588;
      in_tab[static_cast<unsigned char>(0xdc)] = 0x2584;
      in_tab[static_cast<unsigned char>(0xdd)] = 0x258c;
      in_tab[static_cast<unsigned char>(0xde)] = 0x2590;
      in_tab[static_cast<unsigned char>(0xdf)] = 0x2580;
      in_tab[static_cast<unsigned char>(0xf0)] = 0x0401;
      in_tab[static_cast<unsigned char>(0xf1)] = 0x0451;
      in_tab[static_cast<unsigned char>(0xf2)] = 0x0404;
      in_tab[static_cast<unsigned char>(0xf3)] = 0x0454;
      in_tab[static_cast<unsigned char>(0xf4)] = 0x0407;
      in_tab[static_cast<unsigned char>(0xf5)] = 0x0457;
      in_tab[static_cast<unsigned char>(0xf6)] = 0x040e;
      in_tab[static_cast<unsigned char>(0xf7)] = 0x045e;
      in_tab[static_cast<unsigned char>(0xf8)] = 0x00b0;
      in_tab[static_cast<unsigned char>(0xf9)] = 0x2219;
      in_tab[static_cast<unsigned char>(0xfa)] = 0x00b7;
      in_tab[static_cast<unsigned char>(0xfb)] = 0x221a;
      in_tab[static_cast<unsigned char>(0xfc)] = 0x2116;
      in_tab[static_cast<unsigned char>(0xfd)] = 0x00a4;
      in_tab[static_cast<unsigned char>(0xfe)] = 0x25a0;
      in_tab[static_cast<unsigned char>(0xff)] = 0x00a0;
>>>>>>> 76915525ccfd763c294d5b178d4662633dc6de14
    }

    ~codecvt_cp866()
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
      else if(0x80 <= ufrom && ufrom <= 0xAF)
        *to = static_cast<wchar_t>(ufrom + 0x390);
      else if(0xE0 <= ufrom && ufrom <= 0xEF)
        *to = static_cast<wchar_t>(ufrom + 0x360);
      else
      {
        std::map<unsigned char, wchar_t>::const_iterator s;
        s = in_tab.lower_bound(ufrom);
        if(s->first != ufrom || s == in_tab.end())
=======
      // ASCII
      if(static_cast<unsigned char>(*from) <= 0x7F)
      {
        *to = static_cast<wchar_t>(*from);
      }
      else if(0x80 <= static_cast<unsigned char>(*from)
                   && static_cast<unsigned char>(*from) <=0xAF)
      {
        *to = static_cast<wchar_t>(
                static_cast<unsigned char>(*from) + 0x390);
      }
      else if(0xE0 <= static_cast<unsigned char>(*from)
                   && static_cast<unsigned char>(*from) <=0xEF)
      {
        *to = static_cast<wchar_t>(
                static_cast<unsigned char>(*from) + 0x360);
      }
      else
      {
        std::map<char, wchar_t>::const_iterator s;
        s = in_tab.lower_bound(*from);
        if(s->first != *from || s == in_tab.end())
>>>>>>> 76915525ccfd763c294d5b178d4662633dc6de14
        {
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
<<<<<<< HEAD
      if(0 <= *from && *from <= 0x7F)
        *to = static_cast<unsigned char>(*from);
      else if(0x410 <= *from && *from <= 0x43F)
        *to = static_cast<unsigned char>(*from - 0x390);
      else if(0x440 <= *from && *from <=0x44F)
        *to = static_cast<unsigned char>(*from - 0x360);
      else
      {
        std::map<wchar_t, unsigned char>::const_iterator s;
=======
      if(static_cast<unsigned char>(*from) <= 0x7F)
      {
        *to = static_cast<unsigned char>(*from);
      }
      else if(0x410 <= *from
                    && *from <= 0x43F)
      {
        *to = static_cast<char>(*from - 0x390);
      }
      else if(0x440 <= *from
                    && *from <=0x44F)
      {
        *to = static_cast<char>(*from - 0x360);
      }
      else
      {
        std::map<wchar_t, char>::const_iterator s;
>>>>>>> 76915525ccfd763c294d5b178d4662633dc6de14
        s = out_tab.lower_bound(*from);
        if(s->first != *from || s == out_tab.end())
        {
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

#endif // __CODECVT_CP866__


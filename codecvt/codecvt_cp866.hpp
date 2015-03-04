/**@author hoxnox <hoxnox@gmail.com>
 * @copyright (c) 2010 hoxnox <hoxnox@gmail.com>
 * @license LGPL
 * @brief Codecvt cp866 facet implementation.
 * 
 * This file is a part of hoxnox's facets project*/

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
        from_next = from;
        to_next = to;
        return partial;
      }
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
        from_next = from;
        to_next = to;
        return partial;
      }
      if(0 <= *from && *from <= 0x7F)
        *to = static_cast<unsigned char>(*from);
      else if(0x410 <= *from && *from <= 0x43F)
        *to = static_cast<unsigned char>(*from - 0x390);
      else if(0x440 <= *from && *from <=0x44F)
        *to = static_cast<unsigned char>(*from - 0x360);
      else
      {
        std::map<wchar_t, unsigned char>::const_iterator s;
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
  std::map<unsigned char, wchar_t> in_tab;
  std::map<wchar_t, unsigned char> out_tab;
};

#endif // __CODECVT_CP866__


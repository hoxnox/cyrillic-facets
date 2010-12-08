#ifndef __CODECVT_CP866_HPP__
#define __CODECVT_CP866_HPP__

#include <locale>
#include <map>

/**@brief Facet is used to convert ciryllic char strings in cp866 
 * encodings into UNICODE*/
template<class I, class E, class State>
class codecvt_cp866 : public std::codecvt<I, E, State>
{
  public:

    typedef typename std::codecvt_base::result result;
    const result ok, partial, error, noconv;

    explicit codecvt_cp866(size_t r=0)
      : std::codecvt<I, E, State>(r),
        ok(std::codecvt_base::ok),
        partial(std::codecvt_base::partial),
        error(std::codecvt_base::error),
        noconv(std::codecvt_base::noconv)
    {
      in_tab[(unsigned)0xb0] = 0x2591; out_tab[0x2591] = (unsigned)0xb0;
      in_tab[(unsigned)0xb1] = 0x2592; out_tab[0x2592] = (unsigned)0xb1;
      in_tab[(unsigned)0xb2] = 0x2593; out_tab[0x2593] = (unsigned)0xb2;
      in_tab[(unsigned)0xb3] = 0x2502; out_tab[0x2502] = (unsigned)0xb3;
      in_tab[(unsigned)0xb4] = 0x2524; out_tab[0x2524] = (unsigned)0xb4;
      in_tab[(unsigned)0xb5] = 0x2561; out_tab[0x2561] = (unsigned)0xb5;
      in_tab[(unsigned)0xb6] = 0x2562; out_tab[0x2562] = (unsigned)0xb6;
      in_tab[(unsigned)0xb7] = 0x2556; out_tab[0x2556] = (unsigned)0xb7;
      in_tab[(unsigned)0xb8] = 0x2555; out_tab[0x2555] = (unsigned)0xb8;
      in_tab[(unsigned)0xb9] = 0x2563; out_tab[0x2563] = (unsigned)0xb9;
      in_tab[(unsigned)0xba] = 0x2551; out_tab[0x2551] = (unsigned)0xba;
      in_tab[(unsigned)0xbb] = 0x2557; out_tab[0x2557] = (unsigned)0xbb;
      in_tab[(unsigned)0xbc] = 0x255d; out_tab[0x255d] = (unsigned)0xbc;
      in_tab[(unsigned)0xbd] = 0x255c; out_tab[0x255c] = (unsigned)0xbd;
      in_tab[(unsigned)0xbe] = 0x255b; out_tab[0x255b] = (unsigned)0xbe;
      in_tab[(unsigned)0xbf] = 0x2510; out_tab[0x2510] = (unsigned)0xbf;
      in_tab[(unsigned)0xc0] = 0x2514; out_tab[0x2514] = (unsigned)0xc0;
      in_tab[(unsigned)0xc1] = 0x2534; out_tab[0x2534] = (unsigned)0xc1;
      in_tab[(unsigned)0xc2] = 0x252c; out_tab[0x252c] = (unsigned)0xc2;
      in_tab[(unsigned)0xc3] = 0x251c; out_tab[0x251c] = (unsigned)0xc3;
      in_tab[(unsigned)0xc4] = 0x2500; out_tab[0x2500] = (unsigned)0xc4;
      in_tab[(unsigned)0xc5] = 0x253c; out_tab[0x253c] = (unsigned)0xc5;
      in_tab[(unsigned)0xc6] = 0x255e; out_tab[0x255e] = (unsigned)0xc6;
      in_tab[(unsigned)0xc7] = 0x255f; out_tab[0x255f] = (unsigned)0xc7;
      in_tab[(unsigned)0xc8] = 0x255a; out_tab[0x255a] = (unsigned)0xc8;
      in_tab[(unsigned)0xc9] = 0x2554; out_tab[0x2554] = (unsigned)0xc9;
      in_tab[(unsigned)0xca] = 0x2569; out_tab[0x2569] = (unsigned)0xca;
      in_tab[(unsigned)0xcb] = 0x2566; out_tab[0x2566] = (unsigned)0xcb;
      in_tab[(unsigned)0xcc] = 0x2560; out_tab[0x2560] = (unsigned)0xcc;
      in_tab[(unsigned)0xcd] = 0x2550; out_tab[0x2550] = (unsigned)0xcd;
      in_tab[(unsigned)0xce] = 0x256c; out_tab[0x256c] = (unsigned)0xce;
      in_tab[(unsigned)0xcf] = 0x2567; out_tab[0x2567] = (unsigned)0xcf;
      in_tab[(unsigned)0xd0] = 0x2568; out_tab[0x2568] = (unsigned)0xd0;
      in_tab[(unsigned)0xd1] = 0x2564; out_tab[0x2564] = (unsigned)0xd1;
      in_tab[(unsigned)0xd2] = 0x2565; out_tab[0x2565] = (unsigned)0xd2;
      in_tab[(unsigned)0xd3] = 0x2559; out_tab[0x2559] = (unsigned)0xd3;
      in_tab[(unsigned)0xd4] = 0x2558; out_tab[0x2558] = (unsigned)0xd4;
      in_tab[(unsigned)0xd5] = 0x2552; out_tab[0x2552] = (unsigned)0xd5;
      in_tab[(unsigned)0xd6] = 0x2553; out_tab[0x2553] = (unsigned)0xd6;
      in_tab[(unsigned)0xd7] = 0x256b; out_tab[0x256b] = (unsigned)0xd7;
      in_tab[(unsigned)0xd8] = 0x256a; out_tab[0x256a] = (unsigned)0xd8;
      in_tab[(unsigned)0xd9] = 0x2518; out_tab[0x2518] = (unsigned)0xd9;
      in_tab[(unsigned)0xda] = 0x250c; out_tab[0x250c] = (unsigned)0xda;
      in_tab[(unsigned)0xdb] = 0x2588; out_tab[0x2588] = (unsigned)0xdb;
      in_tab[(unsigned)0xdc] = 0x2584; out_tab[0x2584] = (unsigned)0xdc;
      in_tab[(unsigned)0xdd] = 0x258c; out_tab[0x258c] = (unsigned)0xdd;
      in_tab[(unsigned)0xde] = 0x2590; out_tab[0x2590] = (unsigned)0xde;
      in_tab[(unsigned)0xdf] = 0x2580; out_tab[0x2580] = (unsigned)0xdf;
      in_tab[(unsigned)0xf0] = 0x0401; out_tab[0x0401] = (unsigned)0xf0;
      in_tab[(unsigned)0xf1] = 0x0451; out_tab[0x0451] = (unsigned)0xf1;
      in_tab[(unsigned)0xf2] = 0x0404; out_tab[0x0404] = (unsigned)0xf2;
      in_tab[(unsigned)0xf3] = 0x0454; out_tab[0x0454] = (unsigned)0xf3;
      in_tab[(unsigned)0xf4] = 0x0407; out_tab[0x0407] = (unsigned)0xf4;
      in_tab[(unsigned)0xf5] = 0x0457; out_tab[0x0457] = (unsigned)0xf5;
      in_tab[(unsigned)0xf6] = 0x040e; out_tab[0x040e] = (unsigned)0xf6;
      in_tab[(unsigned)0xf7] = 0x045e; out_tab[0x045e] = (unsigned)0xf7;
      in_tab[(unsigned)0xf8] = 0x00b0; out_tab[0x00b0] = (unsigned)0xf8;
      in_tab[(unsigned)0xf9] = 0x2219; out_tab[0x2219] = (unsigned)0xf9;
      in_tab[(unsigned)0xfa] = 0x00b7; out_tab[0x00b7] = (unsigned)0xfa;
      in_tab[(unsigned)0xfb] = 0x221a; out_tab[0x221a] = (unsigned)0xfb;
      in_tab[(unsigned)0xfc] = 0x2116; out_tab[0x2116] = (unsigned)0xfc;
      in_tab[(unsigned)0xfd] = 0x00a4; out_tab[0x00a4] = (unsigned)0xfd;
      in_tab[(unsigned)0xfe] = 0x25a0; out_tab[0x25a0] = (unsigned)0xfe;
      in_tab[(unsigned)0xff] = 0x00a0; out_tab[0x00a0] = (unsigned)0xff;
    }

    ~codecvt_cp866()
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
      else if(0x80 <= (unsigned)(*from)
                   && (unsigned)(*from) <=0xAF)
      {
        *to = static_cast<I>((unsigned)(*from) + 0x390);
      }
      else if(0xE0 <= (unsigned)(*from)
                   && (unsigned)(*from) <=0xEF)
      {
        *to = static_cast<I>((unsigned)(*from) + 0x360);
      }
      else
      {
        typename std::map<E, I>::const_iterator s;
        s = in_tab.lower_bound(*from);
        if(s->first != *from || s == in_tab.end())
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
      if((unsigned)*from <= 0x7F)
      {
        *to = (unsigned)(*from);
      }
      else if(0x410 <= *from
                    && *from <= 0x43F)
      {
        *to = static_cast<E>(*from - 0x390);
      }
      else if(0x440 <= *from
                    && *from <=0x44F)
      {
        *to = static_cast<E>(*from - 0x360);
      }
      else
      {
        typename std::map<I, E>::const_iterator s;
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
  std::map<E, I> in_tab;
  std::map<I, E> out_tab;

};

#endif // __CODECVT_CP866__


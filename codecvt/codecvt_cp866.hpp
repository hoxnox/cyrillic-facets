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
      // extended cyrillic
      in_tab[0xF0] = 0x401;  out_tab[0x401] = 0xF0;
      in_tab[0xF1] = 0x451;  out_tab[0x451] = 0xF1;
      in_tab[0xF2] = 0x404;  out_tab[0x404] = 0xF2;
      in_tab[0xF3] = 0x454;  out_tab[0x454] = 0xF3;
      in_tab[0xF4] = 0x407;  out_tab[0x407] = 0xF4;
      in_tab[0xF5] = 0x457;  out_tab[0x457] = 0xF5;
      in_tab[0xF6] = 0x40E;  out_tab[0x40E] = 0xF6;
      in_tab[0xF7] = 0x45E;  out_tab[0x45E] = 0xF7;
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
      if(0 <= *from && *from <= 0x7F)
      {
        *to = static_cast<I>(*from);
      }
      else if(0x80 <= static_cast<unsigned char>(*from)
                   && static_cast<unsigned char>(*from) <=0xAF)
      {
        *to = static_cast<I>(static_cast<unsigned char>(*from) + 0x390);
      }
      else if(0xE0 <= static_cast<unsigned char>(*from)
                   && static_cast<unsigned char>(*from) <=0xEF)
      {
        *to = static_cast<I>(static_cast<unsigned char>(*from) + 0x360);
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
      if(0 <= *from && *from <= 0x7F)
      {
        *to = static_cast<unsigned char>(*from);
      }
      else if(0x410 <= static_cast<wchar_t>(*from)
                    && static_cast<wchar_t>(*from) <= 0x43F)
      {
        *to = static_cast<char>(static_cast<wchar_t>(*from) - 0x390);
      }
      else if(0x440 <= static_cast<wchar_t>(*from)
                    && static_cast<wchar_t>(*from) <=0x44F)
      {
        *to = static_cast<char>(static_cast<wchar_t>(*from) - 0x360);
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


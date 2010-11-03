#include <locale>

using namespace std;

template<class I, class E, class State>
class codecvt_CP866 : public codecvt<I, E, State>
{
  public:

    typedef typename codecvt_base::result result;
    const result ok, partial, error, noconv;

    explicit codecvt_CP866(size_t r=0)
      : codecvt<I, E, State>(r),
        ok(codecvt_base::ok),
        partial(codecvt_base::partial),
        error(codecvt_base::error),
        noconv(codecvt_base::noconv)
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

    ~codecvt_CP866()
    {
    }

private:
  virtual result do_in(State&,
               const E* from, const E* from_end, const E* &from_next,
               I* to, I* to_end, I* &to_next)
    const
  {
    return ok;
  }

  virtual result do_out(State&,
                const I* from, const I* from_end, const I* &from_next,
                E* to, E* to_end, E* &to_next)
    const
  {

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
  virtual int do_length(const mbstate_t&, const char* from, const char* from_end, size_t max) const
  {
    return 0;
  }

  virtual int do_max_length() const throw()
  {
    return 0;
  }*/
private:
  map<E, I> in_tab;
  map<I, E> out_tab;
};




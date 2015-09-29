/**@copyright (c) 2010 hoxnox <hoxnox@gmail.com>
 * @license LGPL
 * @brief utf8->wchar wchar->utf8
 *
 * This file is a part of hoxnox's facets project
 *
 * This header contains C++ style functions, used to convert between
 * multibyte and wide chracter strings. You must know the size of strings
 * for using C-style mbstowcs and wcstombs. In this case you can use any
 * container you want:
 * @code
 *  std::string str;
 *  std::vector<wchar_t> wstr;
 *  if(wcstombs(str.begin(), str.end(), 
 *              std::back_inserter(wstr)) != str.end())
 *    // error converting;
 * @endcode*/

#ifndef __MBWCVT_HPP__
#define __MBWCVT_HPP__

/**@brief Translate unicode wide character sequence into byte sequence in
 * UTF-8 encoding*/
template <class input_iterator, class output_iterator>
input_iterator wcstombs(const input_iterator& b,
                        const input_iterator& e,
                        output_iterator o)
{
  typedef typename
    std::iterator_traits<input_iterator>::value_type intype;
  typedef typename
    std::iterator_traits<output_iterator>::value_type outtype;
  input_iterator i(b);
  while(i!=e)
  {
    if(0 <= *i && *i <= 0x7F)
    {
        *o = (char)*i;
    }
    else if(0x80 <= *i && *i <=0x7FF)
    {
         *o = 0xC0 + *i/0x40;
      *(++o) = 0x80 + *i%0x40;
    }
    else if(0x800 <= *i && *i <= 0xFFFF)
    {
         *o = 0xE0 + *i/(0x40*0x40);
      *(++o) = 0x80 + (*i%(0x40*0x40))/0x40;
      *(++o) = 0x80 + *i%0x40;
    }
    else if(0x10000 <= *i && *i <= 0x1FFFFF)
    {
         *o = 0xF0 + *i/(0x40*0x40*0x40);
      *(++o) = 0x80 + (*i%(0x40*0x40*0x40))/(0x40*0x40);
      *(++o) = 0x80 + (*i%(0x40*0x40))/0x40;
      *(++o) = 0x80 + *i%0x40;
    }
    ++i;
  }
  return i;
}

/**@brief Translate byte squence in UTF-8 encoding into wide character
 * unicode sequence*/
template <class input_iterator, class output_iterator>
input_iterator mbstowcs(input_iterator b,
                        input_iterator e,
                        output_iterator o)
{
  input_iterator i = b;
  while(i != e)
  {
    typedef
      typename std::iterator_traits<input_iterator>::value_type Char;
    typedef
      typename std::iterator_traits<output_iterator>::value_type WChar;
    typedef unsigned char UChar;

    if(0x0 <= static_cast<UChar>(*i) && static_cast<UChar>(*i) <= 0x7F)
    {
      *o = static_cast<UChar>(*i);
    }
    else if(static_cast<UChar>(*i)/0x20 == 0x6) // meet 110xxxxx byte
    {
      /* TODO
      if(sizeof(WChar) < 2*sizeof(Char))
        return;                   // error
      */
      Char first;
      first = static_cast<UChar>(*i) - 0xC0;
      if( ++i == e )              // error
        return i;
      *o = first*0x40 + (static_cast<UChar>(*i) - 0x80);
    }
    else if(static_cast<UChar>(*i)/0x10 == 0xE)  // meet 1110xxxx byte
    {
      /* TODO
      if(sizeof(WChar) < 3*sizeof(Char))
        return;                   // error
      */
      Char first, second;
      first = static_cast<UChar>(*i) - 0xE0;
      if( ++i == e )
        return i;
      second = static_cast<UChar>(*i) - 0x80;
      *o = first*(0x40*0x40) + second*0x40
                            + (static_cast<UChar>(*i) - 0x80);
    }
    else if(static_cast<UChar>(*i)/0x8 == 0x1E) // meet 11110xxx byte
    {
      /* TODO
      if(sizeof(WChar) < 4*sizeof(Char))
        return;                   // error
      */
      Char first, second, third;
      first = static_cast<UChar>(*i) - 0xF0;
      if( ++i == e )
        return i;
      second = static_cast<UChar>(*i) - 0x80;
      if( ++i == e )
        return i;
      third = static_cast<UChar>(*i) - 0x80;
      if( ++i == e )
        return i;
      *o = first*(0x40*0x40*0x40) + second*(0x40*0x40) + third*0x40
                                 + (static_cast<UChar>(*i) - 0x80);
    }
    ++i;
  }
  return i;
}

#endif // __MBWCVT_HPP__

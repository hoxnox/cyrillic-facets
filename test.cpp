/**@author hoxnox <hoxnox@gmail.com>
 * Test suite for facets.
 * Used boost unit test framework*/

//#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE master test sute
#include <boost/test/unit_test.hpp>
#include <locale>
#include <string>
#include <fstream>
#include <iostream>

#include "codecvt/codecvt_cp866.hpp"
#include "codecvt/codecvt_cp1251.hpp"
#include "unicyr_ctype.hpp"

using namespace std;


// TODO: codecvt/codecvt_cp1251.hpp
// TODO: unicyr_ctype.hpp
// TODO: ctype_cp1251.hpp


BOOST_AUTO_TEST_CASE( test_codecvt_cp866 )
{
  ofstream ofile("test.txt", std::ios::binary);
  std::ostreambuf_iterator<char> writer(ofile);
  writer   = 0x8F; // П
  ++writer = 0xE0; // р
  ++writer = 0xA8; // и
  ++writer = 0xA2; // в
  ++writer = 0xA5; // е
  ++writer = 0xE2; // т
  ++writer = 0x2C; // ,
  ++writer = 0x20; //  
  ++writer = 0xAC; // м
  ++writer = 0xA8; // и
  ++writer = 0xE0; // р
  ++writer = 0x21; // !
  ofile.close();
  wifstream ifile("test.txt");
  std::locale cp866(std::locale(""), new codecvt_cp866<wchar_t, char, mbstate_t>);
  ifile.imbue(cp866);
  wchar_t wstr[13];
  ifile.getline(wstr, 13);
  BOOST_CHECK(std::wstring(wstr) == L"Привет, мир!");
}

BOOST_AUTO_TEST_CASE( test_codecvt_cp1251 )
{
  ofstream ofile("test.txt", std::ios::binary);
  std::ostreambuf_iterator<char> writer(ofile);
  writer   = 0xCF; // П
  ++writer = 0xF0; // р
  ++writer = 0xE8; // и
  ++writer = 0xE2; // в
  ++writer = 0xE5; // е
  ++writer = 0xF2; // т
  ++writer = 0x2C; // ,
  ++writer = 0x20; //  
  ++writer = 0xEC; // м
  ++writer = 0xE8; // и
  ++writer = 0xF0; // р
  ++writer = 0x21; // !
  ofile.close();
  wifstream ifile("test.txt");
  std::locale cp1251(std::locale(""), new codecvt_cp1251<wchar_t, char, mbstate_t>);
  ifile.imbue(cp1251);
  wchar_t wstr[13];
  ifile.getline(wstr, 13);
  BOOST_CHECK(std::wstring(wstr) == L"Привет, мир!");
}

BOOST_AUTO_TEST_CASE( unicyr_ctype_test )
{
  std::locale uctype(std::locale(""), new unicyr_ctype);
  BOOST_CHECK(std::isalpha(L'А', uctype));
  BOOST_CHECK(std::isdigit(L'1', uctype));
}

// EOF


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
#include <iterator>

#include "codecvt/codecvt_cp866.hpp"
#include "codecvt/codecvt_cp1251.hpp"

using namespace std;

BOOST_AUTO_TEST_CASE( test_codecvt_cp866 )
{
  // writing test data
  ofstream ofile("test.txt", std::ios::binary);
  BOOST_REQUIRE(ofile);
  ostreambuf_iterator<char> writer(ofile);
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

  // testing reading
  wifstream ifile("test.txt");
  BOOST_REQUIRE(ifile);
  std::locale cp866(std::locale(""), new codecvt_cp866);
  ifile.imbue(cp866);
  wchar_t wstr[13];
  ifile.getline(wstr, 13);
  BOOST_REQUIRE(std::wstring(wstr) == L"Привет, мир!");
  ifile.close();

  // testing writing
  wofstream wofile("test.txt");
  BOOST_REQUIRE(wofile);
  wofile.imbue(cp866);
  wofile << std::wstring(wstr);
  wofile.close();
  ifile.open("test.txt");
  BOOST_REQUIRE(ifile);
  ifile.getline(wstr, 13);
  BOOST_REQUIRE(std::wstring(wstr) == L"Привет, мир!");
  ifile.close();
}

BOOST_AUTO_TEST_CASE( test_codecvt_cp1251 )
{
  // writing test data
  ofstream ofile("test.txt", std::ios::binary);
  BOOST_REQUIRE(ofile);
  ostreambuf_iterator<char> writer(ofile);
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

  // testing reading
  wifstream ifile("test.txt");
  BOOST_REQUIRE(ifile);
  std::locale cp1251(std::locale(""), new codecvt_cp1251);
  ifile.imbue(cp1251);
  wchar_t wstr[13];
  ifile.getline(wstr, 13);
  BOOST_REQUIRE(std::wstring(wstr) == L"Привет, мир!");
  ifile.close();

  // testing writing
  wofstream wofile("test.txt");
  BOOST_REQUIRE(wofile);
  wofile.imbue(cp1251);
  wofile << std::wstring(wstr);
  wofile.close();
  ifile.open("test.txt");
  BOOST_REQUIRE(ifile);
  ifile.getline(wstr, 13);
  BOOST_REQUIRE(std::wstring(wstr) == L"Привет, мир!");
  ifile.close();
}

// EOF


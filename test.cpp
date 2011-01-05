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
  writer   = 0x80; // А
  ++writer = 0x81; // Б
  ++writer = 0x82; // В
  ++writer = 0x83; // Г
  ++writer = 0x84; // Д
  ++writer = 0x85; // Е
  ++writer = 0xf0; // Ё
  ++writer = 0x86; // Ж
  ++writer = 0x87; // З
  ++writer = 0x88; // И
  ++writer = 0x89; // Й
  ++writer = 0x8a; // К
  ++writer = 0x8b; // Л
  ++writer = 0x8c; // М
  ++writer = 0x8d; // Н
  ++writer = 0x8e; // О
  ++writer = 0x8f; // П
  ++writer = 0x90; // Р
  ++writer = 0x91; // С
  ++writer = 0x92; // Т
  ++writer = 0x93; // У
  ++writer = 0x94; // Ф
  ++writer = 0x95; // Х
  ++writer = 0x96; // Ц
  ++writer = 0x97; // Ч
  ++writer = 0x98; // Ш
  ++writer = 0x99; // Щ
  ++writer = 0x9c; // Ь
  ++writer = 0x9b; // Ы
  ++writer = 0x9a; // Ъ
  ++writer = 0x9d; // Э
  ++writer = 0x9e; // Ю
  ++writer = 0x9f; // Я
  ++writer = 0xa0; // а
  ++writer = 0xa1; // б
  ++writer = 0xa2; // в
  ++writer = 0xa3; // г
  ++writer = 0xa4; // д
  ++writer = 0xa5; // е
  ++writer = 0xf1; // ё
  ++writer = 0xa6; // ж
  ++writer = 0xa7; // з
  ++writer = 0xa8; // и
  ++writer = 0xa9; // й
  ++writer = 0xaa; // к
  ++writer = 0xab; // л
  ++writer = 0xac; // м
  ++writer = 0xad; // н
  ++writer = 0xae; // о
  ++writer = 0xaf; // п
  ++writer = 0xe0; // р
  ++writer = 0xe1; // с
  ++writer = 0xe2; // т
  ++writer = 0xe3; // у
  ++writer = 0xe4; // ф
  ++writer = 0xe5; // х
  ++writer = 0xe6; // ц
  ++writer = 0xe7; // ч
  ++writer = 0xe8; // ш
  ++writer = 0xe9; // щ
  ++writer = 0xec; // ь
  ++writer = 0xeb; // ы
  ++writer = 0xea; // ъ
  ++writer = 0xed; // э
  ++writer = 0xee; // ю
  ++writer = 0xef; // я
  ofile.close();

  // testing reading
  wifstream ifile("test.txt");
  BOOST_REQUIRE(ifile);
  std::locale cp866(std::locale(""), new codecvt_cp866);
  ifile.imbue(cp866);
  wchar_t wstr[68];
  ifile.getline(wstr, 67);
  BOOST_REQUIRE(std::wstring(wstr) == L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЬЫЪЭЮЯ"
                                      L"абвгдеёжзийклмнопрстуфхцчшщьыъэюя");
  ifile.close();

  // testing writing
  wofstream wofile("test.txt");
  BOOST_REQUIRE(wofile);
  wofile.imbue(cp866);
  wofile << std::wstring(wstr);
  wofile.close();
  ifile.open("test.txt");
  BOOST_REQUIRE(ifile);
  ifile.getline(wstr, 67);
  BOOST_REQUIRE(std::wstring(wstr) == L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЬЫЪЭЮЯ"
                                      L"абвгдеёжзийклмнопрстуфхцчшщьыъэюя");
  ifile.close();
}

BOOST_AUTO_TEST_CASE( test_codecvt_cp1251 )
{
  // writing test data
  ofstream ofile("test.txt", std::ios::binary);
  BOOST_REQUIRE(ofile);
  ostreambuf_iterator<char> writer(ofile);
  writer   = 0xc0; // А
  ++writer = 0xc1; // Б
  ++writer = 0xc2; // В
  ++writer = 0xc3; // Г
  ++writer = 0xc4; // Д
  ++writer = 0xc5; // Е
  ++writer = 0xa8; // Ё
  ++writer = 0xc6; // Ж
  ++writer = 0xc7; // З
  ++writer = 0xc8; // И
  ++writer = 0xc9; // Й
  ++writer = 0xca; // К
  ++writer = 0xcb; // Л
  ++writer = 0xcc; // М
  ++writer = 0xcd; // Н
  ++writer = 0xce; // О
  ++writer = 0xcf; // П
  ++writer = 0xd0; // Р
  ++writer = 0xd1; // С
  ++writer = 0xd2; // Т
  ++writer = 0xd3; // У
  ++writer = 0xd4; // Ф
  ++writer = 0xd5; // Х
  ++writer = 0xd6; // Ц
  ++writer = 0xd7; // Ч
  ++writer = 0xd8; // Ш
  ++writer = 0xd9; // Щ
  ++writer = 0xdc; // Ь
  ++writer = 0xdb; // Ы
  ++writer = 0xda; // Ъ
  ++writer = 0xdd; // Э
  ++writer = 0xde; // Ю
  ++writer = 0xdf; // Я
  ++writer = 0xe0; // а
  ++writer = 0xe1; // б
  ++writer = 0xe2; // в
  ++writer = 0xe3; // г
  ++writer = 0xe4; // д
  ++writer = 0xe5; // е
  ++writer = 0xb8; // ё
  ++writer = 0xe6; // ж
  ++writer = 0xe7; // з
  ++writer = 0xe8; // и
  ++writer = 0xe9; // й
  ++writer = 0xea; // к
  ++writer = 0xeb; // л
  ++writer = 0xec; // м
  ++writer = 0xed; // н
  ++writer = 0xee; // о
  ++writer = 0xef; // п
  ++writer = 0xf0; // р
  ++writer = 0xf1; // с
  ++writer = 0xf2; // т
  ++writer = 0xf3; // у
  ++writer = 0xf4; // ф
  ++writer = 0xf5; // х
  ++writer = 0xf6; // ц
  ++writer = 0xf7; // ч
  ++writer = 0xf8; // ш
  ++writer = 0xf9; // щ
  ++writer = 0xfc; // ь
  ++writer = 0xfb; // ы
  ++writer = 0xfa; // ъ
  ++writer = 0xfd; // э
  ++writer = 0xfe; // ю
  ++writer = 0xff; // я
  ofile.close();

  // testing reading
  wifstream ifile("test.txt");
  BOOST_REQUIRE(ifile);
  std::locale cp1251(std::locale(""), new codecvt_cp1251);
  ifile.imbue(cp1251);
  wchar_t wstr[68];
  ifile.getline(wstr, 67);
  BOOST_REQUIRE(std::wstring(wstr) == L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЬЫЪЭЮЯ"
                                      L"абвгдеёжзийклмнопрстуфхцчшщьыъэюя");
  ifile.close();

  // testing writing
  wofstream wofile("test.txt");
  BOOST_REQUIRE(wofile);
  wofile.imbue(cp1251);
  wofile << std::wstring(wstr);
  wofile.close();
  ifile.open("test.txt");
  BOOST_REQUIRE(ifile);
  ifile.getline(wstr, 67);
  BOOST_REQUIRE(std::wstring(wstr) == L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЬЫЪЭЮЯ"
                                      L"абвгдеёжзийклмнопрстуфхцчшщьыъэюя");
  ifile.close();
}

// EOF


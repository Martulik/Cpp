#include <boost/test/unit_test.hpp>
#include <vector>
#include <forward_list>
#include <iostream>
#include "functions.hpp"
#include "sort.hpp"

namespace lebedeva
{
  const char* emtStr = "";
  const char* invArg = "kdfgjdjfg";
  const char* ascending = "ascending";
  const char* descending = "descending";
  const char* num1 = "1";
  const char* num2 = "22";
  const int negSize = -4;
  const int nullSize = 0;
  std::vector< double > testVec(nullSize);
  std::vector< int > iVec = { 3, 5, 2, -2 };
  std::vector< int > oneElemVec = { 7 };
  std::vector< int > twoElemVec = { 101, 2 };
  std::vector< int > nullVec;
  std::forward_list< int > iList = { 5, -5, 1 };
  std::forward_list< int > twoElemList = { 9, 7 };
  std::forward_list< int > oneElemList = { -6 };
  std::forward_list< int > empList;
  std::function< bool(int, int) > ascOrder = getSortOrder< int >(ascending);

  void doBracketsTest(std::vector< int > vec, std::function< bool(int, int) > comp);
  void doAtTest(std::vector< int > vec, std::function< bool(int, int) > comp);
  void doIteratorTest(std::forward_list< int > list, std::function< bool(int, int) > comp);
}

void lebedeva::doBracketsTest(std::vector< int > vec, std::function< bool(int, int) > comp)
{
  sort< bracketsAccess >(vec, comp);
  BOOST_CHECK(std::is_sorted(vec.begin(), vec.end()));
}

void lebedeva::doAtTest(std::vector< int > vec, std::function< bool(int, int) > comp)
{
  sort< atAccess >(vec, comp);
  BOOST_CHECK(std::is_sorted(vec.begin(), vec.end()));
}

void lebedeva::doIteratorTest(std::forward_list< int > list, std::function< bool(int, int) > comp)
{
  sort< iteratorAccess >(list, comp);
  BOOST_CHECK(std::is_sorted(list.begin(), list.end()));
}

BOOST_AUTO_TEST_SUITE(FunctionsTests)
BOOST_AUTO_TEST_CASE(checkSortOrderFunc)
{
  BOOST_CHECK_THROW(lebedeva::getSortOrder< int >(lebedeva::emtStr), std::invalid_argument);
  BOOST_CHECK_THROW(lebedeva::getSortOrder< int >(lebedeva::invArg), std::invalid_argument);
  BOOST_CHECK(lebedeva::getSortOrder< int >(lebedeva::ascending));
  BOOST_CHECK(lebedeva::getSortOrder< int >(lebedeva::descending));
}
BOOST_AUTO_TEST_CASE(checkIsNumber)
{
  BOOST_CHECK_EQUAL(lebedeva::isNumber(lebedeva::emtStr), true);
  BOOST_CHECK_EQUAL(lebedeva::isNumber(lebedeva::invArg), false);
  BOOST_CHECK_EQUAL(lebedeva::isNumber(lebedeva::num1), true);
  BOOST_CHECK_EQUAL(lebedeva::isNumber(lebedeva::num2), true);
}

BOOST_AUTO_TEST_CASE(fillRandom)
{
  BOOST_CHECK_THROW(lebedeva::fillRandom(lebedeva::testVec.data(), lebedeva::nullSize), std::invalid_argument);
  BOOST_CHECK_THROW(lebedeva::fillRandom(lebedeva::testVec.data(), lebedeva::negSize), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(SortTests)
BOOST_AUTO_TEST_CASE(bracketAccess)
{
  lebedeva::doBracketsTest(lebedeva::iVec, lebedeva::ascOrder);
  lebedeva::doBracketsTest(lebedeva::oneElemVec, lebedeva::ascOrder);
  lebedeva::doBracketsTest(lebedeva::twoElemVec, lebedeva::ascOrder);
  lebedeva::doBracketsTest(lebedeva::nullVec, lebedeva::ascOrder);
}

BOOST_AUTO_TEST_CASE(atAccess)
{
  lebedeva::doAtTest(lebedeva::iVec, lebedeva::ascOrder);
  lebedeva::doAtTest(lebedeva::oneElemVec, lebedeva::ascOrder);
  lebedeva::doAtTest(lebedeva::twoElemVec, lebedeva::ascOrder);
  lebedeva::doAtTest(lebedeva::nullVec, lebedeva::ascOrder);
}

BOOST_AUTO_TEST_CASE(iteratorAccess)
{
  lebedeva::doIteratorTest(lebedeva::empList, lebedeva::ascOrder);
  lebedeva::doIteratorTest(lebedeva::oneElemList, lebedeva::ascOrder);
  lebedeva::doIteratorTest(lebedeva::twoElemList, lebedeva::ascOrder);
  lebedeva::doIteratorTest(lebedeva::iList, lebedeva::ascOrder);
}
BOOST_AUTO_TEST_SUITE_END()

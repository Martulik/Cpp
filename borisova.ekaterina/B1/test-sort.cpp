#include <boost/test/unit_test.hpp>
#include <forward_list>
#include <vector>
#include <ctime>
#include "functions.hpp"
#include "strategies.hpp"

namespace borisova
{
  const char* mode = "ascending";
  void testBracket();
  void testAt();
  void testList();
}

namespace lab = borisova;

void lab::testBracket()
{
  std::vector< int > vecBrackets(3);
  std::generate(vecBrackets.begin(), vecBrackets.end(), randomNumber);
  lab::sort< lab::bracketStrategy< int > >(vecBrackets, sortMode< int >(mode));
  BOOST_CHECK(std::is_sorted(vecBrackets.begin(), vecBrackets.end()));
}

void lab::testAt()
{
  std::vector< int > vecInd(4);
  std::generate(vecInd.begin(), vecInd.end(), randomNumber);
  lab::sort< lab::atStrategy< int > >(vecInd, sortMode< int >(mode));
  BOOST_CHECK(std::is_sorted(vecInd.begin(), vecInd.end()));
}

void lab::testList()
{
  std::forward_list< int > listIt(5);
  std::generate(listIt.begin(), listIt.end(), randomNumber);
  lab::sort< lab::listStrategy< int > >(listIt, sortMode< int >(mode));
  BOOST_CHECK(std::is_sorted(listIt.begin(), listIt.end()));
}

BOOST_AUTO_TEST_SUITE(testSort)

BOOST_AUTO_TEST_CASE(bracketStrategy)
{
  srand(time(0));
  lab::testBracket();
}

BOOST_AUTO_TEST_CASE(atStrategy)
{
  srand(time(0));
  lab::testAt();
}

BOOST_AUTO_TEST_CASE(listStrategy)
{
  srand(time(0));
  lab::testList();
}

BOOST_AUTO_TEST_SUITE_END()

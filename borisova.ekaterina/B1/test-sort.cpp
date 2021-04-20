#include <boost/test/unit_test.hpp>
#include <forward_list>
#include <vector>
#include <ctime>
#include "functions.hpp"
#include "strategies.hpp"

namespace borisova
{
  std::string mode = "ascending";
  void testBracket();
  void testAt();
  void testList();
  template < typename T >
  void fillRandomCont(typename T::iterator itr, const typename T::iterator& end)
  {
    srand(time(0));
    while (itr != end)
    {
      *itr = rand()%501 - 1001;
      itr++;
    }
  }
}

namespace lab = borisova;

void lab::testBracket()
{
  std::vector< int > vecBrackets(3);
  lab::fillRandomCont< std::vector< int > >(vecBrackets.begin(), vecBrackets.end());
  lab::sort< lab::bracketStrategy< int > >(vecBrackets, sortMode<int>(mode));
  BOOST_CHECK(std::is_sorted(vecBrackets.begin(), vecBrackets.end()));
}

void lab::testAt()
{
  std::vector< int > vecInd(4);
  lab::fillRandomCont< std::vector< int > >(vecInd.begin(), vecInd.end());
  lab::sort< lab::atStrategy< int > >(vecInd, sortMode<int>(mode));
  BOOST_CHECK(std::is_sorted(vecInd.begin(), vecInd.end()));
}

void lab::testList()
{
  std::forward_list< int > listIt(5);
  lab::fillRandomCont< std::forward_list< int > >(listIt.begin(), listIt.end());
  lab::sort< lab::listStrategy< int > >(listIt, sortMode<int>(mode));
  BOOST_CHECK(std::is_sorted(listIt.begin(), listIt.end()));
}

BOOST_AUTO_TEST_SUITE(testSort)

BOOST_AUTO_TEST_CASE(bracketStrategy)
{
  lab::testBracket();
}

BOOST_AUTO_TEST_CASE(atStrategy)
{
  lab::testAt();
}

BOOST_AUTO_TEST_CASE(listStrategy)
{
  lab::testList();
}

BOOST_AUTO_TEST_SUITE_END()

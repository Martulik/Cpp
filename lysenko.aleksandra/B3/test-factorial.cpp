#include <boost/test/unit_test.hpp>

#include "FactorialList.h"

BOOST_AUTO_TEST_SUITE(testFactorialContainer)

BOOST_AUTO_TEST_CASE(testFactorialValue)
{
  lysenko::FactorialList myCont;
  int number = 1;
  int factorialValue = 1;
  for (lysenko::FactorialList ::Iterator iter = myCont.begin(); iter != myCont.end(); iter++)
  {
    factorialValue *= number;
    number++;
    BOOST_CHECK_EQUAL(*iter, factorialValue);
  }
}
BOOST_AUTO_TEST_SUITE_END()

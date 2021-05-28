#include <boost/test/unit_test.hpp>
#include <string>
#include <sstream>
#include <vector>

#include "DataStruct.h"

namespace lysenko
{
  void testSorting(const std::string firstOne, const std::string secondOne)
  {
    std::istringstream firstStr(firstOne);
    std::istringstream secondStr(secondOne);

    lysenko::DataStruct firstData;
    lysenko::DataStruct secondData;

    firstStr >> firstData;
    secondStr >> secondData;

    std::vector< lysenko::DataStruct > sortedOne{ firstData, secondData };
    std::vector< lysenko::DataStruct > unsortedOne{ secondData, firstData };

    std::sort(unsortedOne.begin(), unsortedOne.end());

    BOOST_CHECK_EQUAL_COLLECTIONS(sortedOne.begin(), sortedOne.end(), unsortedOne.begin(), unsortedOne.end());
  }
}

BOOST_AUTO_TEST_SUITE(testSort)

BOOST_AUTO_TEST_CASE(testByFirstKey)
{
  lysenko::testSorting("3,5,bnghngh", "5,5,bbbbnghngh");
}

BOOST_AUTO_TEST_CASE(testBySecondKey)
{
  lysenko::testSorting("3,4,bnghngh", "3,5,bbbbnghngh");
}

BOOST_AUTO_TEST_CASE(testByLenghtOfStr)
{
  lysenko::testSorting("5,5,bnghngh", "5,5,bnghkoingh");
}

BOOST_AUTO_TEST_SUITE_END()

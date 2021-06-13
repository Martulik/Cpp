#include <boost/test/unit_test.hpp>

#include "Shape.h"

namespace lysenko
{
  void testPointWithInpData(std::string data)
  {
    std::stringstream in(data);
    lysenko::Point pnt;
    BOOST_CHECK_THROW(in >> pnt, std::invalid_argument);
  }
}

BOOST_AUTO_TEST_SUITE(testPointInput)

BOOST_AUTO_TEST_CASE(testCorrectionOfRead)
{
  std::string testData = "(1;1)";
  std::stringstream in(testData);
  lysenko::Point pnt;
  in >> pnt;
  BOOST_CHECK_EQUAL(pnt.x, 1);
  BOOST_CHECK_EQUAL(pnt.y, 1);
}

BOOST_AUTO_TEST_CASE(testWrongDelimiter)
{
  std::string testData = "|1;1)";
  lysenko::testPointWithInpData(testData);

  std::string testData1 = "(1'1)";
  lysenko::testPointWithInpData(testData1);

  std::string testData2 = "(1;1|";
  lysenko::testPointWithInpData(testData2);

  std::string testData3 = "1 1";
  lysenko::testPointWithInpData(testData3);
}

BOOST_AUTO_TEST_CASE(testInvalidNumber)
{
  std::string testData = "(1;b)";
  lysenko::testPointWithInpData(testData);
}

BOOST_AUTO_TEST_SUITE_END()

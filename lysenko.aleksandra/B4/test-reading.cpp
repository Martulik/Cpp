#include <boost/test/unit_test.hpp>
#include <stdexcept>
#include <sstream>

#include"DataStruct.h"

void createDataStruct(const std::string str)
{
  std::istringstream in(str);
  lysenko::DataStruct data;
  in >> data;
}

BOOST_AUTO_TEST_SUITE(testReading)

BOOST_AUTO_TEST_CASE(notManyEnoughArguments)
{
  BOOST_CHECK_THROW(createDataStruct("-5,-5"), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(onlyOneDelimiter)
{
  BOOST_CHECK_THROW(createDataStruct("-5,-5dmvdfmvdovif"), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(invalidKey)
{
  BOOST_CHECK_THROW(createDataStruct("-5,-6,dmvdfmvdovif"), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

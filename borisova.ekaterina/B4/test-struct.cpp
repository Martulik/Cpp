#include <sstream>
#include <boost/test/unit_test.hpp>
#include "data-struct.hpp"

BOOST_AUTO_TEST_SUITE(Input)

BOOST_AUTO_TEST_CASE(CorrectInput)
{
  std::istringstream in("4,-2,fghjk");
  borisova::DataStruct temp;
  in >> temp;
  BOOST_CHECK_EQUAL(temp.key1, 4);
  BOOST_CHECK_EQUAL(temp.key2, -2);
  BOOST_CHECK_EQUAL(temp.str, "fghjk");
}

BOOST_AUTO_TEST_CASE(IncorrectKeys)
{
  std::istringstream in("6, -10, fghjk");
  borisova::DataStruct temp;
  BOOST_CHECK_THROW(in >> temp, std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(WithoutCommas)
{
  std::istringstream in("2 3 fghjk");
  borisova::DataStruct temp;
  BOOST_CHECK_THROW(in >> temp, std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(OneComma)
{
  std::istringstream in("2, 1 fghjkhk");
  borisova::DataStruct temp;
  BOOST_CHECK_THROW(in >> temp, std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Compare)

BOOST_AUTO_TEST_CASE(Compare)
{
  borisova::DataStruct temp1 = { 4, -3, "fghjk" };
  borisova::DataStruct temp2 = { 4, -2, "fghjk" };
  BOOST_CHECK(temp1 < temp2);

  temp1 = { 4, -3, "fghjk" };
  temp2 = { 1, -2, "fghjk" };
  BOOST_CHECK(!(temp1 < temp2));

  temp1 = { 4, -2, "fghjk" };
  temp2 = { 4, -2, "fghjkhjkl" };
  BOOST_CHECK(temp1 < temp2);
}

BOOST_AUTO_TEST_SUITE_END()

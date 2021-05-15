#include <boost/test/unit_test.hpp>
#include <sstream>
#include "record_t.hpp"

const std::string inputStr = "567834567834 \"Banan,Apple\"";
const std::string outputStr = "567834567834 Banan,Apple";

BOOST_AUTO_TEST_SUITE(record_t)

BOOST_AUTO_TEST_CASE(inputOperator)
{
  diurdeva::record_t record;
  std::stringstream input;
  input << inputStr;
  input >> record;
  BOOST_CHECK_EQUAL(outputStr, (record.number + " " + record.name));
}

BOOST_AUTO_TEST_CASE(outputOperator)
{
  diurdeva::record_t record{ "546789087432", "Banan" };
  std::stringstream ss;
  ss << record;
  BOOST_CHECK_EQUAL(ss.str(), (record.number + " " + record.name + "\n"));
}

BOOST_AUTO_TEST_SUITE_END()

#include <sstream>
#include <boost/test/unit_test.hpp>
#include "point.hpp"

BOOST_AUTO_TEST_SUITE(test_point)

  BOOST_AUTO_TEST_CASE(firstWrongPointInput)
  {
    std::string line("(152-;123)");
    std::stringstream sin(line);
    murzakanov::Point point;
    BOOST_CHECK(!(sin >> point));
  }

  BOOST_AUTO_TEST_CASE(secondWrongPointInput)
  {
    std::string line("(aa152;123)");
    std::stringstream sin(line);
    murzakanov::Point point;
    BOOST_CHECK(!(sin >> point));
  }

  BOOST_AUTO_TEST_CASE(thirdWrongPointInput)
  {
    std::string line("(152;asdf12)");
    std::stringstream sin(line);
    murzakanov::Point point;
    BOOST_CHECK(!(sin >> point));
  }

  BOOST_AUTO_TEST_CASE(fouthWrongPointInput)
  {
    std::string line("(asd12;123)");
    std::stringstream sin(line);
    murzakanov::Point point;
    BOOST_CHECK(!(sin >> point));
  }

  BOOST_AUTO_TEST_CASE(succsessfulPointInput)
  {
    std::string line("( -152   ;   123   )");
    std::stringstream sin(line);
    murzakanov::Point point;
    BOOST_CHECK((sin >> point));
  }

BOOST_AUTO_TEST_SUITE_END()

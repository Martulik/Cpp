#include <sstream>
#include <boost/test/unit_test.hpp>
#include "shape.hpp"

namespace lab = ezerinia;

BOOST_AUTO_TEST_SUITE(shape_istream)

  BOOST_AUTO_TEST_CASE(istringstream_correct)
  {
    std::istringstream iss("3 (723; 3968) (723; 26) (-3219; 26)\n");
    lab::Shape shape;
    iss >> shape;
    BOOST_CHECK(shape.size() == 3);
    BOOST_CHECK_EQUAL(shape[0].x, 723);
    BOOST_CHECK_EQUAL(shape[0].y, 3968);
    BOOST_CHECK_EQUAL(shape[1].x, 723);
    BOOST_CHECK_EQUAL(shape[1].y, 26);
    BOOST_CHECK_EQUAL(shape[2].x, -3219);
    BOOST_CHECK_EQUAL(shape[2].y, 26);
  }

  BOOST_AUTO_TEST_CASE(istringstream_incorrect_vertices)
  {
    std::istringstream iss("4  (723; 3968)  (723; 26)  (-3219; 26)\n");
    lab::Shape shape;
    BOOST_CHECK_THROW(iss >> shape, std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(istringstream_incorrect_point)
  {
    std::istringstream iss("3  (723; 3968)  (723,890)  (-3219; 26)\n");
    lab::Shape shape;
    BOOST_CHECK_THROW(iss >> shape, std::invalid_argument);
  }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(shape_ostream)

  BOOST_AUTO_TEST_CASE(ostringstream)
  {
    std::ostringstream oss;
    lab::Shape shape{{723,   3968}, {723,   26}, {-3219, 26}};
    oss << shape;
    BOOST_CHECK_EQUAL(oss.str(), "3 (723; 3968) (723; 26) (-3219; 26) ");
  }

BOOST_AUTO_TEST_SUITE_END()

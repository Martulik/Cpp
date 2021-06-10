#include <boost/test/unit_test.hpp>

#include <chrono>
#include <random>
#include <functional>

#include "shape.hpp"
#include "tools.hpp"

namespace lab = shkurov;

BOOST_AUTO_TEST_SUITE(srGen)

BOOST_AUTO_TEST_CASE(correctGen)
{
  boost::unit_test::unit_test_log.set_threshold_level(boost::unit_test::log_messages);

  std::mt19937 rnd(std::chrono::high_resolution_clock::now().time_since_epoch().count());

  const unsigned int rectangles_req = 30;
  const unsigned int squares_req = 70;
  const double relation_req = static_cast< double >(rectangles_req) / squares_req;

  std::function< lab::Shape() > fGen = std::bind(lab::rsGen, rectangles_req, squares_req, rnd);
  std::vector< lab::Shape > vector(100);
  std::generate(vector.begin(), vector.end(), fGen);

  size_t squares = std::count_if(vector.begin(), vector.end(), lab::isSquare);
  size_t rectangles = vector.size() - squares;

  BOOST_TEST_MESSAGE(rectangles_req << ':' << squares_req);
  BOOST_TEST_MESSAGE('(' << relation_req << ") required.\n");
  BOOST_TEST_MESSAGE(rectangles << ':' << squares);
  BOOST_TEST_MESSAGE('(' << static_cast< double >(rectangles) / squares << ") presented.\n");

  boost::unit_test::unit_test_log.set_threshold_level(boost::unit_test::log_all_errors);
}

BOOST_AUTO_TEST_SUITE_END()

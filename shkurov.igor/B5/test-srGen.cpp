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
  std::mt19937 rnd(std::chrono::high_resolution_clock::now);

  const unsigned int rectangles_req = 30;
  const unsigned int squares_req = 70;
  constexpr double relation_req = rectangles_req / squares_req;

  std::function< lab::Shape() > fGen = std::bind(lab::rsGen, rectangles_req, squares_req, rnd);
  std::vector< lab::Shape > vector(100);
  std::generate(vector.begin(), vector.end(), fGen);

  size_t squares = std::count_if(vector.begin(), vector.end(), lab::isSquare);
  size_t rectangles = vector.size() - squares;

  BOOST_TEST_MESSAGE(rectangles_req << ':' << squares_req << '(');
  BOOST_TEST_MESSAGE(static_cast< double >(rectangles_req) / static_cast< double >(squares_req) << ") required.\n");
  BOOST_TEST_MESSAGE(rectangles << ':' << squares << '(');
  BOOST_TEST_MESSAGE(static_cast< double >(rectangles) / static_cast< double >(squares) << ") presented.\n");
}

BOOST_AUTO_TEST_SUITE_END()

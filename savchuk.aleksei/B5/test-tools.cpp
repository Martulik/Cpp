#include "test-tools.hpp"

#include <sstream>

#include <boost/test/unit_test.hpp>

namespace lab = savchuk;

void lab::checkCorrectInput(const char* str)
{
  std::istringstream ss(str);
  Shape shape;
  BOOST_CHECK(ss >> shape);
}

void lab::checkIncorrectInput(const char* str)
{
  std::istringstream ss(str);
  Shape shape;
  BOOST_CHECK(!(ss >> shape));
}

void lab::checkRandomShape(const Shape& shape)
{
  if (shape.size() == 4)
  {
    BOOST_CHECK(isSquare(shape));
  }
  else
  {
    BOOST_CHECK(shape.size() == 8);
  }
}

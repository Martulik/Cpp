#include <boost/test/included/unit_test.hpp>
#include <stdexcept>
#include "test-tools.hpp"
#include "composite-shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

namespace lab = ezerinia;
using shapePtr = std::shared_ptr< lab::Shape >;

const size_t overIndex = 7000;

void addShapes(lab::CompositeShape *shape)
{
  shapePtr rectangle = std::make_shared< lab::Rectangle >(64.1, 3.1, StartPos);
  shape->pushBack(rectangle);

  shapePtr circle = std::make_shared< lab::Circle >(1.0, StartPos);
  shape->pushBack(circle);
}

BOOST_AUTO_TEST_SUITE(testCompositeShape)

  BOOST_AUTO_TEST_CASE(moveCompositeShape)
  {
    lab::CompositeShape composite(std::make_shared< lab::Rectangle >(width, height, StartPos));
    addShapes(&composite);
    checkMoveAbs(&composite);
    checkMovePoint(&composite);
  }

  BOOST_AUTO_TEST_CASE(scaleCompositeShape)
  {
    lab::CompositeShape composite(std::make_shared< lab::Circle >(radius, StartPos));
    addShapes(&composite);
    checkScale(&composite);
  }

  BOOST_AUTO_TEST_CASE(invalidArgumentCompositeShape)
  {
    lab::CompositeShape composite(std::make_shared< lab::Rectangle >(width, height, StartPos));
    BOOST_CHECK_THROW(composite.scale(negativeValue), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(outOfRangeCompositeShape)
  {
    lab::CompositeShape composite(std::make_shared< lab::Circle >(radius, StartPos));
    BOOST_CHECK_THROW(composite.at(overIndex), std::out_of_range);
  }

  BOOST_AUTO_TEST_CASE(deleteLastShapeInCompositeShape)
  {
    lab::CompositeShape composite(std::make_shared< lab::Circle >(radius, StartPos));
    BOOST_CHECK_THROW(composite.popBack(), std::logic_error);
  }

BOOST_AUTO_TEST_SUITE_END()

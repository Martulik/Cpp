#include "test-functions.hpp"

namespace lysenko
{
  lysenko::Shape::ShapePtr makeCircle()
  {
    double radius = 33.33;
    point_t pos = { 1, 1 };

    return std::make_shared< Circle >(Circle(pos, radius));
  }

  lysenko::Shape::ShapePtr createMyCircle(double radius, point_t pos)
  {
    return std::make_shared< Circle >(Circle(pos, radius));
  }

  lysenko::Shape::ShapePtr makeRectangle()
  {
    double width = 1.0;
    double height = 2.0;
    point_t pos{ 33.33, 33.33 };

    return std::make_shared< Rectangle >(Rectangle(width, height, pos));
  }

  lysenko::Shape::ShapePtr createMyRectangle(double width, double height, point_t pos)
  {
    return std::make_shared< Rectangle >(Rectangle(width, height, pos));
  }

  std::shared_ptr< lysenko::CompositeShape > makeCompositeShape()
  {
    Shape::ShapePtr myCircle = makeCircle();
    Shape::ShapePtr myRectangle = makeRectangle();
    std::shared_ptr < CompositeShape > myComposite = std::make_shared< CompositeShape >(myCircle);
    myComposite->addShape(myRectangle);
    return myComposite;
  }

  void testMove(lysenko::Shape::ShapePtr src)
  {
    const double dx = 1.0;
    const double dy = 1.0;
    const point_t newPos{ 0.0, 0.0 };

    double width = getWidth(src);
    double height = getHeight(src);
    double area = src->getArea();

    src->move(dx, dy);

    BOOST_CHECK_CLOSE(getWidth(src), width, accuracy);
    BOOST_CHECK_CLOSE(getWidth(src), width, accuracy);
    BOOST_CHECK_CLOSE(getHeight(src), height, accuracy);
    BOOST_CHECK_CLOSE(src->getArea(), area, accuracy);

    src->move(newPos);
    BOOST_CHECK_CLOSE(getWidth(src), width, accuracy);
    BOOST_CHECK_CLOSE(getHeight(src), height, accuracy);
    BOOST_CHECK_CLOSE(src->getArea(), area, accuracy);
  }

  void testScale(lysenko::Shape::ShapePtr src)
  {
    double k = 5.0;
    double oldArea = src->getArea();
    double centerX = getX(src);
    double centerY = getY(src);

    src->scale(k);
    BOOST_CHECK_CLOSE(src->getArea(), oldArea * k * k, accuracy);
    BOOST_CHECK_CLOSE(centerX, getX(src), accuracy);
    BOOST_CHECK_CLOSE(centerY, getY(src), accuracy);
  }
}

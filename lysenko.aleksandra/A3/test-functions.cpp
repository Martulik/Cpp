#include "test-functions.hpp"

namespace lysenko
{
  Shape::ShapePtr lysenko::makeCircle()
  {
    double radius = 33.33;
    point_t pos = { 1, 1 };

    return std::make_shared< Circle >(Circle(pos, radius));
  }

  Shape::ShapePtr lysenko::makeRectangle()
  {
    double width = 1.0;
    double height = 2.0;
    point_t pos{ 33.33, 33.33 };

    return std::make_shared< Rectangle >(Rectangle(width, height, pos));
  }

  std::shared_ptr < CompositeShape > lysenko::makeCompositeShape()
  {
    Shape::ShapePtr myCircle = makeCircle();
    Shape::ShapePtr myRectangle = makeRectangle();
    std::shared_ptr <CompositeShape> myComposite = std::make_shared< CompositeShape >(myCircle);
    myComposite->addShape(myRectangle);
    return myComposite;
  }
  void lysenko::testMove(lysenko::Shape::ShapePtr src)
  {
    const double dx = 1.0;
    const double dy = 1.0;
    const point_t newPos{ 0.0, 0.0 };

    double width = getWidth(src);
    double height = getHeight(src);
    double area = src->getArea();

    src->move(dx, dy);
    BOOST_CHECK_CLOSE(getWidth(src), width, accuracy);
    BOOST_CHECK_CLOSE(getHeight(src), height, accuracy);
    BOOST_CHECK_CLOSE(src->getArea(), area, accuracy);

    src->move(newPos);
    BOOST_CHECK_CLOSE(getWidth(src), width, accuracy);
    BOOST_CHECK_CLOSE(getHeight(src), height, accuracy);
    BOOST_CHECK_CLOSE(src->getArea(), area, accuracy);
  }

  void lysenko::testScale(Shape::ShapePtr src)
  {
    double k = 5.0;
    double defaultK = -5.0;
    double oldArea = src->getArea();

    src->scale(k);
    BOOST_CHECK_CLOSE(src->getArea(), oldArea * k * k, accuracy);
  }
}
 
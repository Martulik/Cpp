#include "test-functions.hpp"

namespace murzakanov
{
  namespace mur = murzakanov;
  void testMove(mur::Shape::ShapePtr shp)
  {
    const double dX = -5.0;
    const double dY = 16.0;
    const point_t newPos{ 2.0, -5.0 };

    double area = shp->getArea();
    double height = getHeight(shp);
    double width = getWidth(shp);

    shp->move(dX, dY);
    BOOST_CHECK_CLOSE(getWidth(shp), width, epsilon);
    BOOST_CHECK_CLOSE(getHeight(shp), height, epsilon);
    BOOST_CHECK_CLOSE(shp->getArea(), area, epsilon);

    shp->move(newPos);
    BOOST_CHECK_CLOSE(getWidth(shp), width, epsilon);
    BOOST_CHECK_CLOSE(getHeight(shp), height, epsilon);
    BOOST_CHECK_CLOSE(shp->getArea(), area, epsilon);
  }

  void testScale(mur::Shape::ShapePtr shp)
  {
    double area = shp->getArea();
    double k1 = 5;
    double k2 = 0.5;
    shp->scale(k1);
    BOOST_CHECK_CLOSE(shp->getArea(), area * k1 * k1, epsilon);
    area = shp->getArea();
    shp->scale(k2);
    BOOST_CHECK_CLOSE(shp->getArea(), area * k2 * k2, epsilon);
  }

  mur::Shape::ShapePtr makeRect()
  {
    const double width = 3.0;
    const double height = 2.0;
    const mur::point_t pos{ 9.0, 7.0 };
    return std::make_shared< mur::Rectangle >(mur::Rectangle(width, height, pos));
  }

  mur::Shape::ShapePtr makeCircle()
  {
    const mur::point_t pos{ 5.0, 8.0 };
    const double rad = 7.0;
    return std::make_shared< mur::Circle >(mur::Circle(rad, pos));
  }

  std::shared_ptr< mur::CompositeShape > makeCompositeShp()
  {
    mur::Shape::ShapePtr rectangle = makeRect();
    mur::Shape::ShapePtr circle = makeCircle();
    std::shared_ptr< mur::CompositeShape > polyCmpShp(std::make_shared< mur::CompositeShape >(circle));
    polyCmpShp->addShape(rectangle);
    return polyCmpShp;
  }
}

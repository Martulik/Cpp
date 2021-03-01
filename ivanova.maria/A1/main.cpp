#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

void info(Shape* shape);

int main()
{
  Rectangle *rectangle = new Rectangle (10, 12, {3.0, 18.0});
  Shape *shape0 = rectangle;
  info(shape0);
  Circle *circle  = new Circle({1, 4}, 12);
  Shape *shape1 = circle;
  info(shape1);
  delete rectangle;
  delete circle;
  return 0;
}

void info(Shape *shape)
{
  std::cout << shape;
  std::cout << "\narea is " << shape->getArea() << std::endl;
  shape->move(12, 7);
  shape->move({4, 8});
  std::cout << "\nframe rectangle: " << std::endl << "height: " << shape0->getFrameRect().height << std::endl
  << "width: " << shape0->getFrameRect().width << std::endl << "center: {" << shape0->getFrameRect().pos.x
  << ";" << shape0->getFrameRect().pos.y << "}\n" << std::endl;
}

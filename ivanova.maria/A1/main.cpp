#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"
namespace i=ivanova;
void info(i::Shape* shape);

int main()
{
  i::Rectangle *rectangle = new i::Rectangle (10, 12, {3.0, 18.0});
  i::Shape *shape0 = rectangle;
  info(shape0);
  i::Circle *circle  = new i::Circle({1, 4}, 12);
  i::Shape *shape1 = circle;
  info(shape1);
  delete rectangle;
  delete circle;
  return 0;
}

void info(i::Shape *shape)
{
  std::cout << shape;
  std::cout << "\narea is " << shape->getArea() << std::endl;
  shape->move(12, 7);
  shape->move({4, 8});
  std::cout << "\nframe rectangle: " << std::endl << "height: " << shape->getFrameRect().height << std::endl
  << "width: " << shape->getFrameRect().width << std::endl << "center: {" << shape->getFrameRect().pos.x
  << ";" << shape->getFrameRect().pos.y << "}\n" << std::endl;
}

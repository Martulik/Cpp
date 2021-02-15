#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  Rectangle *rectangle = new Rectangle (10, 12, {3.0, 18.0});
  Shape *shape0 = rectangle;
  std::cout << *shape0;
  std::cout << "\narea is " << shape0->getArea() << std::endl;
  shape0->move(12, 7);
  shape0->move({4, 8});
  std::cout << "\nframe rectangle: " << std::endl << "height: " << shape0->getFrameRect().height << std::endl
  << "width: " << shape0->getFrameRect().width << std::endl << "center: {" << shape0->getFrameRect().pos.x
  << ";" << shape0->getFrameRect().pos.y << "}\n" << std::endl;

  Circle *circle  = new Circle({1, 4}, 12);
  Shape *shape1 = circle;
  std::cout << *shape1;
  std::cout << "\narea is " << shape1->getArea() << std::endl;
  shape1->move(12, 7);
  shape1->move({4, 8});
  std::cout << "\nframe rectangle: " << std::endl << "height: " << shape1->getFrameRect().height << std::endl
  << "width: " << shape1->getFrameRect().width << std::endl << "center: {" << shape1->getFrameRect().pos.x
  << ";" << shape1->getFrameRect().pos.y << "}" << std::endl;

  delete rectangle;
  delete circle;
  return 0;
}

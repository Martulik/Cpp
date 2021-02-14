#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  Rectangle rectangle(10, 12, {3, 18});
  Shape &shape0 = rectangle;
  shape0.outShape();
  std::cout << "area is " << shape0.getArea() << std::endl;
  shape0.move(12, 7);
  shape0.outShape();
  shape0.move({4, 8});
  shape0.outShape();
  std::cout << "frame rectangle: " << std::endl << "height: " << shape0.getFrameRect().height_ << std::endl
  << "width: " << shape0.getFrameRect().width_ << std::endl << "center: {" << shape0.getFrameRect().pos_.x
  << ";" << shape0.getFrameRect().pos_.y << "}" << std::endl;

  Circle circle({1, 4}, 12);
  Shape &shape1 = circle;
  shape1.outShape();
  std::cout << "area is " << shape1.getArea() << std::endl;
  shape1.move(12, 7);
  shape1.outShape();
  shape1.move({4, 8});
  shape1.outShape();
  std::cout << "frame rectangle: " << std::endl << "height: " << shape1.getFrameRect().height_ << std::endl
  << "width: " << shape1.getFrameRect().width_ << std::endl << "center: {" << shape1.getFrameRect().pos_.x
  << ";" << shape1.getFrameRect().pos_.y << "}" << std::endl;
  return 0;
}

#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"
#include "base-types.hpp"

int main()
{
  Shape * polyPointer;
  rectangle_t frame;
  point_t o{0,0};
  Circle circle(10, o);
  Rectangle rec(20, 10, o);

  frame = circle.getFrameRect();
  std::cout << "left top corner's of circle's frame x cord is " << frame.pos.x << std::endl;
  std::cout << "left top corner's of circle's frame y cord is " << frame.pos.y << std::endl;
  polyPointer = &circle;
  polyPointer->move(12, 13);
  frame = circle.getFrameRect();
  std::cout << "left top corner's of circle's frame x cord is " << frame.pos.x << std::endl; 
  std::cout << "left top corner's of circle's frame y cord is " << frame.pos.y << std::endl;

  frame = rec.getFrameRect();
  std::cout << "left top corner's of rectangle's frame x cord is " << frame.pos.x << std::endl;
  std::cout << "left top corner's of rectangle's frame y cord is " << frame.pos.y << std::endl;
  polyPointer = &rec;
  polyPointer->move(3.22, 11.235);
  frame = rec.getFrameRect();
  std::cout << "left top corner's of rectangle's frame x cord is " << frame.pos.x << std::endl;
  std::cout << "left top corner's of rectangle's frame y cord is " << frame.pos.y << std::endl;

  return 0;
}

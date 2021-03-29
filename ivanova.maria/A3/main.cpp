#include <iostream>

#include "composite-shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

void info(ivanova::CompositeShape &array);
void test(ivanova::CompositeShape &array);

int main()
{
  const double radius = 12.0;
  const ivanova::point_t ctr = {4.8, 2.9};
  const double h = 10.9;
  const double w = 5.0;
  const ivanova::point_t pos = {-2.0, 9.1};

  ivanova::Rectangle rectangle(h, w, pos);
  std::shared_ptr<ivanova::Shape> testRect = std::make_shared<ivanova::Rectangle>(rectangle);

  ivanova::Circle circle(ctr, radius);
  ivanova::CompositeShape testArray(std::make_shared<ivanova::Circle>(circle));

  testArray.pushBack(testRect);
  test(testArray);
  return 0;
}

void test(ivanova::CompositeShape &array)
{
  std::cout << "Before scale: " << std::endl;
  info(array);
  array.scale(3);
  std::cout << "After scale: " << std::endl;
  info(array);
  std::cout << "MoveAbs: " << std::endl;
  array.move(1.5, -2);
  info(array);
  array.move({4.0, 6.8});
  info(array);
}

void info(ivanova::CompositeShape &array)
{
  std::cout << array.getName() << std::endl << "size: " << array.size() << std::endl;
  std::cout << "width: " << array.getFrameRect().width << std::endl;
  std::cout << "height: " << array.getFrameRect().height << std::endl;
  std::cout << "area: " << array.getArea() << std::endl;
  for (size_t i = 0; i < array.size(); i++) {
    std::shared_ptr<ivanova::Shape> temp = array[i];
    std::cout << i << ": " << temp->getName() << std::endl;
    std::cout << "center: {" << temp->getFrameRect().pos.x << "; " << temp->getFrameRect().pos.y << "}" << std::endl;
  }
  std::cout << "width: " << array.getFrameRect().width << std::endl;
  std::cout << "height: " << array.getFrameRect().height << std::endl;
  std::cout << "area: " << array.getArea() << std::endl;
}

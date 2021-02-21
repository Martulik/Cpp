#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

int main() {
  Rectangle rectangle(5, 8, { 0, 0 });
  Rectangle rectangle1(9, 4, { 5, 5 });
  rectangle.print();
  rectangle = rectangle1;
  rectangle.move(2, 3);
  rectangle.print();
  std::cout << "rectangel square - " << rectangle.getArea() << std::endl;
  Circle circle(5, { 0, 0 });
  circle.print();
  circle.move(-1, 3);
  circle.print();
  std::cout <<"circle square - " << circle.getArea() << std::endl;
  return 0;
}

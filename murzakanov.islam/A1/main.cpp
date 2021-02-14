#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

int main(){
  Rectangle rectangle(5, 6, { 3, 2 });
  Rectangle rectangle2(3, 1, { 0, 0 });
  rectangle.print();
  rectangle = rectangle2;
  rectangle.move(2, 3);
  rectangle.print();
  Circle circle(2, { 0, 0 });
  std::cout << circle.getArea() << std::endl;
  std::cout << rectangle.getArea() << std::endl;
  return 0;
}

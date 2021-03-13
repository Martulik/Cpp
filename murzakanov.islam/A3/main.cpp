#include <iostream>

#include "circle.hpp"
#include "rectangle.hpp"
#include "composite-shape.hpp"

int main()
{
  double width = 3,
         height = 2;
  murzakanov::point_t rectanglePos{1, 2};
  murzakanov::Rectangle testRectangle(width, height, rectanglePos);

  double radius = 1.5;
  murzakanov::point_t circlePos{2, 3};
  std::shared_ptr< murzakanov::Shape > testCircle;
  testCircle = std::make_shared< murzakanov::Circle >(radius, circlePos);
  murzakanov::CompositeShape testArray;
  testArray.addShape(testCircle);
  testArray.addShape(std::make_shared< murzakanov::Rectangle >(testRectangle));
  std::cout << testArray[0].getName() << std::endl;
  std::cout << testArray[1].getName() << std::endl;
  std::cout << testArray.getFrameRect().pos.x << " "
            << testArray.getFrameRect().pos.y << std::endl;
  std::cout << "Координаты до скейла\n";
  for (int i = 0; i < testArray.getSize(); i++)
  {
    std::cout << testArray[i].getName() << '\n';
    std::cout << testArray[i].getFrameRect().pos.x
              << " " << testArray[i].getFrameRect().pos.y << std::endl;
  }
  std::cout << "Площадь до скейла: \n" << testArray.getArea() << "\n";
  testArray.scale(5);
  std::cout << "Площадь после скейла: \n" << testArray.getArea() << "\n";
  std::cout << "Координаты после скейла\n";
  for (int i = 0; i < testArray.getSize(); i++)
  {
    std::cout << testArray[i].getFrameRect().pos.x
              << " " << testArray[i].getFrameRect().pos.y << std::endl;
  }
  return 0;
}

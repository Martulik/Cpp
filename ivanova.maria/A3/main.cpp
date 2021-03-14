#include <iostream>

#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"

void info (ivanova::CompositeShape &array);

int main()
{
  ivanova::Rectangle rectangle (10.9, 5.0, {-4.0, 8.1});
  std::shared_ptr< ivanova::Shape > testRect = std::make_shared< ivanova::Rectangle >(rectangle);

  ivanova::Circle circle ({4.8, 2.9}, 12.0);
  std::shared_ptr< ivanova::Shape > testCircle = std::make_shared< ivanova::Circle >(circle);

  ivanova::CompositeShape testArray;
  testArray.add(testCircle);
  testArray.add(testRect);

  std::cout << "Before scale: " << std::endl;
  info(testArray);
  testArray.scale(3);
  std::cout << "After scale: " << std::endl;
  info(testArray);
  return 0;
}

void info (ivanova::CompositeShape &array)
{
  for ( size_t i=0; i<array.getSize(); i++)
  {
    std::shared_ptr< ivanova::Shape> temp = array[i];
    std::cout << i << ": " << temp->getName() << std::endl;
    std::cout << "center: {" << temp->getFrameRect().pos.x << "; " << temp->getFrameRect().pos.y << "}" << std::endl;
  }
  std::cout << "width: " << array.getFrameRect().width << std::endl;
  std::cout << "height: " << array.getFrameRect().height << std::endl;
  std::cout << "area: " << array.getArea() << std::endl;
}

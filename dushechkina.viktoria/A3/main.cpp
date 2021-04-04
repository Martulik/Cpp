#include <iostream>

#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"

namespace vika = dushechkina;
void printInfoAboutFrameRect(std::ostream& out,const std::shared_ptr< vika::Shape > f)
{
  out << "\nInfo: height = " << vika::getHeight(*f) << ", width = " << vika::getWidth(*f)
      << ", center: { " << vika::getX(*f) << ", " << vika::getY(*f) << " }\n";
}
int main()
{
  try
  { 
    const double width = 12.8;
    const double height = 6.4;
    const double radius1 = 3.2;
    const double radius2 = 16.0;
    const double ratio = 2.56;
    const double coor1 = 0.8;
    const double coor2 = 20.48;
    const vika::point_t center = { coor1, coor2 };
    const vika::point_t center1 = { coor2, coor1 };

    vika::CompositeShape compositeShape(std::make_shared< vika::Rectangle >(width, height, center));
    compositeShape.pushBack(std::make_shared< vika::Circle >(center, radius1));
    compositeShape.pushBack(std::make_shared< vika::Circle >(center, radius2));

    std::cout << "Area: " << compositeShape.getArea();
    for (size_t i = 0; i < compositeShape.size(); i++)
    {
      printInfoAboutFrameRect(std::cout, compositeShape.at(i));
      compositeShape.at(i)->move(center1);
      compositeShape.at(i)->move(coor1, coor2);
      compositeShape.at(i)->scale(ratio);
      printInfoAboutFrameRect(std::cout, compositeShape.at(i));
    }
  }
  catch (const std::invalid_argument& e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  catch (const std::out_of_range& e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  catch (const std::logic_error& e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  return 0;
}

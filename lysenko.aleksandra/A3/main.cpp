#include <iostream>
#include <string>

#include "base-types.hpp"
#include "shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "composite-shape.hpp"

namespace lysenko
{
  void testMyFigure(lysenko::Shape::ShapePtr figure);

  void printFrameRect(const lysenko::Shape::ShapePtr figure);

  void printFiguresCenter(std::string adj, const lysenko::Shape::ShapePtr figure);

  void printFigure(const lysenko::Shape::ShapePtr figure);
}

int main()
{
  try
  {
    lysenko::point_t myPos{ 33.33, 33.33 };
    double width = 1.0;
    double heigth = 2.0;
    lysenko::Shape::ShapePtr myRectangle(std::make_shared< lysenko::Rectangle >(width, heigth, myPos));
    testMyFigure(myRectangle);

    double radius = 33.33;
    lysenko::Shape::ShapePtr myCircle(std::make_shared< lysenko::Circle >(myPos, radius));
    testMyFigure(myCircle);

    lysenko::Shape::ShapePtr myCompositeShape(std::make_shared< lysenko::CompositeShape >(myRectangle));
    testMyFigure(myCompositeShape);
  }
  catch (...)
  {
    std::cerr << "Exceptions are detected. Program can not be finished";
    return 1;
  }
  return 0;
}

void lysenko::printFrameRect(const lysenko::Shape::ShapePtr figure)
{
  std::cout << "Its frame rectangle's width: " << figure->getFrameRect().width << ", "
            << "height: " << figure->getFrameRect().height << ", "
            << "center's abscissa: " << figure->getFrameRect().pos.x << ", "
            << "centers's ordinate " << figure->getFrameRect().pos.y << "\n";
}

void lysenko::printFiguresCenter(const std::string adj, const lysenko::Shape::ShapePtr figure)
{
  std::cout << "Its " << adj << " center's abscissa " << figure->getFrameRect().pos.x << "\n"
            << "Its " << adj << " centers's ordinate " << figure->getFrameRect().pos.y << "\n";
}

void lysenko::printFigure(const lysenko::Shape::ShapePtr figure)
{
  std::string typeOfFigure = figure->getName();
  std::cout << "Type of figure:" << typeOfFigure << "\n";
  printFiguresCenter("", figure);
  std::cout << "Its area " << figure->getArea() << "\n";
  printFrameRect(figure);
}

void lysenko::testMyFigure(lysenko::Shape::ShapePtr figure)
{
  printFigure(figure);
  lysenko::point_t newPos{ 0.0, 0.0 };
  std::cout << "Move the figure's center to point (" << newPos.x << ", " << newPos.y << ")\n";
  figure->move(newPos);
  printFiguresCenter("new", figure);
  std::cout << "Move figure's center along x-asix by 1 along the y-asix by 1\n";
  figure->move(1.0, 1.0);
  printFiguresCenter("new", figure);
  double coef = 5;
  figure->scale(coef);
  printFigure(figure);
  printFrameRect(figure);
}

#include <iostream>

#include "circle.hpp"
#include "rectangle.hpp"

void printFrameRect(const Shape* s)
{
  rectangle_t reserve = s->getFrameRect();
  std::cout << "Coordinates: " << "X = " << reserve.pos.x
  << "; Y = " << reserve.pos.y << '\n';
  std::cout << "\nHeight and width: ";
  std::cout << "h = " << reserve.height <<
  "; w = " << reserve.width << '\n';
}

void printArea(const Shape *s)
{
  std::cout << "\nArea: " << s->getArea() << '\n';
}

int main()
{
  Shape* figureCircle = new Circle({ 2, 2 }, 3);
  std::cout << "Parameters circle before move: " << '\n';
  printFrameRect(figureCircle);

  point_t pos = { 12, 7 };
  figureCircle->move(pos);
  std::cout << "\nParameters circle after move: " << '\n';
  printFrameRect(figureCircle);


  figureCircle->move(10, 12);
  std::cout << "\nParameters circle after another move :" << '\n';
  printFrameRect(figureCircle);

  printArea(figureCircle);

  delete figureCircle;

  pos = { 5, 8 };

  Shape* figureRectangle = new Rectangle(10, 12, { 5, 5 });
  std::cout << "\nParameters rectangle before move: " << '\n';
  printFrameRect(figureRectangle);


  figureRectangle->move(10, 65);
  std::cout << "\nParameters rectangle after move: " << '\n';
  printFrameRect(figureRectangle);

  figureRectangle->move(pos);
  std::cout << "\nParameters rectangle after another move :" << '\n';
  printFrameRect(figureRectangle);

  printArea(figureRectangle);

delete figureRectangle;
}

#include "base-types.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

#include <iostream>

void printCoordinates(Shape* figure)
{
    std::cout   << "Figure is now located by (" << figure->getFrameRect().pos.x
                << ':' << figure->getFrameRect().pos.y << ')' << std::endl;
}


int main() {
    std::cout << "Rectangle test:" << std::endl;
    point_t begin_pos = {5.5, -3.5};
    Rectangle rect(begin_pos, 6, 8);

    Shape* figure = &rect;              // parent-type pointer to rectangle
    printCoordinates(figure);

    point_t new_pos = {-10.4, 1};       // move test #1
    figure->move(new_pos);
    printCoordinates(figure);

    figure->move(-5, -20);          // move test #2
    printCoordinates(figure);

    std::cout << "Area of rectangle is: " << figure->getArea() << std::endl;


    std::cout << std::endl << "Circle test:" << std::endl;
    begin_pos = {-31.2, 9.21};
    Circle circle(begin_pos, 10);

    figure = &circle;
    printCoordinates(figure);

    new_pos = {41.2, -100};     // move test #1
    figure->move(new_pos);
    printCoordinates(figure);

    figure->move(-1.2, 120);    // move test #2
    printCoordinates(figure);

    std::cout << "Area of circle is: " << figure->getArea() << std::endl;



    return 0;
}

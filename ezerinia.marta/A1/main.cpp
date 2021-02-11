#include "circle.hpp"
#include "rectangle.hpp"

int main()
{
    try
    {
        Rectangle someRectangle(2.0, 4.0, point_t(0.0, 0.0));
        Shape *someShape = &someRectangle;
        std::cout << "area of rectangle = " << someShape->getArea() << std::endl;
        someShape->showShape();
        someShape->move(point_t(1.1, 2.2));
        someShape->showShape();
        someShape->move(-1.1, 1.0);
        someShape->showShape();
        std::cout << "limit rectangle_t for Rectangle ";
        std::cout << "height = " << someShape->getFrameRect().height << "  width = "
                  << someShape->getFrameRect().width;
        std::cout << " center: x = " << someShape->getFrameRect().pos.x << ", y = "
                  << someShape->getFrameRect().pos.y;

        std::cout << std::endl;


        Circle someCircle(111.1, point_t(1.0, -1.0));
        someShape = &someCircle;
        std::cout << "area of circle = " << someShape->getArea() << std::endl;
        someShape->showShape();
        someShape->move(point_t(1.1, 2.2));
        someShape->showShape();
        someShape->move(-1.1, 1.0);
        someShape->showShape();
        someShape->getFrameRect();
        std::cout << "limit rectangle_t for Circle ";
        std::cout << "height = " << someShape->getFrameRect().height << "  width = "
                  << someShape->getFrameRect().width;
        std::cout << " center: x = " << someShape->getFrameRect().pos.x << ", y = "
                  << someShape->getFrameRect().pos.y;
        std::cout << std::endl;
    }
    catch (const char *s)
    {
        std::cout << s << std::endl;
        return 1;
    }
    return 0;
}

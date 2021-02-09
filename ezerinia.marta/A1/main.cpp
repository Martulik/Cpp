#include "circle.hpp"
#include "rectangle.hpp"

int main()
{
	//try
	//{
		Shape* someShape;
		Rectangle someRectangle(2.0, 4.0);
		Circle someCircle(111.1, point_t(1.0, -1.0));
	//}
	//catch (const char* s)
	//{
	//	std::cout << s;
	//}
	someShape = &someRectangle;
	std::cout << "area of rectangle = " << someShape->getArea() << std::endl;
	someShape->showCenter();
	someShape->move(point_t(1.1, 2.2));
	someShape->showCenter();
	someShape->move(-1.1, 1.0);
	someShape->showCenter();
	std::cout << "limit rectangle_t for Rectangle " << std::endl;
	std::cout << "height = " << someShape->getFrameRect().height_t << "  width = " << someShape->getFrameRect().width_t;
	std::cout << " center: " << someShape->getFrameRect().pos_t.x_t << someShape->getFrameRect().pos_t.y_t;

	std::cout << std::endl;

	someShape = &someCircle;
	std::cout << "area of circle = " << someShape->getArea() << std::endl;
	someShape->showCenter();
	someShape->move(point_t(1.1, 2.2));
	someShape->showCenter();
	someShape->move(-1.1, 1.0);
	someShape->showCenter();
	someShape->getFrameRect();
}
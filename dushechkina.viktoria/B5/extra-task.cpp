#include "extra-task.hpp"

dushechkina::Shape dushechkina::generateFigure(std::mt19937& rand)
{
	std::uniform_int_distribution< int > coor(-100, 100);
	int x = coor(rand);
	int y = coor(rand);
	while (x == 0 || y == 0)
	{
		x = coor(rand);
		y = coor(rand);
	}
	Point first{ coor(rand), coor(rand) };
	Point second{ first.x + x, first.y };
	Point third{ first.x + x, first.y + y };
	Point fourth{ first.x, first.y + y };

	Shape shape1;
	shape1 = {first, second, third, fourth};

	std::uniform_int_distribution< int > randPos(0, 3);
	int pos1, pos2, pos3, pos4;
	pos1 = randPos(rand);
	pos2 = randPos(rand);
	while (pos1 == pos2)
	{
		pos2 = randPos(rand);
	}
	pos3 = randPos(rand);
	while (pos1 == pos3 || pos2 == pos3)
	{
		pos3 = randPos(rand);
	}
	pos4 = 6 - pos1 - pos2 - pos3;

	std::swap(shape1[0], shape1[pos1]);
	std::swap(shape1[1], shape1[pos2]);
	std::swap(shape1[2], shape1[pos3]);
	std::swap(shape1[3], shape1[pos4]);

	return shape1;
}

bool dushechkina::isSquareNotSelfInter(const Shape& shape)
{
	return (isSquare(shape) && (shape[0].x != shape[2].x && shape[0].y != shape[2].y));
}

bool dushechkina::isRectNotSelfInter(const Shape& shape)
{
	return (isRectangle(shape) && (shape[0].x != shape[2].x && shape[0].y != shape[2].y));
}

dushechkina::Shape dushechkina::changeSquareSelfInter(Shape shape)
{
	if (!isSquareNotSelfInter(shape))
	{
		if (shape[0].x == shape[2].x || shape[0].y == shape[2].y)
		{
			std::swap(shape[2].x, shape[3].x);
			std::swap(shape[2].y, shape[3].y);
		}
		if (shape[1].x == shape[3].x || shape[1].y == shape[3].y)
		{
			std::swap(shape[3].x, shape[0].x);
			std::swap(shape[3].y, shape[0].y);
		}
	}
	return shape;
}

dushechkina::Shape dushechkina::changeRectSelfInter(Shape& shape)
{
	if (!isRectNotSelfInter(shape))
	{
		if (shape[0].x == shape[2].x || shape[0].y == shape[2].y)
		{
			std::swap(shape[2].x, shape[3].x);
			std::swap(shape[2].y, shape[3].y);
		}
		if (shape[1].x == shape[3].x || shape[1].y == shape[3].y)
		{
			std::swap(shape[3].x, shape[0].x);
			std::swap(shape[3].y, shape[0].y);
		}
	}
	return shape;
}

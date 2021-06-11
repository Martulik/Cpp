#ifndef EXTRA_TASK_HPP
#define EXTRA_TASK_HPP

#include "point.hpp"

#include <random>

namespace dushechkina
{
	Shape generateFigure(std::mt19937& rand);
	bool isSquareNotSelfInter(const Shape& shape);
	bool isRectNotSelfInter(const Shape& shape);
	Shape changeSquareSelfInter(Shape shape);
	Shape changeRectSelfInter(Shape& shape);
}

#endif

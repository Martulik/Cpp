#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

class Shape
{
public:
	virtual void showCenter() = 0;
	virtual double getArea() = 0;								//вычисление площади
	virtual rectangle_t getFrameRect() = 0;						//получение ограничивающего прямоугольника
	virtual void move(const point_t& point) = 0;				//перемещение центра фигуры в конкретную точку
	virtual void move(const double& x, const double& y) = 0;	//перемещение центра фигуры в виде смещений по осям абсцисс и ординат
	virtual ~Shape() = default;
};

#endif
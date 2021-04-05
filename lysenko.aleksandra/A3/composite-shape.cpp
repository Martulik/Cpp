#include "composite-shape.hpp"

#include <string>

namespace curr = lysenko;

double curr::CompositeShape::getArea() const
{
  double resultArea = 0;
  for (size_t i = 0; i < size_; i++)
  {
    resultArea += array_[i]->getArea();
  }
  return resultArea;
}

double lysenko::getShapesLeftmostAbscissa(Shape::ShapePtr const src)
{
  return getX(*src) + getWidth(*src) / 2;
}

double lysenko::getShapesRightmostAbscissa(Shape::ShapePtr const src)
{
  return getX(*src) - getWidth(*src) / 2;
}

double lysenko::getShapesBottomOrdinate(Shape::ShapePtr const src)
{
  return getY(*src) - getHeight(*src) / 2;
}

double lysenko::getShapesTopOrdinate(Shape::ShapePtr const src)
{
  return getY(*src) + getHeight(*src) / 2;
}

curr::rectangle_t curr::CompositeShape::getFrameRect() const
{
  ShapePtr current = array_[0];
  double minX = getShapesRightmostAbscissa(current);
  double maxX = getShapesLeftmostAbscissa(current);
  double minY = getShapesBottomOrdinate(current);
  double maxY = getShapesTopOrdinate(current);
  for (size_t i = 1; i < size_; i++)
  {
    current = array_[i];
    minX = std::min(minX, getShapesRightmostAbscissa(current));
    maxX = std::max(maxX, getShapesLeftmostAbscissa(current));
    minY = std::min(minY, getShapesBottomOrdinate(current));
    maxY = std::max(maxY, getShapesTopOrdinate(current));
  }
  return {maxX - minX, maxY - minY, {(minX + (maxX - minX) / 2), (minY + (maxY - minY) / 2)}};
}

void curr::CompositeShape::move(const point_t& newPos)
{
  double dx = newPos.x - getX(*this);
  double dy = newPos.y - getY(*this);
  move(dx, dy);
}

void curr::CompositeShape::move(double dx, double dy)
{
  for (size_t i = 0; i < size_; i++)
  {
    array_[i]->move(dx, dy);
  }
}

std::string curr::CompositeShape::getName() const
{
  return "Composite shape";
}

void curr::CompositeShape::doScale(double k)
{
  double compositeCenterX = getX(*this);
  double compositeCenterY = getY(*this);
  for (size_t i = 0; i < size_; i++)
  {
    array_[i]->scale(k);
    double dx = compositeCenterX - getX(*array_[i]);
    double dy = compositeCenterY - getY(*array_[i]);
    array_[i]->move({ compositeCenterX + dx * k, compositeCenterY + dy * k });
  }
}

curr::Shape::ShapePtr curr::CompositeShape::clone() const
{
  return std::make_shared < CompositeShape >(*this);
}


#include <stdexcept>
#include "composite-shape.hpp"
#include <iostream>

namespace leb = lebedeva;

leb::CompositeShape::CompositeShape(const std::initializer_list < ShapePtr > composition):
  countElements_(composition.size()),
  data_(std::make_unique< ShapePtr[] >(countElements_))
{
  if (countElements_ == 0)
  {
    throw std::invalid_argument("Could not create an empty composition.");
  }

  size_t i = 0;
  for (const ShapePtr shape: composition)
  {
    if (shape == nullptr)
    {
      throw std::invalid_argument("Composition could not contain an empty figure.");
    }

    data_[i] = shape->clone();
    i++;
  }
  frameRect_ = makeFrameRect();
}

leb::CompositeShape::CompositeShape(const CompositeShape& composition):
  countElements_(composition.countElements_),
  data_(std::make_unique< ShapePtr[] >(countElements_))
{
  for (size_t i = 0; i < countElements_; ++i)
  {
    data_[i] = composition.data_[i]->clone();
  }
  frameRect_ = makeFrameRect();
}

leb::CompositeShape& leb::CompositeShape::operator=(const CompositeShape& composition)
{
  CompositeShape temp(composition);
  swap(temp);
  return *this;
}

double leb::CompositeShape::getArea() const
{
  double result = 0;
  for (size_t i = 0; i < countElements_; i++)
  {
    result += data_[i]->getArea();
  }
  return result;
}

leb::rectangle_t leb::CompositeShape::getFrameRect() const
{
  return frameRect_;
}

std::string leb::CompositeShape::getName() const
{
  return "Composite Shape";
}

std::shared_ptr< leb::Shape > leb::CompositeShape::clone() const
{
  return std::make_shared< CompositeShape >(*this);
}

void leb::CompositeShape::move(const point_t& newPos)
{
  point_t oldPos = this->getFrameRect().pos;
  move(newPos.x - oldPos.x, newPos.y - oldPos.y);
}

void leb::CompositeShape::move(double dx, double dy)
{
  for (size_t i = 0; i < countElements_; i++)
  {
    data_[i]->move(dx, dy);
  }
  frameRect_ = makeFrameRect();
}

void leb::CompositeShape::doScale(double k)
{
  leb::point_t collectionPos = this->getFrameRect().pos;
  for (size_t i = 0; i < countElements_; i++)
  {
    leb::point_t tempPos = data_[i]->getFrameRect().pos;
    double dx = (tempPos.x - collectionPos.x) * k;
    double dy = (tempPos.y - collectionPos.y) * k;
    data_[i]->move({ collectionPos.x + dx, collectionPos.y + dy });
    data_[i]->scale(k);
  }
  frameRect_ = makeFrameRect();
}

void leb::CompositeShape::swap(CompositeShape& composition) noexcept
{
  std::swap(countElements_, composition.countElements_);
  std::swap(data_, composition.data_);
}

namespace lebedeva
{
  point_t getPos(point_t botLeft, point_t topRight);
  double getWidth(double minX, double maxX);
  double getHeight(double minY, double maxY);

  point_t getPos(point_t botLeft, point_t topRight)
  {
    return { (topRight.x + botLeft.x) / 2, (topRight.y + botLeft.y) / 2 };
  }

  double getWidth(const double minX, const double maxX)
  {
    return (maxX - minX);
  }

  double getHeight(const double minY, const double maxY)
  {
    return (maxY - minY);
  }
}

leb::rectangle_t leb::CompositeShape::makeFrameRect() const
{
  rectangle_t frameRect = data_[0]->getFrameRect();
  //Direction left = Direction::Left;
  //Direction right = Direction::Right;
  //Direction top = Direction::Top;
  //Direction bottom = Direction::Bottom;
  double maxX = getBorderCoordinate(frameRect, Direction::Right);
  double minX = getBorderCoordinate(frameRect, Direction::Left);
  double maxY = getBorderCoordinate(frameRect, Direction::Top);
  double minY = getBorderCoordinate(frameRect, Direction::Bottom);

  for (size_t i = 1; i < countElements_; i++)
  {
    frameRect = data_[i]->getFrameRect();
    maxX = std::max(maxX, getBorderCoordinate(frameRect, Direction::Right));
    minX = std::min(minX, getBorderCoordinate(frameRect, Direction::Left));
    maxY = std::max(maxY, getBorderCoordinate(frameRect, Direction::Top));
    minY = std::min(minY, getBorderCoordinate(frameRect, Direction::Bottom));
  }

  return { getPos({ minX, minY }, { maxX, maxY }), getWidth(minX, maxX), getHeight(minY, maxY) };
}

#include <stdexcept>
#include "composite-shape.hpp"

namespace leb = lebedeva;

leb::CompositeShape::CompositeShape(std::shared_ptr< Shape > composition[], size_t n):
  countElements_(n),
  data_(std::make_unique< shapePtr[] >(n))
{
  if (n == 0)
  {
    throw std::invalid_argument("Could not create empty composition.");
  }
  else
  {
    for (size_t i = 0; i < n; i++)
    {
      if (composition[i] == nullptr)
      {
        throw std::invalid_argument("Composition could not contain an empty figure.");
      }
      else
      {
        data_[i] = composition[i];
      }
    }
  }
}

leb::CompositeShape::shapePtr leb::CompositeShape::operator[](size_t i) const
{
  if (i < countElements_)
  {
    return data_[i];
  }
  else
  {
    throw std::out_of_range("Out of range");
  }
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
  rectangle_t frameRect = data_[0]->getFrameRect();
  double maxX = frameRect.pos.x + (frameRect.width / 2);
  double minX = frameRect.pos.x - (frameRect.width / 2);
  double maxY = frameRect.pos.y + (frameRect.height / 2);
  double minY = frameRect.pos.y - (frameRect.height / 2);

  for (size_t i = 1; i < countElements_; i++)
  {
    frameRect = data_[i]->getFrameRect();
    maxX = std::max(maxX, frameRect.pos.x + (frameRect.width / 2));
    minX = std::min(minX, frameRect.pos.x - (frameRect.width / 2));
    maxY = std::max(maxY, frameRect.pos.y + (frameRect.height / 2));
    minY = std::min(minY, frameRect.pos.y - (frameRect.height / 2));
  }

  frameRect = { { (maxX + minX) / 2, (maxY + minY) / 2 }, (maxX - minX), (maxY - minY) };
  return frameRect;
}

std::string leb::CompositeShape::getName() const
{
  return "Composite Shape";
}

void leb::CompositeShape::move(const point_t& newPos)
{
  leb::point_t oldPos = this->getFrameRect().pos;
  move(newPos.x - oldPos.x, newPos.y - oldPos.y);
}

void leb::CompositeShape::move(double dx, double dy)
{
  for (size_t i = 0; i < countElements_; i++)
  {
    data_[i]->move(dx, dy);
  }
}

void leb::CompositeShape::scale(double k)
{
  if (k > 0)
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
  }
  else
  {
    throw std::invalid_argument("Negative parameter. Could not scale.");
  }
}

#include <cassert>
#include "composite-shape.hpp"

namespace l = lebedeva;

l::CompositeShape::CompositeShape(std::shared_ptr< Shape > composition[], const std::size_t& n):
  countElements_(n),
  data_(std::make_unique< l::Shape::Ptr[] >(n))
{
  assert(n != 0);
  for (std::size_t i = 0; i < n; i++)
  {
    data_[i] = composition[i];
  }
}

l::Shape::Ptr& l::CompositeShape::operator[](const std::size_t& i) const
{
  assert(i < countElements_);
  return data_[i];
}

double l::CompositeShape::getArea() const
{
  double result = 0;
  for (std::size_t i = 0; i < countElements_; i++)
  {
    result += data_[i]->getArea();
  }
  return result;
}

l::rectangle_t l::CompositeShape::getFrameRect() const
{
  rectangle_t frameRect = { { 0, 0 }, 0, 0 };
  if (0 != countElements_)
  {
    frameRect = data_[0]->getFrameRect();
    double maxX = frameRect.pos.x + (frameRect.width / 2);
    double minX = frameRect.pos.x - (frameRect.width / 2);
    double maxY = frameRect.pos.y + (frameRect.height / 2);
    double minY = frameRect.pos.y - (frameRect.height / 2);

    for (std::size_t i = 1; i < countElements_; i++)
    {
      frameRect = data_[i]->getFrameRect();
      maxX = std::max(maxX, frameRect.pos.x + (frameRect.width / 2));
      minX = std::min(minX, frameRect.pos.x - (frameRect.width / 2));
      maxY = std::max(maxY, frameRect.pos.y + (frameRect.height / 2));
      minY = std::min(minY, frameRect.pos.y - (frameRect.height / 2));
    }

    frameRect = { { (maxX + minX) / 2, (maxY + minY) / 2 }, (maxX - minX), (maxY - minY) };
  }
  return frameRect;
}

std::string l::CompositeShape::getName() const
{
  return "Composite Shape";
}

void l::CompositeShape::move(const point_t& newPos)
{
  l::point_t oldPos = this->getFrameRect().pos;
  this->move(newPos.x - oldPos.x, newPos.y - oldPos.y);
}

void l::CompositeShape::move(double dx, double dy)
{
  for (std::size_t i = 0; i < countElements_; i++)
  {
    data_[i]->move(dx, dy);
  }
}

void l::CompositeShape::scale(double k)
{
  assert(k > 0);
  l::point_t oldPos = this->getFrameRect().pos;
  for (std::size_t i = 0; i < countElements_; i++)
  {
    data_[i]->scale(k);
    l::point_t tempPos = data_[i]->getFrameRect().pos;
    tempPos.x *= k;
    tempPos.y *= k;
    data_[i]->move(tempPos);
  }
  l::point_t newPos = this->getFrameRect().pos;
  this->move(oldPos.x - newPos.x, oldPos.y - newPos.y);
}

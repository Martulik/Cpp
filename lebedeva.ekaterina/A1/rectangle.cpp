#include "rectangle.hpp"

//constructors
Rectangle::Rectangle(point_t pos, double width, double height):
  pos_(pos),
  width_(width),
  height_(height)
{
}
Rectangle::Rectangle(Rectangle& rect1)://copy constructor
  pos_(rect1.pos_),
  width_(rect1.width_),
  height_(rect1.height_)
{
}
Rectangle::Rectangle(Rectangle&& rect1) noexcept://move constructor
  pos_(rect1.pos_),
  width_(rect1.width_),
  height_(rect1.height_)
{
  rect1.pos_ = { 0, 0 };
  rect1.width_ = 0;
  rect1.height_ = 0;
}
//destructor
Rectangle::~Rectangle()
{
}
//overloads
Rectangle& Rectangle::operator = (Rectangle&& rect1) noexcept
{
  if(&rect1 != this)
  {
    this->pos_ = rect1.pos_;
    this->width_ = rect1.width_;
    this->height_ = rect1.height_;
  }
  return *this;
}
bool Rectangle::operator < (const Rectangle& rect1)
{
  if(&rect1 == this)
  {
    return false;
  }
  bool bResult = false;
  if (this->getArea() < rect1.getArea())
  {
    bResult = true;
  }
  return bResult;
}
bool Rectangle::operator <= (const Rectangle& rect1)
{
  if (&rect1 == this)
  {
    return true;
  }
  bool bResult = false;
  if (this->getArea() <= rect1.getArea())
  {
    bResult = true;
  }
  return bResult;
}
bool Rectangle::operator > (const Rectangle& rect1)
{
  if (&rect1 == this)
  {
    return false;
  }
  bool bResult = false;
  if (this->getArea() > rect1.getArea())
  {
    bResult = true;
  }
  return bResult;
}
bool Rectangle::operator >= (const Rectangle& rect1)
{
  if (&rect1 == this)
  {
    return true;
  }
  bool bResult = false;
  if (this->getArea() >= rect1.getArea())
  {
    bResult = true;
  }
  return bResult;
}
bool Rectangle::operator == (const Rectangle& rect1)
{
  if (&rect1 == this)
  {
    return true;
  }
  bool bResult = false;
  if (this->width_ == rect1.width_)
  {
    if (this->height_ == rect1.height_)
    {
        bResult = true;
    }
  }
  return bResult;
}
bool Rectangle::operator != (const Rectangle& rect1)
{
  if (&rect1 == this)
  {
    return false;
  }
  bool bResult = true;
  if (this->width_ == rect1.width_)
  {
    if (this->height_ == rect1.height_)
    {
      bResult = false;
    }
  }
  return bResult;
}
std::ostream& operator << (std::ostream& out, const Rectangle& rect)
{
  out << "centre " << rect.pos_ << ", " << rect.height_ << " x " << rect.width_;
  return out;
}
//setters
bool Rectangle::setHeight(const double& height)
{
  if (height <= 0)
  {
    std::cout << "Invalid height value!\n";
    return false;
  }
  else
  {
    this->height_ = height;
    return true;
  }
}
bool Rectangle::setWidth(const double& width)
{
  if (width <= 0)
  {
    std::cout << "Invalid width value!\n";
    return false;
  }
  else
  {
    this->width_ = width;
    return true;
  }
}
//getters
double Rectangle::getArea() const
{
  if ((height_ > 0) && (width_ > 0))
  {
    return (height_ * width_);
  }
  else
  {
    throw ("getArea - incorrect height or width!");
  }
}
rectangle_t Rectangle::getFrameRect() const
{
  rectangle_t result;
  result.pos = pos_;
  result.height = height_;
  result.width = width_;
  return result;
}
point_t Rectangle::getCentre() const
{
  return pos_;
}
double Rectangle::getWidth() const
{
  return width_;
}
double Rectangle::getHeight() const
{
  return height_;
}
//centre moving methods
void Rectangle::move(const point_t& newPos)
{
  if (pos_ != newPos)
  {
    pos_ = newPos;
  }
}
void Rectangle::move(const double& dx, const double& dy)
{
  pos_.x = pos_.x + dx;
  pos_.y = pos_.y + dy;
}

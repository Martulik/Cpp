#include "circle.hpp"

//constructors
Circle::Circle(const point_t pos, const double radius):
  pos_(pos),
  radius_(radius)
{}
Circle::Circle(Circle& circle1)://copy constructor
  pos_(circle1.pos_),
  radius_(circle1.radius_)
{}
Circle::Circle(Circle&& circle1) noexcept://move constructor
  pos_(circle1.pos_),
  radius_(circle1.radius_)
{
  circle1.pos_ = { 0, 0 };
  circle1.radius_ = 0;
}
//destructor
Circle::~Circle()
{}
//overloads
Circle& Circle::operator = (Circle&& circle1) noexcept
{
  if (&circle1 != this)
  {
    this->pos_ = circle1.pos_;
    this->radius_ = circle1.radius_;
  }
  return *this;
}
bool Circle::operator < (const Circle& circle1)
{
  if (&circle1 == this)
  {
    return false;
  }
  bool bResult = false;
  if (this->radius_ < circle1.radius_)
  {
    bResult = true;
  }
  return bResult;
}
bool Circle::operator <= (const Circle& circle1)
{
  if (&circle1 == this)
  {
    return true;
  }
  bool bResult = false;
  if (this->radius_ <= circle1.radius_)
  {
    bResult = true;
  }
  return bResult;
}
bool Circle::operator > (const Circle& circle1)
{
  if (&circle1 == this)
  {
    return false;
  }
  bool bResult = false;
  if (this->radius_ > circle1.radius_)
  {
    bResult = true;
  }
  return bResult;
}
bool Circle::operator >= (const Circle& circle1)
{
  if (&circle1 == this)
  {
    return true;
  }
  bool bResult = false;
  if (this->radius_ >= circle1.radius_)
  {
    bResult = true;
  }
  return bResult;
}
bool Circle::operator == (const Circle& circle1)
{
  if (&circle1 == this)
  {
    return true;
  }
  bool bResult = false;
  if (this->radius_ == circle1.radius_)
  {
    bResult = true;
  }
  return bResult;
}
bool Circle::operator != (const Circle& circle1)
{
  if (&circle1 == this)
  {
    return false;
  }
  bool bResult = true;
  if (this->radius_ == circle1.radius_)
  {
    bResult = false;
  }
  return bResult;
}
std::ostream& operator<<(std::ostream& out, const Circle& circle)
{
  out << "centre " << circle.pos_ << ", radius " << circle.radius_;
  return out;
}
//setters
bool Circle::setRadius(const double& radius)
{
  if (radius < 0)
  {
    std::cout << "Invalid radius value!\n";
    return false;
  }
  else
  {
    this->radius_ = radius;
    return true;
  }
}
//getters
point_t Circle::getCentre() const
{
  return pos_;
}
double Circle::getRadius() const
{
  return radius_;
}
double Circle::getArea() const
{
  if (radius_ >= 0)
  {
    double result = 3.14 * radius_ * radius_;
    return result;
  }
  else
  {
    throw("getArea - invalid radius!\n");
  }
}
rectangle_t Circle::getFrameRect() const
{
  if (radius_ >= 0)
  {
    rectangle_t result;
    result.pos = pos_;
    result.height = 2 * radius_;
    result.width = result.height;
    return result;
  }
  else
  {
    throw("getFrameRect - invalid radius!\n");
  }
}
//centre moving methods
void Circle::move(const point_t& newPos)
{
  if (this->pos_ != newPos)
  {
    pos_ = newPos;
  }
}
void Circle::move(const double& dx, const double& dy)
{
  pos_.x = pos_.x + dx;
  pos_.y = pos_.y + dy;
}

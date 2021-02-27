#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include "shape.hpp"

class Rectangle: public Shape
{
public:
  Rectangle(point_t pos, double width, double height); //constructor
  Rectangle(Rectangle& rect1); //copy constructor
  Rectangle(Rectangle&& rect1) noexcept; //move constructor
  ~Rectangle(); //destructor
  //overloads
  Rectangle& operator = (Rectangle&& rect1) noexcept;
  bool operator < (const Rectangle& rect1);
  bool operator <= (const Rectangle& rect1);
  bool operator > (const Rectangle& rect1);
  bool operator >= (const Rectangle& rect1);
  bool operator == (const Rectangle& rect1);
  bool operator != (const Rectangle& rect1);
  friend std::ostream& operator << (std::ostream& out, const Rectangle& rect);
  //setters
  bool setHeight(const double& height);
  bool setWidth(const double& width);
  //getters
  double getArea() const;
  rectangle_t getFrameRect() const;
  point_t getCentre() const;
  double getWidth() const;
  double getHeight() const;
  //centre point moving methods
  void move(const point_t& newPos);
  void move(const double& dx, const double& dy);
private:
  point_t pos_;
  double width_;
  double height_;
};
#endif // !RECTANGLE_H

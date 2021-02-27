#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include "shape.hpp"

class Circle : public Shape
{
public:
  Circle(const point_t pos, const double radius); //constructor
  Circle(Circle& circle1); //copy constructor
  Circle(Circle&& circle1) noexcept; //move constructor
  ~Circle(); //destructor
  //overloads
  Circle& operator = (Circle&& circle1) noexcept;
  bool operator < (const Circle& circle1);
  bool operator <= (const Circle& circle1);
  bool operator > (const Circle& circle1);
  bool operator >= (const Circle& circle1);
  bool operator == (const Circle& circle1);
  bool operator != (const Circle& circle1);
  friend std::ostream& operator << (std::ostream& out, const Circle& circle);
  //setters
  bool setRadius(const double& radius);
  //getters
  point_t getCentre() const;
  double getRadius() const;
  double getArea() const;
  rectangle_t getFrameRect() const;
  //centre point moving methods
  void move(const point_t& newPos);
  void move(const double& dx, const double& dy);
private:
  point_t pos_;
  double radius_;
};
#endif

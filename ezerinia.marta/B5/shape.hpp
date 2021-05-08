#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <vector>
#include <iostream>

struct Point {
  int x, y;
};
using Shape = std::vector< Point >;

double getSideLength(const Point &p1, const Point &p2);
bool isSideEqual(const Shape &shape);
bool compare(const Shape &lhs, const Shape &rhs);

std::istream &operator>>(std::istream &in, Point &point);
std::istream &operator>>(std::istream &in, Shape &shape);
std::ostream &operator<<(std::ostream &out, const Point &point);
std::ostream &operator<<(std::ostream &out, const Shape &shape);

#endif

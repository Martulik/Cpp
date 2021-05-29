#ifndef TASKS_HPP
#define TASKS_HPP

#include "tasks.hpp"

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

#include "functions.hpp"
#include "shape.hpp"

void razukrantov::shapeTask(std::istream& in, std::ostream& out)
{
  std::vector< Shape > shapes;
  std::copy(std::istream_iterator< Shape >(in), std::istream_iterator< Shape >(), std::back_inserter(shapes));
  unsigned int vertices = std::accumulate(shapes.begin(), shapes.end(), 0, razukrantov::sumVertices);
  unsigned int triangles = std::count_if(shapes.begin(), shapes.end(), razukrantov::isTriangle);
  unsigned int rectangles = std::count_if(shapes.begin(), shapes.end(), razukrantov::isRectangle);
  unsigned int squares = std::count_if(shapes.begin(), shapes.end(), razukrantov::isSquare);
  shapes.erase(std::remove_if(shapes.begin(), shapes.end(), razukrantov::isPentagon), shapes.end());
  std::vector< Point > points;
  std::transform(shapes.begin(), shapes.end(), std::back_inserter(points), )
}

#endif

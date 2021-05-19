#include "task2.hpp"
#include <iostream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <numeric>

namespace iva = ivanova;

int iva::task2(std::istream &in, std::ostream &out)
{
  if (!in)
  {
    std::cerr << "failed reading";
    exit(1);
  }
  std::vector< Shape > shapes((std::istream_iterator< Shape >(in)), std::istream_iterator< Shape >());
  int vert = std::accumulate(shapes.begin(), shapes.end(), 0, [](int cnt, const Shape &e){ return cnt + e.size();});
  int tri = std::count_if(shapes.begin(), shapes.end(), isTriangle);
  int sqr = std::count_if(shapes.begin(), shapes.end(), isSquare);
  int rect = std::count_if(shapes.begin(), shapes.end(), isRect);
  using cSh = const Shape;
  shapes.erase(std::remove_if(shapes.begin(), shapes.end(), [](cSh &shp){return shp.size() == 5; }), shapes.end());
  std::vector< Point > points;
  points.reserve(shapes.size());
  for(auto&& point: shapes) {
    points.emplace_back(point.front());
  }
  std::sort(shapes.begin(), shapes.end(), compare);
  out << "Vertices: " << vert << "\n";
  out << "Triangles: " << tri << '\n';
  out << "Squares: " << sqr << '\n';
  out << "Rectangles: " << rect << '\n';
  out << "Points: ";
  std::copy(points.begin(), points.end(), std::ostream_iterator< Point >(out, " "));
  out << "\nShapes:\n";
  std::copy(shapes.begin(), shapes.end(), std::ostream_iterator< Shape >(out, "\n"));
  return 0;
}

std::istream &ivanova::operator >>(std::istream &in, Shape &shp)
{
  size_t vertices = 0;
  std::string line;
  std::getline(in >> std::ws, line);
  if (line.empty())
  {
    return in;
  }
  std::istringstream iss(line);
  iss >> vertices >> std::skipws;
  if (vertices < 3)
  {
    std::cerr << "invalid input 4";
    exit(1);
  }
  size_t i =0;
  shp.reserve(vertices);
  while (i < vertices)
  {
    i++;
    Point pt;
    iss >> pt;
    shp.push_back(pt);
  }
  return in;
}

std::ostream &ivanova::operator <<(std::ostream &out, const Shape &elem)
{
  out << elem.size();
  std::copy(elem.begin(), elem.end(), std::ostream_iterator< Point >(out));
  return out;
}

bool ivanova::compare(Shape &elem1, Shape &elem2)
{
  if (isSquare(elem1))
  {
    if (isRect(elem2))
    {
      return true;
    }
  }
  return elem1.size() < elem2.size();
}


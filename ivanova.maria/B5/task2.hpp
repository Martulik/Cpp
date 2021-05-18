#ifndef B5_TASK2_HPP
#define B5_TASK2_HPP
#include <iostream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include "point.hpp"
#include "count.hpp"

namespace ivanova
{
  std::istream &operator >>(std::istream &in, Shape &shp);
  std::ostream &operator <<(std::ostream &out, const Shape &elem);
  bool compare(Shape &elem1, Shape &elem2);

  int task2(std::istream &in, std::ostream &out)
  {
    if (!in)
    {
      std::cerr << "failed reading";
      exit(1);
    }
    std::vector< Shape > shapes((std::istream_iterator< Shape >(in)), std::istream_iterator< Shape >());
    count info;
    std::for_each(shapes.begin(), shapes.end(),[&info](const Shape &elem){ info.countShape(elem); });
    using shp = const Shape;
    std::vector < Shape > temp;
    std::for_each(shapes.begin(), shapes.end(), [&temp](shp &elem){ if (!isPentagon(elem)) { temp.push_back(elem);}});
    shapes.swap(temp);
    std::vector< Point > points;
    std::for_each(shapes.begin(), shapes.end(), [&points](const Shape &elem){ points.push_back(elem[0]); });
    std::sort(shapes.begin(), shapes.end(), compare);
    out << "Vertices: " << info.vertices << "\n";
    out << "Triangles: " << info.triangles << '\n';
    out << "Squares: " << info.squares << '\n';
    out << "Rectangles: " << info.rectangles << '\n';
    out << "Points: ";
    std::copy(points.begin(), points.end(), std::ostream_iterator< Point >(out, " "));
    out << "\nShapes:\n";
    std::copy(shapes.begin(), shapes.end(), std::ostream_iterator< Shape >(out, "\n"));
    return 0;
  }
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
  Shape tmp;
  std::copy(std::istream_iterator< Point >(iss), std::istream_iterator < Point >(), std::back_inserter(tmp));
  if ((!iss && !iss.eof()) || (tmp.size() != vertices))
  {
    std::cerr << "invalid input 3";
    exit(1);
  }
  shp.swap(tmp);
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
  if (elem1.size() < elem2.size())
  {
    return true;
  }
  if (isSquare(elem1))
  {
    if (isRect(elem2))
    {
      return true;
    }
  }
  return false;
}

#endif

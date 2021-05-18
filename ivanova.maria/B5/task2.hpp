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
//  void doCount(count &shapes, std::vector < Shape > &vec);
//  void deletePentagons(std::vector < Shape > &vec);
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
//    doCount(info, shapes);
    using shp = const Shape;
    std::vector < Shape > temp;
    std::for_each(shapes.begin(), shapes.end(), [&temp](shp &elem){ if (!isPentagon(elem)) { temp.push_back(elem);}});
    shapes.swap(temp);
//    deletePentagons(shapes);
    std::vector< Point > points;
//    points.reserve(shapes.size());
    std::for_each(shapes.begin(), shapes.end(), [&points](const Shape &elem){ points.push_back(elem[0]); });
    std::sort(shapes.begin(), shapes.end(), compare);
    out << "Vertices: " << info.vertices << "\n";
    out << "Triangles: " << info.triangles << '\n';
    out << "Squares: " << info.squares << '\n';
    out << "Rectangles: " << info.rectangles << '\n';
    out << "Points: ";
//    std::ostream_iterator < Point > oit(out, " ");
    std::copy(points.begin(), points.end(), std::ostream_iterator< Point >(out, " "));
    out << "\nShapes:\n";
//    std::ostream_iterator < Shape > oits(out, "\n");
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
//  tmp.reserve(vertices);
//  std::istream_iterator < Point > isi(iss);
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
//  std::ostream_iterator< Point > oit(out);
  out << elem.size();
  std::copy(elem.begin(), elem.end(), std::ostream_iterator< Point >(out));
  return out;
}

//void ivanova::doCount(count &shapes, std::vector < Shape > &vec)
//{
//  std::for_each(vec.begin(), vec.end(),[&shapes](const Shape &elem){ shapes.countShape(elem); });
//}
//
//void ivanova::deletePentagons(std::vector < ivanova::Shape > &vec)
//{
//  using shp = const Shape;
//  std::vector < Shape > temp;
//  std::for_each(vec.begin(), vec.end(), [&temp](shp &elem){ if (!isPentagon(elem)) { temp.push_back(elem);}});
//  vec.swap(temp);
//}

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

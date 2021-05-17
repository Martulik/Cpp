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
  std::ostream &operator <<(std::ostream &out, const std::vector < Shape > &shp);
  std::ostream &operator <<(std::ostream &out, const Shape &elem);
  void doCount(count &shapes, std::vector < Shape > &vec);
  void deletePentagons(std::vector < Shape > &vec);
  bool compare(Shape &elem1, Shape &elem2);
  void print(const std::vector < Shape > &shp, const count &info, std::ostream &out);

  int task2(std::istream &in, std::ostream &out)
  {
    std::istream_iterator< Shape > isi(in);
    std::vector < Shape > shapes(isi, std::istream_iterator< Shape >());
    count info;
    doCount(info, shapes);
    deletePentagons(shapes);
    std::vector< Point > points(shapes.size());
    std::for_each(shapes.begin(), shapes.end(), [&points](const Shape &elem){ points.push_back(elem.at(0)); });
    std::sort(shapes.begin(), shapes.end(), compare);
    out << "Points: ";
    std::ostream_iterator < Point > oit(out, " ");
    out << "Vertices: " << info.vertices << "\n";
    out << "Triangles: " << info.triangles << '\n';
    out << "Rectangles: " << info.rectangles << '\n';
    out << "Squares: " << info.squares << '\n';
    out << "Points: ";
    std::copy(points.begin(), points.end(), oit);
    out << "Shapes: " << shapes;
    return 0;
  }
}

std::istream &ivanova::operator >>(std::istream &in, Shape &shp)
{
  size_t vertices = 0;
  std::string line;
  std::getline(in, line);
  if (!line.empty())
  {
  std::istringstream iss(line);
  iss >> vertices;
  std::istream_iterator < Point > isi(iss);
  shp = std::move(std::vector< Point > (isi, std::istream_iterator< Point >()));
  }
  return in;
}

std::ostream &ivanova::operator <<(std::ostream &out, const std::vector < Shape > &shp)
{
  std::ostream_iterator< Shape > oit(out);
  std::copy(shp.begin(), shp.end(), oit);
  return out;
}

std::ostream &ivanova::operator <<(std::ostream &out, const Shape &elem)
{
  std::ostream_iterator< Point > oit(out);
  std::copy(elem.begin(), elem.end(), oit);
  return out;
}


void ivanova::doCount(count &shapes, std::vector < Shape > &vec)
{
  std::for_each(vec.begin(), vec.end(),[&shapes](const Shape &elem){ shapes.countShape(elem); });
}

void ivanova::deletePentagons(std::vector < ivanova::Shape > &vec)
{
  auto it = vec.begin();
  using shp = const Shape;
  std::for_each(vec.begin(), vec.end(), [&vec, &it](shp &elem){ if (isPentagon(elem)) { vec.erase(it); } it++;});
}

bool ivanova::compare(Shape &elem1, Shape &elem2)
{
  return (elem1.size() < elem2.size());
}

void ivanova::print(const std::vector < Shape > &shp, const count &info, std::ostream &out)
{

  out << shp;
}
#endif

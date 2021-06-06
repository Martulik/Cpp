#include "tasks.hpp"

#include <numeric>
#include <functional>

#include "shape.hpp"
#include "tools.hpp"

using namespace std::placeholders;
namespace lab = shkurov;
using istreamIt = std::istream_iterator< lab::Shape >;

void lab::task2(std::istream& in, std::ostream& out)
{
  std::vector< lab::Shape > shapes;
  std::copy(istreamIt(in), istreamIt(), std::back_inserter(shapes));
  if (in.fail() && !in.eof())
  {
    throw std::invalid_argument("");
  }
  unsigned int vertices = std::accumulate(shapes.cbegin(), shapes.cend(), 0, countVertices);

  std::vector< std::function< bool(const Shape&) > > isFuncs = {isTriangle, isSquare, isRectangle};
  unsigned int counts[3];
  for (size_t i = 0; i < 3; i++)
  {
    counts[i] = std::count_if(shapes.cbegin(), shapes.cend(), isFuncs[i]);
  }

  shapes.erase(std::remove_if(shapes.begin(), shapes.end(), isPentagon), shapes.end());

  std::vector < Point > points(shapes.size());
  std::transform(shapes.cbegin(), shapes.cend(), points.begin(), getPoint);

  auto border = std::partition(shapes.begin(), shapes.end(), isTriangle);
  border = std::partition(border, shapes.end(), isSquare);
  std::partition(border, shapes.end(), isRectangle);

  out << "Vertices: " << vertices << '\n';
  out << "Triangles: " << counts[0] << '\n';
  out << "Squares: " << counts[1] << '\n';
  out << "Rectangles: " << counts[2] << '\n';
  out << "Points: ";
  std::copy(points.cbegin(), points.cend(), std::ostream_iterator< Point >(out, " "));
  out << '\n' << "Shapes:" << '\n';
  std::copy(shapes.cbegin(), shapes.cend(), std::ostream_iterator< Shape >(out, "\n"));
}

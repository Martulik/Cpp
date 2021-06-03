#include "tasks.hpp"
#include <numeric>
#include <tuple>
#include <algorithm>
#include <iterator>
#include "shape-opers.hpp"

namespace poz = pozdnyakov;

void poz::task2(std::istream& in, std::ostream& out)
{
  std::vector< poz::Shape > shapes;
  std::istream_iterator< poz::Shape > begin(in);
  std::istream_iterator< poz::Shape > eos;
  std::copy(begin, eos, std::back_inserter(shapes));
  unsigned int verticesCount = std::accumulate(shapes.cbegin(), shapes.cend(), 0, poz::sizeAccum);
  std::tuple< unsigned int, unsigned int, unsigned int > shapesCount
  {
    std::count_if(shapes.cbegin(), shapes.cend(), poz::isTriangle),
    std::count_if(shapes.cbegin(), shapes.cend(), poz::isSquare),
    std::count_if(shapes.cbegin(), shapes.cend(), poz::isRect)
  };
  shapes.erase(std::remove_if(shapes.begin(), shapes.end(), poz::compSize< 5, poz::Shape >), shapes.end());
  std::vector< poz::Point > points;
  std::transform(shapes.cbegin(), shapes.cend(), std::back_inserter(points), poz::getFirst);
  std::sort(shapes.begin(), shapes.end(), poz::comparator);
  out << "Vertices: " << verticesCount << '\n'
      << "Triangles: " << std::get< 0 >(shapesCount) << '\n'
      << "Squares: " << std::get< 1 >(shapesCount) << '\n'
      << "Rectangles: " << std::get< 2 >(shapesCount) << '\n'
      << "Points: ";
  std::copy(points.cbegin(), points.cend(), std::ostream_iterator< poz::Point >(out, " "));
  out << '\n' << "Shapes:" << '\n';
  std::copy(shapes.cbegin(), shapes.cend(), std::ostream_iterator< poz::Shape >(out, "\n"));
}

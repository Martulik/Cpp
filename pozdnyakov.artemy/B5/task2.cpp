#include "tasks.hpp"
#include <numeric>
#include "shape-opers.hpp"
#include "geo-vector.hpp"

namespace poz = pozdnyakov;

void poz::task2(std::istream& in, std::ostream& out)
{
  std::vector< poz::Shape > shapes;
  std::istream_iterator< poz::Shape > begin(in);
  std::istream_iterator< poz::Shape > eos;
  std::copy(begin, eos, std::back_inserter(shapes));
  unsigned int verticesCount = std::accumulate(shapes.cbegin(), shapes.cend(), 0, poz::sizeAccum);
  out << "Vertices: " << verticesCount << '\n';
  std::copy(shapes.begin(), shapes.end(), std::ostream_iterator< poz::Shape >(out, "\n"));
}

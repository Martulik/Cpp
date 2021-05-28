#include "tasks.h"

#include <vector>
#include <iterator>

#include "Shape.h"

void lysenko::task2(std::istream&  in, std::ostream& out)
{
  std::istream_iterator< Shape > first(in);
  std::istream_iterator< Shape > last;
  std::vector< Shape > myShapes(first, last);
}
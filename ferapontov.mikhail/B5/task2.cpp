#include "tasks.hpp"

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include "Shape.hpp"

void ferapontov::task2(std::istream& in, std::ostream& out)
{
  std::istream_iterator< Shape > begin(in);
  std::istream_iterator< Shape > end;
  std::vector< Shape > shapes(begin, end);
  if (in.fail() && !in.eof())
  {
    throw std::runtime_error("Inavalid Input");
  }
  std::copy(shapes.cbegin(), shapes.cend(), std::ostream_iterator< Shape >(out, "\n"));
}

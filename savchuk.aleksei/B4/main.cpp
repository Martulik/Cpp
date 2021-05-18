#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>

#include "data-struct.hpp"
#include "comparator.hpp"

namespace lab = savchuk;

int main()
{
  std::istream_iterator< lab::DataStruct > first(std::cin);
  std::istream_iterator< lab::DataStruct > last;
  std::vector< lab::DataStruct > v(first, last);
  if (std::cin.fail() && !std::cin.eof())
  {
    std::cerr << "Input error\n";
    return 1;
  }
  std::sort(v.begin(), v.end(), lab::compare);
  std::copy(v.begin(), v.end(), std::ostream_iterator< lab::DataStruct >(std::cout, "\n"));
}

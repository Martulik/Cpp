#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include "data-struct.hpp"

int main()
{
  std::istream_iterator< shilyaev::DataStruct > istreamIterator(std::cin);
  std::istream_iterator< shilyaev::DataStruct > lastIstreamIterator;
  std::vector< shilyaev::DataStruct > structs(istreamIterator, lastIstreamIterator);
  if (!std::cin && !std::cin.eof()) {
    return 1;
  }
  std::sort(structs.begin(), structs.end(), shilyaev::compare);
  std::ostream_iterator< shilyaev::DataStruct > ostreamIterator(std::cout, "\n");
  std::copy(structs.begin(), structs.end(), ostreamIterator);
}

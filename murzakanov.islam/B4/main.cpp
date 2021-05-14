#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

#include "data-struct.hpp"

int main()
{
  using DataStruct = murzakanov::DataStruct;
  std::vector< DataStruct > vec{std::istream_iterator< DataStruct >(std::cin), std::istream_iterator< DataStruct >()};
  if (std::cin.fail() && !std::cin.eof())
  {
    return 2;
  }
  std::sort(vec.begin(), vec.end());
  std::copy(vec.begin(), vec.end(), std::ostream_iterator< murzakanov::DataStruct >(std::cout));
}

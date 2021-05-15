#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

#include "data-struct.hpp"

int main()
{
  using DataStruct = murzakanov::DataStruct;
  std::istream_iterator< DataStruct > firstIterator(std::cin);
  std::istream_iterator< DataStruct > lastIterator;
  std::vector< DataStruct > vec(firstIterator, lastIterator);
  if (std::cin.fail() && !std::cin.eof())
  {
    return 2;
  }
  std::sort(vec.begin(), vec.end());
  std::copy(vec.begin(), vec.end(), std::ostream_iterator< DataStruct >(std::cout, "\n"));
}

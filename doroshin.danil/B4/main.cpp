#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "datastruct.hpp"

int main()
{
  using namespace doroshin;
  std::istream_iterator< DataStruct > input(std::cin);
  std::ostream_iterator< DataStruct > output(std::cout, "\n");
  std::vector< DataStruct > values;
  std::move(input, std::istream_iterator< DataStruct >(), std::back_inserter(values));
  std::sort(values.begin(), values.end(), sort_order);
  std::copy(values.begin(), values.end(), output);
  return 0;
}

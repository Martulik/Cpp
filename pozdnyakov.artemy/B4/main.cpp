#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include "data-struct.hpp"

namespace poz = pozdnyakov;

int main()
{
  std::istream_iterator< poz::DataStruct > begin(std::cin);
  std::istream_iterator< poz::DataStruct > eos;
  std::vector< poz::DataStruct > vector(begin, eos);
  std::sort(vector.begin(), vector.end(), *poz::comparator);
  std::ostream_iterator< poz::DataStruct > out(std::cout, "\n");
  std::copy(vector.begin(), vector.end(), out);
  if (std::cin.fail() && !std::cin.eof())
  {
    return -2;
  }
  return 0;
}

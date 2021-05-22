#include <iterator>
#include <vector>
#include <iostream>
#include <algorithm>

#include "data-struct.hpp"

int main()
{
  std::istream_iterator< razukrantov::DataStruct > start(std::cin);
  std::istream_iterator< razukrantov::DataStruct > finish;
  std::vector < razukrantov::DataStruct > vector(start, finish);
  if (std::cin.fail() && !std::cin.eof())
  {
    std::cerr << "Incorrect input" << "\n";
    return 1;
  }
  std::sort(vector.begin(), vector.end());
  std::ostream_iterator< razukrantov::DataStruct > out(std::cout, "\n");
  std::copy(vector.begin(), vector.end(), out);
}

#include <iostream>
#include <iterator>
#include <algorithm>
#include "DataStruct.hpp"

int main()
{
  std::istream_iterator< ferapontov::DataStruct > begin(std::cin);
  std::istream_iterator< ferapontov::DataStruct > end;
  std::vector< ferapontov::DataStruct > vec(begin, end);
  if (std::cin.fail() && !std::cin.eof())
  {
    std::cerr << "Input fail\n";
    return 1;
  }
  std::sort(vec.begin(), vec.end());
  std::copy(vec.begin(), vec.end(), std::ostream_iterator< ferapontov::DataStruct >(std::cout));
  return 0;
}

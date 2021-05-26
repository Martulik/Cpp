#include <iostream>
#include <iterator>
#include <vector>

#include "DataStruct.hpp"

namespace lab = shkurov;

int main()
{
  try
  {
    std::istream_iterator< lab::DataStruct > begin(std::cin);
    std::istream_iterator< lab::DataStruct > end;
    std::vector< lab::DataStruct > vec(begin, end);

    std::sort(vec.begin(), vec.end(), lab::compare);
    std::copy(vec.begin(), vec.end(), std::ostream_iterator< lab::DataStruct >(std::cout));
  }
  catch (const std::exception& ex)
  {
      std::cerr << ex.what() << '\n';
      return 1;
  }

  return 0;
}

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <iterator>
#include "data-struct.hpp"

namespace lab = borisova;

int main()
{
  try
  {
    std::istream_iterator< lab::DataStruct > first(std::cin);
    std::istream_iterator< lab::DataStruct > last;
    std::vector< lab::DataStruct > vector(first, last);
    if (!std::cin && !std::cin.eof())
    {
      throw std::invalid_argument("Invalid input\n");
    }
    std::sort(vector.begin(), vector.end());
    std::copy(vector.begin(), vector.end(), std::ostream_iterator< lab::DataStruct >(std::cout, "\n"));
  }
  catch (const std::invalid_argument& ex)
  {
    std::cerr << ex.what() << "\n";
    return -1;
  }
  return 0;
}

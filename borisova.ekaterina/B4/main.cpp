#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <iterator>
#include "data-struct.hpp"

namespace lab = borisova;

int main()
{
  using unInt = unsigned int;
  std::vector< lab::DataStruct > vector;
  lab::DataStruct value;
  std::string line;
  try
  {
    std::istream_iterator< lab::DataStruct > input(std::cin);
    std::vector< lab::DataStruct > vector(input, std::istream_iterator< lab::DataStruct >());
  }
  catch (const std::invalid_argument& ex)
  {
    std::cerr << ex.what() << "\n";
    return -1;
  }

  std::sort(vector.begin(), vector.end());
  std::ostream_iterator< lab::DataStruct > out(std::cout);
  std::copy(vector.begin(), vector.end(), out);
  return 0;
}

#include "tools.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "dataStruct.hpp"

namespace lab = ezerinia;


void lab::task(std::istream &in, std::ostream &out)
{
  std::istream_iterator< lab::DataStruct > input(in);
  std::vector< lab::DataStruct > vector(input, std::istream_iterator< DataStruct >());
  if (!in.fail() && ! in.eof()){
    throw std::invalid_argument("Invalid input\n");
  }
  std::sort(vector.begin(), vector.end());
  std::copy(vector.begin(), vector.end(), std::ostream_iterator< DataStruct >(out));
}

#include "tools.hpp"
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "dataStruct.hpp"

namespace lab = ezerinia;

void lab::read(std::vector< lab::DataStruct > &vector, std::istream &in)
{
  std::string line;
  while (std::getline(in, line)) {
    lab::DataStruct data;
    std::copy(std::istream_iterator< lab::DataStruct >(in),
              std::istream_iterator< DataStruct >(), std::back_inserter(vector));
  }
}

void lab::task(std::istream &in, std::ostream &out)
{
  std::vector< lab::DataStruct > vector;
  read(vector, in);
  std::sort(vector.begin(), vector.end());
  std::copy(vector.begin(), vector.end(), std::ostream_iterator< DataStruct >(out));
}

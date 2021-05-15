#ifndef B4_READVECTOR_HPP
#define B4_READVECTOR_HPP

#include <vector>
#include <iosfwd>
#include <sstream>
#include <string>

#include "struct.hpp"
#include "tools.hpp"

namespace ivanova
{
  int readVector(std::vector < DataStruct > &vector, std::istream &in)
  {
    std::istream_iterator< DataStruct > input(in);
    std::vector < DataStruct >newVector(input, std::istream_iterator< DataStruct >());
    vector = std::move(newVector);
    return 0;
  }
}
#endif

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
    std::string string;
    while (std::getline(in, string))
    {
      std::stringstream input(string);
      DataStruct data;
      input >> data;
      vector.push_back(data);
    }
    return 0;
  }
}
#endif

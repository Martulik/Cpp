#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <iostream>
#include "data-struct.hpp"

namespace murzakanov
{
  bool readDelimiter(std::istream& in, char delimiter);
  std::string readString(std::istream& in);
}

#endif

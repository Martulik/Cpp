#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <cstddef>
#include <sstream>
#include <string>
#include <iostream>

namespace murzakanov
{
  size_t getValue(size_t num);
  std::istream& readName(std::istream& in, std::string& name, std::ostream& out);
  bool checkIsNum(const std::string& number);
}

#endif

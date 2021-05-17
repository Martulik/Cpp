#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <iosfwd>
#include <string>

namespace savchuk
{
  int readKey(std::istream& is, char delim);
  std::string readString(std::istream& is);
}

#endif

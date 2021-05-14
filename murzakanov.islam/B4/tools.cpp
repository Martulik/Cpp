#include "tools.hpp"
#include <iostream>

std::string murzakanov::readString(std::istream& in)
{
  std::string result;
  in >> std::ws;
  getline(in, result, '\n');
  if (result == "")
  {
    std::cerr << "Empty line\n";
    std::exit(1);
  }
  return result;
}

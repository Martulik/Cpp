#include <iostream>
#include <string>

#include "tools.hpp"
#include "data-struct.hpp"

bool murzakanov::readDelimiter(std::istream& in, char delimiter)
{
  in >> std::ws;
  if (in.peek() != delimiter)
  {
    in.setstate(std::istream::failbit);
    return false;
  }
  char c;
  in >> c;
  return true;
}

std::string murzakanov::readString(std::istream& in)
{
  std::string result;
  in >> std::ws;
  getline(in, result, '\n');
  return result;
}

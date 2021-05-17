#include "functions.hpp"

#include <iostream>

int pochernin::getKey(std::istream& in)
{
  std::string str;
  std::getline(in, str, ',');
  int key = 0;
  try
  {
    key = std::stoi(str);
  }
  catch (std::exception& error)
  {
    in.setstate(std::ios::failbit);
    return 0;
  }
  if (std::abs(key) > 5)
  {
    in.setstate(std::ios::failbit);
    return 0;
  }
  return key;
}

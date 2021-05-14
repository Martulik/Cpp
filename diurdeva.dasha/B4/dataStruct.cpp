#include "dataStruct.hpp"
#include <sstream>
#include <iostream>

std::istream& diurdeva::operator>>(std::istream& in, DataStruct& dataStruct)
{
  char separator;
  std::string str;
  std::getline(in, str);
  std::istringstream input(str);

  input >> dataStruct.key1;
  if (!input.fail()) {
    input >> separator;
    if (input.fail() || separator != ',') {
      in.setstate(std::ios::failbit);
      return in;
    }
    input >> dataStruct.key2;
    if (!input.fail()) {
      input >> separator;
    }
  }

  if (input.fail() || separator != ',' || abs(dataStruct.key1) > 5 || abs(dataStruct.key2) > 5)
  {
    in.setstate(std::ios::failbit);
    return in;
  }

  if (!input.eof()) {
    std::getline(input, dataStruct.str);
  }

  return in;
}

std::ostream& diurdeva::operator<<(std::ostream& cout, const DataStruct& data)
{
  return cout << data.key1 << "," << data.key2 << "," << data.str;
}

bool diurdeva::compare(const DataStruct& lhs, const DataStruct& rhs)
{
  if (lhs.key1 != rhs.key1)
  {
    return lhs.key1 < rhs.key1;
  }
  if (lhs.key2 != rhs.key2)
  {
    return lhs.key2 < rhs.key2;
  }
  return lhs.str.size() < rhs.str.size();
}

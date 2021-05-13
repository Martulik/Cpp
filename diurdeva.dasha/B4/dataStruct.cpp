#include "dataStruct.hpp"
#include <iostream>

std::istream& diurdeva::operator>>(std::istream& in, DataStruct& dataStruct)
{
  char separator;
  in >> dataStruct.key1;
  if (!in.fail()) {
    in >> separator;
    if (!in.fail() && separator == ',') {
      in >> dataStruct.key2;
      if (!in.fail()) {
        in >> separator;
      }
    }
  }
  if (in.fail() || separator != ',' || abs(dataStruct.key1) > 5 || abs(dataStruct.key2) > 5) {
    throw std::invalid_argument("Invalid input\n");
  }
  if (!in.eof()) {
    std::getline(in, dataStruct.str);
  }
  return in;
}

std::ostream& diurdeva::operator<<(std::ostream& cout, const DataStruct& data)
{
  cout << data.key1 << "," << data.key2 << "," << data.str << "\n";
  return cout;
}

bool diurdeva::compare(DataStruct& lhs, DataStruct& rhs)
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

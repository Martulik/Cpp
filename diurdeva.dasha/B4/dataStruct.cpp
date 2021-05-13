#include "dataStruct.hpp"
#include <iostream>

std::istream& diurdeva::operator>>(std::istream& in, DataStruct& dataStruct)
{
  char separator;
  in >> dataStruct.key1;
  in >> separator;

  if (separator != ',')
  {
    throw std::invalid_argument("Invalid first separator\n");
  }

  in >> dataStruct.key2;
  in >> separator;

  if (separator != ',')
  {
    throw std::invalid_argument("Invalid second separator\n");
  }

  getline(in, dataStruct.str);

  if (dataStruct.str.empty())
  {
    throw std::invalid_argument("Third argument is empty\n");
  }

  if ((abs(dataStruct.key1) > 5) || (abs(dataStruct.key2) > 5))
  {
    throw std::out_of_range("Values out of range\n");
  }

  return in;
}

std::ostream& diurdeva::operator<<(std::ostream& cout, const DataStruct& data)
{
  return cout << data.key1 << "," << data.key2 << "," << data.str;
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

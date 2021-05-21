#include "data-struct.hpp"
#include <iostream>
#include <string>

const int MIN_VALUE = -5;
const int MAX_VALUE = 5;
const char SEPARATOR = ',';


std::ostream& dushechkina::operator<<(std::ostream& out, const dushechkina::DataStruct& data)
{
  out << data.key1 << SEPARATOR << data.key2 << SEPARATOR << data.str;
  return out;
}

std::istream& dushechkina::operator>>(std::istream& in, dushechkina::DataStruct& data)
{
  
}

bool dushechkina::operator<(const DataStruct& first, const DataStruct& second)
{
  if (first.key1 != second.key1)
  {
    return (first.key1 < second.key1);
  }
  if (first.key2 != second.key2)
  {
    return (first.key2 < second.key2);
  }
  else
  {
    return (first.str.size() < second.str.size());
  }
}

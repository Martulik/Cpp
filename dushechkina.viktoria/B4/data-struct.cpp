#include "data-struct.hpp"
#include <iosfwd>
#include <sstream>
#include <string>

const int MIN = -5;
const int MAX = 5;
const char COMMA = ',';


std::ostream& dushechkina::operator<<(std::ostream& out, const dushechkina::DataStruct& data)
{
  out << data.key1 << COMMA << data.key2 << COMMA << data.str;
  return out;
}

std::istream& dushechkina::operator>>(std::istream& in, dushechkina::DataStruct& data)
{
  std::string line;
  std::istringstream input(line);
  char sep;
  input >> data.key1;
  if (!input.fail())
  {
    input >> sep;
    if (input.fail() || sep != COMMA)
    {
      throw std::invalid_argument("Invalid input or separator not a comma\n");
    }
    else
    {
      input >> data.key2;
      if (!input.fail())
      {
        input >> sep;
      }
    }
    if (sep != COMMA || data.key1 < MIN || data.key1 > MAX || data.key2 < MIN || data.key2 > MAX || input.fail())
    {
      throw std::invalid_argument("Invalid input\n");
    }
    if (!input.eof())
    {
      getline(input, data.str);
    }
  }
  return in;
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

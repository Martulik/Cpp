#include "data-struct.hpp"
#include <iosfwd>
#include <sstream>
#include <string>

constexpr int MIN = -5;
constexpr int MAX = 5;
constexpr char COMMA = ',';

std::ostream& dushechkina::operator<<(std::ostream& out, const dushechkina::DataStruct& data)
{
  out << data.key1 << COMMA << data.key2 << COMMA << data.str;
  return out;
}

std::istream& dushechkina::operator>>(std::istream& in, dushechkina::DataStruct& data)
{
  std::string line;
  std::getline(in, line);
  std::istringstream input(line);
  char sep = '\0';
  input >> data.key1;
  if (!input.fail()) {
    input >> sep;
    if (input.fail() || sep != COMMA) {
      in.setstate(std::ios::failbit);
      return in;
    }
    input >> data.key2;
    if (!input.fail()) {
      input >> sep;
    }
  }
  if (input.fail() || sep != COMMA || data.key1 > MAX || data.key2 > MAX || data.key1 < MIN || data.key2 < MIN)
  {
    in.setstate(std::ios::failbit);
    return in;
  }

  if (!input.eof()) {
    std::getline(input, data.str);
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

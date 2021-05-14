#include "data-struct.hpp"
#include <iosfwd>
#include <sstream>

namespace lab = borisova;

bool lab::operator<(const DataStruct& temp1, const DataStruct& temp2)
{
  if (temp1.key1 == temp2.key1)
  {
    if (temp1.key2 == temp2.key2)
    {
      return (temp1.str.length() < temp2.str.length());
    }
    else
    {
      return (temp1.key2 < temp2.key2);
    }
  }
  else
  {
    return (temp1.key1 < temp2.key1);
  }
}

std::istream& lab::operator>>(std::istream& in, DataStruct& data)
{
  std::string line;
  if (!getline(in, line))
  {
    return in;
  }
  std::istringstream input(line);
  char comma;
  input >> data.key1;
  if (!input.fail())
  {
    input >> comma;
    if (input.fail() || comma != ',')
    {
      throw std::invalid_argument("Invalid input or without comma\n");
    }
    else
    {
      input >> data.key2;
      if (!input.fail())
      {
        input >> comma;
      }
    }
    if (input.fail() || comma != ',' || data.key1 < -5 || data.key1 > 5 || data.key2 < -5 || data.key2 > 5)
    {
      throw std::invalid_argument("Invalid input\n");
    }
    if (!input.eof())
    {
      getline(input, data.str);
      if (data.str.empty())
      {
        throw std::invalid_argument("empty str\n");
      }
    }
    else
    {
      throw std::invalid_argument("end of file\n");
    }
  }
  return in;
}

std::ostream& lab::operator<<(std::ostream& out, const DataStruct& value)
{
  out << value.key1 << "," << value.key2 << "," << value.str;
  return out;
}

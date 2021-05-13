#include "data-struct.hpp"
#include <iostream>

namespace lab = borisova;

bool lab::isCorrect(const std::string& line)
{
  if (line[line.length() - 1] == ',')
  {
    for (size_t i = 0; i < line.length() - 1; i++)
    {
      if (!isdigit(line[i]))
      {
        if (i != 0 && line[i] != '-')
        {
          return false;
        }
      }
    }
    return true;
  }
  return false;
}

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
  DataStruct value;
  std::string key1;
  std::string key2;
  std::string str;
  if (in)
  {
    in >> key1;
    bool code = isCorrect(key1);
    if (code)
    {
      value.key1 = std::stoi(key1);
      in >> key2;
      code = isCorrect(key2);
      if (code)
      {
        value.key2 = std::stoi(key2);
        in >> std::ws;
        getline(in, value.str, '\n');

        if (value.key1 > -5 && value.key1 < 5 && value.key2 > -5 && value.key2 < 5)
        {
          data = {value.key1, value.key2, value.str};
        }
        else
        {
          throw std::invalid_argument("Invalid input\n");
        }
      }
      else
      {
        throw std::invalid_argument("Invalid input\n");
      }
    }
    else
    {
      throw std::invalid_argument("Invalid input\n");
    }
  }
  return in;
}

std::ostream& lab::operator<<(std::ostream& out, const DataStruct& value)
{
  out << value.key1 << " " << value.key2 << " " << value.str << '\n';
  return out;
}

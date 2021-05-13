#include "data-struct.hpp"
#include <iostream>

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
  DataStruct value;
  int key1;
  int key2;
  std::string str;
  char comma;
  if (in)
  {
    in >> key1;
    if (!in.fail())
    {
      in >> comma;
      if (comma != ',')
      {
        throw std::invalid_argument("Miss comma\n");
      }
      value.key1 = key1;
      in >> key2;
      if (!in.fail())
      {
        in >> comma;
        if (comma != ',')
        {
          throw std::invalid_argument("Miss comma\n");
        }
        value.key2 = key2;
        in >> std::ws;
        getline(in, value.str, '\n');
        if (value.str.empty())
        {
          throw std::invalid_argument("str is empty\n");
        }
      }
    }
    if (!in.fail() && value.key1 >= -5 && value.key1 <= 5 && value.key2 >= -5 && value.key2 <= 5)
    {
      data = { value.key1, value.key2, value.str };
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
  out << value.key1 << "," << value.key2 << "," << value.str << '\n';
  return out;
}

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
  char comma;
  in >> data.key1;
  if (!in.fail())
  {
    in >> comma;
    if (!in.fail() && comma == ',')
    {
      in >> data.key2;
      if (!in.fail())
      {
        in >> comma;

      }
    }
    if (!in.fail() && comma != ',' && data.key1 < -5 && data.key1 > 5 && data.key2 < -5 && data.key2 > 5)
    {
      throw std::invalid_argument("Invalid input\n");
    }
    else
    {
      if (!in.eof())
      {
        getline(in, data.str, '\n');
      }    
    }
  }
  return in;
}

std::ostream& lab::operator<<(std::ostream& out, const DataStruct& value)
{
  out << value.key1 << "," << value.key2 << "," << value.str << '\n';
  return out;
}

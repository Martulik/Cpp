#include "struct.hpp"
#include <iostream>
#include <sstream>
#include "tools.hpp"

std::istream &ivanova::operator >>(std::istream &input, ivanova::DataStruct &data)
{
  std::string string;
  std::getline(input, string);
  std::istringstream in(string);
  if (string.empty())
  {
    return input;
  }
  char separator = ' ';
  in >> data.key1;
  if (!in.fail())
  {
    in >> separator;
    if (in.fail() || separator != ',')
    {
      std::cerr << "Invalid separator";
      exit(1);
    }
    else if (separator == ',')
    {
      in >> data.key2;
      if (in.fail())
      {
        std::cerr << "1Invalid input";
        exit(1);
      }
      in >> separator;
      if (in.fail() || separator != ',')
      {
        std::cerr << "Invalid separator";
        exit(1);
      }
    }
  }
  if ((in.fail() || std::abs(data.key1) > 5 || std::abs(data.key2) > 5))
  {
    std::cerr << "2Invalid input";
    exit(1);
  }
  if (!in.eof())
  {
    std::getline(in, data.str);
  }
  return input;
}

std::ostream &ivanova::operator <<(std::ostream &out, const ivanova::DataStruct &data)
{
  out << data.key1 << "," << data.key2 << "," << data.str << '\n';
  return out;
}


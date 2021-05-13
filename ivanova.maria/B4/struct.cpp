#include "struct.hpp"
#include "tools.hpp"

std::istream &ivanova::operator >>(std::istream &in, ivanova::DataStruct &data)
{
  char separator = ' ';
  in >> data.key1;
  if (!in.fail())
  {
    in >> separator;
    if (in.fail() && separator != ',')
    {
      std::cerr << "Invalid separator";
      exit(1);
    }
    else if (separator == ',')
    {
      in >> data.key2;
      if (in.fail())
      {
        std::cerr << "Invalid input";
        exit(1);
      }
      in >> separator;
      if (in.fail() && separator != ',')
      {
        std::cerr << "Invalid separator";
        exit(1);
      }
    }
  }
  if ((in.fail() || std::abs(data.key1) > 5 || std::abs(data.key2) > 5))
  {
    std::cerr << "Ivalid input";
    exit(1);
  }
  if (!in.eof())
  {
    std::getline(in, data.str);
  }
  return in;
}

std::ostream &ivanova::operator <<(std::ostream &out, ivanova::DataStruct &data)
{
  out << data.key1 << "," << data.key2 << "," << data.str << std::endl;
  return out;
}

bool ivanova::empty(ivanova::DataStruct &data)
{
  if (data.str.empty())
  {
    return true;
  }
  return false;
}

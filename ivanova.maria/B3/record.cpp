#include "record.hpp"
#include <sstream>
namespace iva = ivanova;

std::istream &iva::operator >>(std::istream &in, ivanova::Record &info)
{
  std::string number;
  in >> std::ws >> number;
  if (number.empty() || !checkNumber(number))
  {
    return in;
  }
  else
  {
    info.data.first = number;
  }
  std::string name;
  std::getline(in >> std::ws, name);
  if (name.empty() || name.front() != '\"')
  {
    return in;
  }
  name.erase(name.begin());
  size_t i;
  for (i = 0; (i < name.size()) && (name[i] != '\"'); i++)
  {
    if (name[i] == '\\')
    {
      if ((name[i + 1] == '\"') && (i + 2 < name.size()))
      {
        name.erase(i, 1);
      }
      else
      {
        return in;
      }
    }
  }
  if (i == name.size())
  {
    return in;
  }
  name.erase(i);
  if (name.empty())
  {
    return in;
  }
  if (name.empty())
  {
    return in;
  }
  if ((!name.empty()) && (name.back() == '\r'))
  {
    name.pop_back();
  }
  info.data.second = name;
  return in;
}

std::ostream &ivanova::operator <<(std::ostream &out, const ivanova::Record &info)
{
  out << info.data.first << " " << info.data.second << std::endl;
  return out;
}

bool iva::checkNumber(const std::string &number)
{
  if (number.empty())
  {
    return false;
  }
  for (char i: number)
  {
    if (!std::isdigit(i))
    {
      return false;
    }
  }
  return true;
}


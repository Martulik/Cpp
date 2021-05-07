#include "record.hpp"

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
  if (name.empty())
  {
    return in;
  }
  if ((!name.empty()) && (name.back() == '\r'))
  {
    name.pop_back();
  }
  name = ivanova::getName(name);
  info.data.second = name;
  return in;
}

std::ostream &ivanova::operator<<(std::ostream &out, ivanova::Record &info)
{
  out << info.data.first << " " << info.data.second;
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

std::string iva::getName(const std::string &name)
{
  if (name.empty())
  {
    return "";
  }
  if (name.front() != '\"')
  {
    return "";
  }
  std::string str = name;
  str.erase(name.begin());
  size_t i;
  for (i = 0; (i < str.size()) && (str[i] != '\"'); i++)
  {
    if (str[i] == '\\')
    {
      if ((str[i + 1] == '\"') && (i + 2 < str.size()))
      {
        str.erase(i, 1);
      }
      else
      {
        return "";
      }
    }
  }
  if (i == str.size())
  {
    return "";
  }
  str.erase(i);
  if (str.empty())
  {
    return "";
  }
  return str;
}

bool iva::checkMark(const std::string &mark)
{
  if (mark.empty())
  {
    return false;
  }
  for (char i: mark)
  {
    if ((!std::isalnum(i)) && (i != '-'))
    {
      return false;
    }
  }
  return true;
}

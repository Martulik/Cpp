#include "tools.hpp"
#include <sstream>
namespace iva = ivanova;

bool iva::compare(DataStruct &data1, DataStruct &data2)
{
  if (data1.key1 > data2.key1)
  {
    return true;
  }
  else if (data1.key1 == data2.key1)
  {
    if (data1.key2 > data2.key2)
    {
      return true;
    }
    else if (data1.key2 == data2.key2)
    {
      if (data1.str.length() > data2.str.length())
      {
        return true;
      }
      else return false;
    }
    else return false;
  }
  else return false;
}

iva::DataStruct iva::getVector(std::string &str)
{
  if (str.empty() || str.length() < 5)
  {
    std::cerr << "Invalid input";
    exit(1);
  }
  DataStruct data;
  size_t i = 0;
  std::string key1;
  while (i < str.length() && str.at(i) != ',')
  {
    key1 += str.at(i);
    i++;
  }
  if (!checkInt(key1))
  {
    std::cerr << "Ivalid input";
    exit(1);
  }
  i++;
  std::string key2;
  while (i < str.length() && str.at(i) == ' ')
  {
    i++;
  }
  while (i < str.length() && str.at(i) != ',')
  {
    key2 += str.at(i);
    i++;
  }
  if (!checkInt(key2))
  {
    std::cerr << "invalid input";
    exit(1);
  }
  i++;
  std::string string;
  while (i < str.length() && str.at(i) == ' ')
  {
    i++;
  }
  while (i < str.length())
  {
    string += str.at(i);
    i++;
  }
  if (string.empty())
  {
    std::cerr << "missing string";
    exit(1);
  }
  return {std::stoi(key1), std::stoi(key2), string};
}

bool ivanova::checkInt(std::string &str)
{
  size_t i = 0;
  if (str.at(i) == '-' || str.at(i) == '+')
  {
    while (size_t k = i + 1 < str.length())
    {
      if (!std::isdigit(str.at(k)))
      {
        return false;
      }
      k++;
    }
    if (std::abs(std::stoi(str)) > 5)
    {
      return false;
    }
  }
  else
  {
    while (i < str.length())
    {
      if (!std::isdigit(str.at(i)))
      {
        return false;
      }
      i++;
    }
    if (std::abs(std::stoi(str)) > 5)
    {
      return false;
    }
  }
  return true;
}

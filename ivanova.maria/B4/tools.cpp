#include "tools.hpp"

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
  iva::DataStruct data;
  std::string key;
  size_t i = 0;
  while (isdigit(str.at(i)))
  {
    key += str.at(i);
    i++;
  }
  iva::checkSymbol(str.at(i));
  data.key1 = std::move(std::stoi(key));
  while (isdigit(str.at(i)))
  {
    key += str.at(i);
    i++;
  }
  iva::checkSymbol(str.at(i));
  data.key2 = std::move(std::stoi(key));
  while (i < str.size())
  {
    key += str.at(i);
    i++;
  }
  if (!key.empty())
  {
    data.str = std::move(key);
    return data;
  }
  else
  {
    std::cerr << " Missing String";
    exit(1);
  }
}


void ivanova::checkSymbol(char &s)
{
  if (s != ',')
  {
    std::cerr << "Invalid Separator";
    exit(1);
  }
  else if (abs(std::atoi(&s)) > 5)
  {
    std::cerr << "key must be in range of -5 to 5\n";
    exit(1);
  }
}

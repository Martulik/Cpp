#include "tools.hpp"

bool ivanova::compare(DataStruct &data1, DataStruct &data2)
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

template< typename T >
bool ivanova::getVector(std::string &str, std::vector< T > &vec)
{
  DataStruct data;
  std::string key;
  size_t i = 0;
  while (str.at(i) != ',')
  {
    key += str.at(i);
    i++;
  }
  i++;
  if (abs(std::stoi(key) > 5))
  {
    std::cerr << "key1 must be in range of -5 to 5\n";
    return false;
  }
  else
  {
    data.key1 = std::move(std::stoi(key));
  }
  key.clear();
  while (str.at(i) != ',')
  {
    key += str.at(i);
    i++;
  }
  i++;
  if (abs(std::stoi(key)) > 5)
  {
    std::cerr << "key2 must be in range of -5 tp 5\n";
    return false;
  }
  else
  {
    data.key2 = std::move(std::stoi(key));
    key.clear();
    while (i < str.size())
    {
      data.str += str.at(i);
      i++;
    }
    vec.push_back(data);
  }
  return true;
}

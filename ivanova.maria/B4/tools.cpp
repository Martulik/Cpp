#include "struct.hpp"
#include <iostream>
#include <string>
#include <vector>
namespace ivanova
{
  template < typename T > void getVector(std::string &str, std::vector < T > &vec)
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
  }
}

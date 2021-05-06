#include "struct.hpp"
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
namespace ivanova
{
  template < typename T > void getVector(std::stringstream &input, std::vector < T > &vec)
  {
    DataStruct data;
    std::string str;
    std::string key;
    size_t i = 0;
    input >> str;
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
      while (i < str.length())
      {
        key += str.at(i);
        i++;
      }
      data.str = std::move(key);
      vec.push_back(data);
    }
  }
}

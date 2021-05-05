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
    std::string key;
    input >> std::ws >> key;
    if (abs(std::stoi(key) > 5))
    {
      std::cerr << "key1 must be in range of -5 to 5\n";
    }
    else
    {
      data.key1 = std::move(std::stoi(key));
    }
    input >> key;
    if (abs(std::stoi(key)) > 5)
    {
      std::cerr << "key2 must be in range of -5 tp 5\n";
    }
    else
    {
      data.key2 = std::move(std::stoi(key));
      input >> data.str;
      vec.push_back(data);
    }
  }
}

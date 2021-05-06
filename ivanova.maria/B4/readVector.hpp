#ifndef B4_READVECTOR_HPP
#define B4_READVECTOR_HPP

#include <vector>
#include <iostream>
#include <string>

#include "struct.hpp"
#include "tools.hpp"

namespace ivanova
{
  template < typename T >
  bool readVector(std::vector < T > &vector)
  {
    std::string str;
    while (std::getline(std::cin, str))
    {
      if (std::cin.fail())
      {
        std::cerr << "Read fail";
        return false;
      }
      else
      {
        if (str.empty())
        {
          return true;
        }
        else
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
            vector.push_back(data);
          }
//          return getVector(str, vector);
        }
      }
    }
    if (!std::cin.eof())
    {
      std::cerr << "Failed reading";
      return false;
    }
    return true;
  }
}
#endif

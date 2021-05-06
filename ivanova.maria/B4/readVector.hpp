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
          vector.push_back(getVector(str));
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

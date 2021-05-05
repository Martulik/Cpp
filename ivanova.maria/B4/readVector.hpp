#ifndef B4_READVECTOR_HPP
#define B4_READVECTOR_HPP

#include <vector>
#include <iostream>
#include <sstream>
#include <string>

#include "struct.hpp"
#include "tools.cpp"

namespace ivanova
{
  template < typename T > int readVector(std::vector < T > &vector )
  {
    std::string str;
    while (std::getline(std::cin, str))
    {
      if (std::cin.fail())
      {
        std::cerr << "Read fail";
      }
      else
      {
        std::stringstream input(str);
        getVector(input, vector);
      }
    }
    if (!std::cin.eof())
    {
      std::cerr << "Failed reading";
      return 1;
    }
    return 0;
  }
}
#endif

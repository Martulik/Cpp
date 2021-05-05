#include "readVector.hpp"
#include "struct.hpp"
#include "tools.cpp"
#include <iostream>
#include <vector>
#include <sstream>
namespace iva = ivanova;

template < typename T > int iva::task1(std::vector < T > &vector)
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
      iva::getVector(input, vector);
    }
  }
  if (!std::cin.eof())
  {
    std::cerr << "Failed reading";
    return 1;
  }
  return 0;
}

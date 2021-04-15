#ifndef TASK4_HPP
#define TASK4_HPP

#include <iostream>
#include "functions.hpp"

namespace ivanova
{
  int task4(const char *method, const int size)
  {
    int exitCode = 0;
    if (size < 0)
    {
      exitCode = 1;
    }
    else
    {
      std::vector<double> vec(size);
      fillRandom(vec.data(), size);
      print(vec, std::cout);
      sortAndPrint<strategyBrackets<double> >(vec, method);
    }
    return exitCode;
  }
}
#endif

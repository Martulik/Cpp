#ifndef TASK4_HPP
#define TASK4_HPP

#include <iostream>
#include "tasks.hpp"
#include "functions.hpp"

namespace iva = ivanova;

int iva::task4(const char *method, const int size)
{
  if (size < 0)
  {
    return 1;
  }
  else
  {
    std::vector<double> vec(size);
    iva::fillRandom(vec.data(), size);
    iva::print(vec, std::cout);
    iva::sortAndPrint<iva::strategyBrackets<double> >(vec, method);
  }
  return 0;
}
#endif

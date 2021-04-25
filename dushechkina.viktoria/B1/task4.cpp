#include <forward_list>
#include <fstream>
#include <functional>
#include <iostream>
#include <vector>

#include "tasks.hpp"
#include "functions.hpp"
#include "sort.hpp"

void task4(std::function<bool(const double&, const double&)> compar, int size)
{
  if (size <= 0)
  {
    throw std::invalid_argument("Incorrect size provided");
  }
  std::vector<double> vector(size);
  dushechkina::fillRandom(vector.data(), size);
  dushechkina::print(vector, " ");
  std::cout << std::endl;
  dushechkina::sort<At>(vector, compar);
  dushechkina::print(vector, " ");
}

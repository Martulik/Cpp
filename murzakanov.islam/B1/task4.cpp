#include <string>
#include <iostream>
#include "sorting.hpp"
#include "strategy.hpp"
#include "tools.hpp"
#include "tasks.hpp"

int murzakanov::task4(std::string& order, int size)
{
  if (order != "ascending" && order != "descending")
  {
    std::cerr << "Wrong order";
    return 1;
  }
  double* arr = new double[size];
  murzakanov::fillRandom(arr, size);
  std::vector< double > vec(arr, arr + size);
  murzakanov::print< std::vector< double> >(vec, std::cout);
  murzakanov::sort< murzakanov::StrategyBrackets< double > >(vec, order);
  murzakanov::print< std::vector< double > >(vec, std::cout);
  return 0;
}

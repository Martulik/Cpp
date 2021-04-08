#include <string>
#include <iostream>
#include "sorting.hpp"
#include "strategy.hpp"
#include "tools.hpp"
#include "tasks.hpp"



void murzakanov::task4(std::string& order, int size)
{
  double* arr = new double[size];
  murzakanov::fillRandom(arr, size);
  std::vector< double > vec(arr, arr + size);
  murzakanov::print< std::vector< double> >(vec, std::cout);
  murzakanov::sort< murzakanov::StrategyBrackets< double > >(vec, order);
  murzakanov::print< std::vector< double > >(vec, std::cout);
}

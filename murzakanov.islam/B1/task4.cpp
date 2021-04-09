#include "tasks.hpp"

#include <string>
#include <iostream>
#include <memory>

#include "sorting.hpp"
#include "strategy.hpp"
#include "tools.hpp"

int murzakanov::task4(std::string& order, int size)
{
  if (order != "ascending" && order != "descending")
  {
    std::cerr << "Wrong order\n";
    return 1;
  }
  std::unique_ptr< double > arr = std::make_unique< double >(size);
  murzakanov::fillRandom(arr.get(), size);
  std::vector< double > vec(arr.get(), arr.get() + size);
  murzakanov::sort< murzakanov::StrategyBrackets< double > >(vec, order);
  murzakanov::print< std::vector< double > >(vec, std::cout);
  return 0;
}

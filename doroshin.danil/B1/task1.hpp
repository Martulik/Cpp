#ifndef TASK1_HPP
#define TASK1_HPP

#include <iostream>
#include "insert-sort.hpp"
#include "sort-strategies.hpp"

namespace doroshin
{
  template< typename Strat, typename Cmp >
  void task1(typename Strat::container_t values, Cmp cmp)
  {
    insert_sort< int, Strat >(values, cmp);
    for(int num: values) {
      std::cout << num << ' ';
    }
    std::cout << '\n';
  }
}

#endif //TASK1_HPP

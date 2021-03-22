#ifndef TASK1_HPP
#define TASK1_HPP

#include <iostream>
#include "insert-sort.hpp"
#include "sort-strategies.hpp"

namespace doroshin
{
  template< typename Strat, Ordering::Way order >
  void doSort(typename Strat::container_t values)
  {
    insert_sort< int, Strat, Ordering::ordering_op< order > >
        (values, Strat::begin(values), Strat::end(values));
    for(int num: values) {
      std::cout << num << ' ';
    }
    std::cout << '\n';
  }
}

#endif //TASK1_HPP

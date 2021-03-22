#ifndef TASK1_HPP
#define TASK1_HPP

#include <iostream>
#include "insert-sort.hpp"
#include "sort-strategies.hpp"

namespace dan = doroshin;

template< typename Strat, dan::Ordering::Way order >
void doSort(typename Strat::container_t values)
{
  dan::insert_sort< int, Strat, dan::Ordering::ordering_op< order > >
      (values, Strat::begin(values), Strat::end(values));
  for(int num: values) {
    std::cout << num << ' ';
  }
  std::cout << '\n';
}

#endif //TASK1_HPP

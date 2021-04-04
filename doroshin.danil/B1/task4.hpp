#ifndef TASK4_HPP
#define TASK4_HPP

#include <iostream>
#include <iomanip>
#include <vector>
#include "insert-sort.hpp"
#include "sort-strategies.hpp"

namespace doroshin
{
  void fillRandom(double* array, size_t size);

  template< typename Cmp >
  void testRandom(const size_t size, Cmp cmp)
  {
    std::vector< double > array(size);
    fillRandom(array.data(), array.size());
    std::cout << std::fixed << std::setprecision(5);
    for(size_t i = 0; i < size; ++i) {
      std::cout << array[i] << ' ';
    }
    std::cout << '\n';
    insert_sort< double, VectorIndexStrat< double > >
      (array, VectorIndexStrat< double >::begin(array), VectorIndexStrat< double >::end(array), cmp);
    for(size_t i = 0; i < size; ++i) {
      std::cout << array[i] << ' ';
    }
    std::cout << '\n';
  }
}

#endif //TASK4_HPP

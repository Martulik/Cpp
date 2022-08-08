#ifndef TASK1_HPP
#define TASK1_HPP

#include <vector>
#include <forward_list>
#include "tools.hpp"
#include "errors.hpp"

namespace ezerinia {
  template< typename C >
  error task1(const C sort_mode)
  {
    std::vector< int > collection_numbers;
    int number = 0;
    while (std::cin && !(std::cin >> number).eof()) {
      if (std::cin.fail() || std::cin.bad()) {
        return error::input;
      }
      collection_numbers.push_back(number);
    }

    std::vector< int > index(collection_numbers);
    sortAndPrint< indexVec< int > >(index, sort_mode, std::cout);

    std::vector< int > at(collection_numbers);
    sortAndPrint< atVec< int > >(at, sort_mode, std::cout);

    std::forward_list< int > iter(collection_numbers.begin(), collection_numbers.end());
    sortAndPrint< iteratorList< int > >(iter, sort_mode, std::cout);

    return error::success;
  }
}
#endif

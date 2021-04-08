#include "task-sort.hpp"
#include <iostream>
#include <vector>
#include <forward_list>
#include "compare-function.hpp"
#include "access-strategies.hpp"
#include "iterator-print.hpp"
#include "sort.hpp"

namespace shilyaev {

  void inputVector(std::vector< int > &vector)
  {
    int input;
    while (std::cin >> input) {
      vector.push_back(input);
    }
  }

  template < typename AccessStrategy >
  void printSorted(typename AccessStrategy::Collection collection, const std::function< bool(int, int) > &compare)
  {
    bubbleSort< AccessStrategy >(collection, compare);
    print(collection.cbegin(), collection.cend());
  }

  int doTask(const std::function< bool(int, int) > &compare)
  {
    std::vector< int > vector;
    inputVector(vector);
    if (std::cin.fail() && !std::cin.eof()) {
      std::cerr << "Error while reading";
      return 1;
    }
    std::forward_list< int > list(vector.cbegin(), vector.cend());

    printSorted< VectorBracketsStrategy< int > >(vector, compare);
    printSorted< VectorAtStrategy< int > >(vector, compare);
    printSorted< ForwardListIteratorStrategy< int > >(list, compare);
    return 0;
  }

  int taskSort(int argc, char *argv[])
  {
    if (argc != 3) {
      std::cerr << "Invalid argument count";
      return 1;
    }
    using Item = int;
    using Compare = std::function< bool(Item, Item) >;
    boost::optional< Compare > compare = getCompareFunction< Item >(argv[2]);
    if (!compare) {
      std::cerr << "Invalid sorting order";
      return 1;
    }
    return doTask(*compare);
  }

}

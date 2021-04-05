#include "task-sort.hpp"
#include <iostream>
#include <vector>
#include <forward_list>
#include "order-strategies.hpp"
#include "access-strategies.hpp"
#include "iterator-utils.hpp"
#include "sort.hpp"

namespace shilyaev {

  void inputVector(std::vector< int > &vector)
  {
    int input;
    while (std::cin >> input) {
      vector.push_back(input);
    }
  }

  template < typename AccessStrategy, typename Order >
  void printSorted(typename AccessStrategy::Collection collection)
  {
    bubbleSort< AccessStrategy, Order >(collection);
    print(collection.begin(), collection.end());
  }

  template < typename Order >
  void doTask()
  {
    std::vector< int > vector;
    inputVector(vector);
    std::forward_list< int > list(vector.begin(), vector.end());

    printSorted< VectorBracketsStrategy< int >, Order >(vector);
    printSorted< VectorAtStrategy< int >, Order >(vector);
    printSorted< ForwardListIteratorStrategy< int >, Order >(list);
  }

  int taskSort(int argc, char *argv[])
  {
    if (argc != 3) {
      std::cerr << "Order not specified";
      return 1;
    }
    const std::string orderParameter = argv[2];
    if (orderParameter == "ascending") {
      doTask< AscendingOrder >();
    } else if (orderParameter == "descending") {
      doTask< DescendingOrder >();
    } else {
      std::cerr << "Invalid sorting order";
      return 1;
    }
    return 0;
  }

}

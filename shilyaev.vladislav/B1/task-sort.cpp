#include "task-sort.hpp"
#include <iostream>
#include <vector>
#include <forward_list>
#include "order-strategies.hpp"
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

  template < typename AccessStrategy, typename Order >
  void printSorted(typename AccessStrategy::Collection collection)
  {
    bubbleSort< AccessStrategy, Order >(collection);
    print(collection.begin(), collection.end());
  }

  template < typename Order >
  int doTask()
  {
    std::vector< int > vector;
    inputVector(vector);
    if (std::cin.fail() && !std::cin.eof()) {
      std::cerr << "Error while reading";
      return 1;
    }
    std::forward_list< int > list(vector.begin(), vector.end());

    printSorted< VectorBracketsStrategy< int >, Order >(vector);
    printSorted< VectorAtStrategy< int >, Order >(vector);
    printSorted< ForwardListIteratorStrategy< int >, Order >(list);
    return 0;
  }

  int taskSort(int argc, char *argv[])
  {
    if (argc != 3) {
      std::cerr << "Order not specified";
      return 1;
    }
    const std::string orderParameter = argv[2];
    if (orderParameter == "ascending") {
      return doTask< AscendingOrder >();
    } else if (orderParameter == "descending") {
      return doTask< DescendingOrder >();
    } else {
      std::cerr << "Invalid sorting order";
      return 1;
    }
  }

}

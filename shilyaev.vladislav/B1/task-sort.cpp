#include "task-sort.hpp"
#include <iostream>
#include <vector>
#include <forward_list>
#include "order-strategies.hpp"
#include "access-strategies.hpp"
#include "iterator-utils.hpp"
#include "sort.hpp"

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
  shilyaev::bubbleSort< AccessStrategy, Order >(collection);
  shilyaev::print(collection.begin(), collection.end());
}

template < typename Order >
void doTask()
{
  std::vector< int > vector;
  inputVector(vector);
  std::forward_list< int > list(vector.begin(), vector.end());

  printSorted< shilyaev::VectorBracketsStrategy< int >, Order >(vector);
  printSorted< shilyaev::VectorAtStrategy< int >, Order >(vector);
  printSorted< shilyaev::ForwardListIteratorStrategy< int >, Order >(list);
}

int shilyaev::taskSort(int argc, char *argv[])
{
  if (argc != 3) {
    std::cerr << "Order not specified";
    return 1;
  }
  const std::string orderParameter = argv[2];
  if (orderParameter == "ascending") {
    doTask< shilyaev::AscendingOrder >();
  } else if (orderParameter == "descending") {
    doTask< shilyaev::DescendingOrder >();
  } else {
    std::cerr << "Invalid sorting order";
    return 1;
  }
  return 0;
}

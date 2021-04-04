#include "task-sort.hpp"
#include <iostream>
#include <vector>
#include <forward_list>
#include "order-strategies.hpp"
#include "iterator-strategies.hpp"
#include "iterator-utils.hpp"

template < typename T >
void inputVector(std::vector< T > &vector)
{
  T input;
  while (std::cin >> input) {
    vector.push_back(input);
  }
}

template < typename Strategy, typename Order >
void bubbleSort(typename Strategy::Collection &collection)
{
  using Item = typename Strategy::Item;
  using Iterator = typename Strategy::Iterator;
  Iterator begin = Strategy::begin(collection);
  Iterator end = Strategy::end(collection);
  while (begin != end) {
    Iterator i = begin;
    for (; advanced(i) != end; i++) {
      Item &current = Strategy::get(collection, i);
      Item &next = Strategy::get(collection, advanced(i));
      if (!Order::isOrdered(current, next)) {
        std::swap(current, next);
      }
    }
    end = i;
  }
}

template < typename Strategy, typename Order >
void printSorted(typename Strategy::Collection collection)
{
  bubbleSort< Strategy, Order >(collection);
  print(collection.begin(), collection.end());
}

template < typename Order >
void doTask()
{
  using Item = int;
  std::vector< Item > vector;
  inputVector(vector);
  std::forward_list< Item > list(vector.begin(), vector.end());

  printSorted< VectorBracketsStrategy< Item >, Order >(vector);
  printSorted< VectorAtStrategy< Item >, Order >(vector);
  printSorted< ForwardListIteratorStrategy< Item >, Order >(list);
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

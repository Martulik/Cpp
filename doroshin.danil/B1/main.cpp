#include <iostream>
#include <stdexcept>
#include "task1.hpp"
#include "task2.hpp"
#include "task3.hpp"
#include "task4.hpp"

namespace dan = doroshin;

template< typename T >
std::function< bool(T, T) > getOrder(std::string order)
{
  if(order == "ascending") {
    return std::less< T >();
  }
  else if(order == "descending") {
    return std::greater< T >();
  }
  else {
    throw std::runtime_error("Invalid sorting order");
  }
}

template< typename T >
T readArg(std::string arg)
{
  T res;
  std::istringstream in (arg);
  in >> res;
  if(in.fail()) {
    throw std::runtime_error("Invalid read");
  }
  in.get();
  if(!in.eof()) {
    throw std::runtime_error("Extra symbols");
  }
  return res;
}

template< typename T >
std::vector< T > readUntilEof()
{
  std::vector< T > values;
  while(true) {
    if(std::cin.eof())
      break;

    T next;
    std::cin >> next;
    if(std::cin.eof())
      break;
    if(std::cin.fail()) {
      throw std::runtime_error("Incorrect input");
    }
    values.push_back(next);
  }
  return values;
}

int main(int argc, char* argv[])
{
  try {
    if(argc < 2) {
      throw std::runtime_error("No task number");
    }
    const int task_num = readArg< int >(argv[1]);
    if(task_num == 1) {
      if(argc < 3) {
        throw std::runtime_error("No sorting order");
      }

      const std::function< bool(int, int) > cmp = getOrder< int >(argv[2]);
      const std::vector< int > values = readUntilEof< int >();
      const std::forward_list< int > l_values(values.begin(), values.end());

      dan::task1< dan::VectorIndexStrat< int > >(values, cmp);
      dan::task1< dan::VectorAtStrat< int > >(values, cmp);
      dan::task1< dan::ListIterStrat< int > >(l_values, cmp);
    }
    else if(task_num == 2) {
      if(argc < 3) {
        throw std::runtime_error("No filename");
      }
      std::string filename = argv[2];
      dan::task2(filename);
    }
    else if(task_num == 3) {
      dan::task3();
    }
    else if(task_num == 4) {
      if(argc < 3) {
        throw std::runtime_error("No sorting order");
      }
      if(argc < 4) {
        throw std::runtime_error("No array length");
      }
      const size_t size = readArg< size_t >(argv[3]);
      std::function< bool(double, double) > cmp = getOrder< double >(argv[2]);
      dan::task4(size, cmp);
    }
    else {
      throw std::runtime_error("Unknown task");
    }
  }
  catch(const std::runtime_error& e) {
    std::cerr << e.what() << '\n';
    return 1;
  }
  catch(const std::logic_error& e) {
  }
  return 0;
}

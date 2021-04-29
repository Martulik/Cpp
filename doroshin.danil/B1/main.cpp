#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <cstring>
#include "task1.hpp"
#include "task2.hpp"
#include "task3.hpp"
#include "task4.hpp"

namespace dan = doroshin;

template< typename T >
std::vector< T > readUntilEof()
{
  std::vector< T > values;
  while(true) {
    if(std::cin.eof()) {
      break;
    }

    T next;
    std::cin >> next;
    if(std::cin.eof()) {
      break;
    }
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
    if(!std::all_of(argv[1], argv[1] + std::strlen(argv[1]), isdigit)) {
      throw std::runtime_error("Task number is invalid");
    }
    const int task_num = std::atoi(argv[1]);
    if(task_num == 1) {
      if(argc < 3) {
        throw std::runtime_error("No sorting order");
      }

      const std::vector< int > values = readUntilEof< int >();
      const std::forward_list< int > l_values(values.begin(), values.end());

      if(!std::strcmp(argv[2], "ascending")) {
        dan::task1< dan::VectorIndexStrat< int > >(values, std::less<>());
        dan::task1< dan::VectorAtStrat< int > >(values, std::less<>());
        dan::task1< dan::ListIterStrat< int > >(l_values, std::less<>());
      }
      else if(!std::strcmp(argv[2], "descending")) {
        dan::task1< dan::VectorIndexStrat< int > >(values, std::greater<>());
        dan::task1< dan::VectorAtStrat< int > >(values, std::greater<>());
        dan::task1< dan::ListIterStrat< int > >(l_values, std::greater<>());
      }
      else {
        throw std::runtime_error("Invalid sorting order");
      }
    }
    else if(task_num == 2) {
      if(argc < 3) {
        throw std::runtime_error("No filename");
      }
      dan::task2(argv[2]);
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
      if(!std::all_of(argv[3], argv[3] + std::strlen(argv[3]), isdigit)) {
        throw std::runtime_error("Size is invalid");
      }
      const size_t size = atoi(argv[3]);
      if(!std::strcmp(argv[2], "ascending")) {
        dan::task4(size, std::less<>());
      }
      else if(!std::strcmp(argv[2], "descending")) {
        dan::task4(size, std::greater<>());
      }
      else {
        throw std::runtime_error("Invalid sorting order");
      }
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

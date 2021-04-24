#include "task-processing.hpp"
#include <iostream>
#include <vector>
#include "iterator-print.hpp"

namespace shilyaev {

  void inputVectorZero(std::vector< int > &vector)
  {
    int input;
    while (std::cin >> input) {
      if (input == 0) {
        break;
      }
      vector.push_back(input);
    }
  }

  void removeEven(std::vector< int > &vector)
  {
    for (std::vector< int >::iterator i = vector.begin(); i < vector.end();) {
      if (*i % 2 == 0) {
        i = vector.erase(i);
      } else {
        i++;
      }
    }
  }

  void addOnes(std::vector< int > &vector)
  {
    for (std::vector< int >::iterator i = vector.begin(); i < vector.end();) {
      if (*i % 3 == 0) {
        i = vector.insert(i + 1, 3, 1);
        i += 3;
      } else {
        i++;
      }
    }
  }

  int taskProcessing(int argc)
  {
    if (argc != 2) {
      std::cerr << "Invalid arguments count";
      return 1;
    }
    std::vector< int > vector;
    inputVectorZero(vector);
    if (std::cin.fail()) {
      if (std::cin.eof() && vector.empty()) {
        return 0;
      } else {
        std::cerr << "Error while reading";
        return 1;
      }
    }
    if (vector.empty()) {
      return 0;
    }
    if (vector.back() == 1) {
      removeEven(vector);
    } else if (vector.back() == 2) {
      addOnes(vector);
    }
    print(vector.cbegin(), vector.cend(), std::cout);
    return 0;
  }

}

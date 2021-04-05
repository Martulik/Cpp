#include "task-iterators.hpp"
#include <iostream>
#include <vector>
#include "iterator-utils.hpp"

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

  int taskIterators(int argc)
  {
    if (argc != 2) {
      std::cerr << "Invalid arguments count";
      return 1;
    }
    std::vector< int > vector;
    inputVectorZero(vector);
    if (std::cin.fail()) {
      std::cerr << "Error while reading";
      return 1;
    }
    if (vector.empty()) {
      std::cerr << "Empty input";
      return 1;
    }
    int last = *(vector.end() - 1);
    if (last == 1) {
      removeEven(vector);
    } else if (last == 2) {
      addOnes(vector);
    }
    print(vector.begin(), vector.end());
    return 0;
  }

}

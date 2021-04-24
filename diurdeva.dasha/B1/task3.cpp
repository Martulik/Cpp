#include "tasks.hpp"
#include <vector>
#include "tools.hpp"

int diurdeva::task3()
{
  std::vector< int > vector;
  int num = 0;

  while (std::cin && !(std::cin >> num).eof()) {

    if (std::cin.fail() || std::cin.bad()) {
      std::cerr << "Read error\n";
      return 1;
    }

    if (num == 0) {
      break;
    }
    vector.push_back(num);
  }

  if (num != 0) {
    std::cerr << "Wrong input\n";
    return 1;
  }

  if (vector.empty()) {
    return 0;
  }

  std::vector< int >::iterator it = vector.begin();
  if (vector.back() == 1) {
    while (it != vector.end()) {
      if (*it % 2 == 0) {
        it = vector.erase(it);
      }
      else {
        it++;
      }
    }
  }
  if (vector.back() == 2) {
    while (it != vector.end()) {
      if (*it % 3 == 0) {
        it = vector.insert(it + 1, 3, 1) + 2;
      }
      else {
        it++;
      }
    }
  }

  print(vector);
  return 0;
}

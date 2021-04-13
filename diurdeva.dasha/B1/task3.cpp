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

  std::vector< int >::iterator iterator = vector.begin();
  if (!vector.empty() && vector.back() == 1) {
    while (iterator != vector.end()) {
      if (*iterator % 2 == 0) {
        iterator = vector.erase(iterator);
      } else {
        iterator++;
      }
    }
  }
  if (!vector.empty() && vector.back() == 2) {
    while (iterator != vector.end()) {
      if (*iterator % 3 == 0) {
        iterator = vector.insert(iterator + 1, 3, 1) + 2;
      } else {
        iterator++;
      }
    }
  }
  print(vector);
  return 0;
}

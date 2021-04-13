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

  switch (vector.back()) {
  case 1:
    for (auto i = vector.begin(); i != vector.end();) {
      i = ((*i % 2) == 0) ? vector.erase(i) : ++i;
    }
    break;

  case 2:
    for (auto i = vector.begin(); i != vector.end();) {
      i = ((*i % 3) == 0) ? (vector.insert(++i, 3, 1) + 3) : ++i;
    }
    break;

  default:
    break;
  }
  print(vector);
  return 0;
}

#include "tasks.hpp"
#include <vector>
#include "tools.hpp"

void diurdeva::task3(Error &err)
{
  std::vector< int > vector;
  int num = 0;

  while (err.isError() && std::cin && !(std::cin >> num).eof()) {

    if (std::cin.fail() || std::cin.bad()) {
      err.set("Error reading file\n");
      break;
    }

    if (num == 0) {
      break;
    }
    vector.push_back(num);
  }

  if (err.isError()) {
    if (num != 0) {
      err.set("No end of line\n");
    }
  }

  if (err.isError()) {
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
  }

  print(vector);
}

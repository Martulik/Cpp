#include "task3.hpp"
#include <vector>
#include "tools.hpp"

namespace lab = ezerinia;

lab::error lab::task3()
{
  std::vector< int > vec;
  int n = 1;
  while (std::cin && !(std::cin >> n).eof()) {
    if (std::cin.fail() || std::cin.bad()) {
      return lab::error::input;
    }
    if (n == 0) {
      break;
    }
    vec.push_back(n);
  }
  if (vec.empty()) {
    return lab::error::success;
  }
  if (n != 0) {
    return lab::error::input;
  }

  std::vector< int >::iterator iter = vec.begin();
  if (vec.back() == 1) {
    while (iter != vec.end()) {
      if (*iter % 2) {
        iter++;
      } else {
        vec.erase(iter);
      }
    }
  } else if (vec.back() == 2) {
    while (iter != vec.end()) {
      if (!(*iter % 3)) {
        iter = vec.insert(++iter, 3, 1);
        iter += 2;
      }
      iter++;
    }
  }
  lab::print(vec, std::cout);

  return lab::error::success;
}

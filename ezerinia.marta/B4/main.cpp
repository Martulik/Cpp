#include <iostream>
#include "tools.hpp"

namespace lab = ezerinia;

int main()
{
  try {
    lab::task();
  }
  catch (const std::invalid_argument &ex) {
    std::cerr << ex.what() << "\n";
    return 1;
  }
  return 0;
}

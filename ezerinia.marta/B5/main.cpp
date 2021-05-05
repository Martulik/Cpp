#include <iostream>
#include "task1.hpp"
#include "task2.hpp"

namespace lab = ezerinia;

int main(int argc, char *argv[])
{
  try {
    if (argc < 2 || strlen(argv[1]) != 1 || (std::atoi(argv[1]) != 1 && std::atoi(argv[1]) != 2)) {
      throw std::runtime_error("Invalid arguments or number of them");
    }
    if (std::atoi(argv[1]) == 1) {
      lab::task1();
    } else {
      lab::task2();
    }
  }
  catch (std::exception &ex) {
    std::cerr << ex.what() << "\n";
    return 1;
  }
  return 0;
}

#include <iostream>
#include <cstring>
#include "task1.hpp"
#include "task2.hpp"

namespace lab = ezerinia;

int main(int argc, char *argv[])
{
  try {
    if (argc < 2 || std::strlen(argv[1]) != 1 || !std::isdigit(argv[1][0])) {
      throw std::invalid_argument("Invalid arguments");
    }
    if (argv[1][0] == '1') {
      lab::task1(std::cin, std::cout);
    } else if (argv[1][0] == '2') {
      lab::task2(std::cin, std::cout);
    } else {
      throw std::invalid_argument("Invalid number of task");
    }
  }
  catch (std::exception &ex) {
    std::cerr << ex.what() << "\n";
    return 1;
  }
  return 0;
}

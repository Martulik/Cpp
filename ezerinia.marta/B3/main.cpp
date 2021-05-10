#include <iostream>
#include <cstring>
#include "task1.hpp"
#include "task2.hpp"

namespace ezerinia {
  bool isSingleDigit(const char *src)
  {
    return (std::strlen(src) == 1) && std::isdigit(src[0]);
  }
}

namespace lab = ezerinia;

int main(int argc, char *argv[])
{
  try {
    if (argc != 2) {
      throw std::runtime_error("Invalid arguments");
    }
    if (!lab::isSingleDigit(argv[1])) {
      throw std::runtime_error("Task number must be a single digit");
    } else if (std::atoi(argv[1]) == 1) {
      lab::task1(std::cin, std::cout);
    } else if (std::atoi(argv[1]) == 2) {
      lab::task2(std::cout);
    } else {
      throw std::runtime_error("Task number must be 1 or 2");
    }
  }
  catch (const std::runtime_error &err) {
    std::cerr << err.what() << "\n";
    return 2;
  }
  return 0;
}

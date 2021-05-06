#include <iostream>
#include <cstring>
#include "task1.hpp"
#include "task2.hpp"

namespace lab = ezerinia;

bool isTaskNumber(const char *src)
{
  return (std::strlen(src) == 1) && std::isdigit(src[0]) && (std::atoi(src) == 1 || std::atoi(src) == 2);
}

int main(int argc, char *argv[])
{
  try {
    if (argc != 2) {
      throw std::runtime_error("Invalid arguments");
    }
    if (!isTaskNumber(argv[1])) {
      throw std::runtime_error("Invalid task number");
    } else if (std::atoi(argv[1])  == 1) {
      lab::task1();
    } else {
      lab::task2();
    }
  }
  catch (const std::runtime_error &err) {
    std::cerr << err.what() << "\n";
    return 2;
  }
  return 0;
}

#include <iostream>
#include "task1.hpp"
#include "task2.hpp"

namespace lab = ezerinia;

int main(int argc, char *argv[])
{
  try {
    if (argc != 2) {
      throw std::runtime_error("Invalid arguments");
    }
    const int taskNumber = std::atoi(argv[1]);
    if (taskNumber != 1 && taskNumber != 2) {
      throw std::runtime_error("Invalid task number");
    } else if (taskNumber == 1) {
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

#include <iostream>

#include "task1.hpp"

void task2();

int main(int argc, char *argv[])
{
  try {
    if (argc != 2) {
      throw std::runtime_error("Invalid arguments");
    }
    char *str_end = nullptr;
    const int taskNumber = std::strtol(argv[1], &str_end, 10);
    if (*str_end || (taskNumber != 1 && taskNumber != 2)) {
      throw std::runtime_error("Invalid task number");
    } else if (taskNumber == 1) {
      task1();
    } else {
      task2();
    }
  }
  catch (const std::runtime_error &err) {
    std::cerr << err.what() << std::endl;
    return 1;
  }
  return 0;
}

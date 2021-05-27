#include <iostream>
#include <cctype>
#include <cstring>

#include "task1.hpp"
#include "task2.hpp"

bool isTaskNumber(const char* src)
{
  return (std::strlen(src) == 1 && std::isdigit(src[0]));
}

int main(int argc, char* argv[])
{
  try
  {
    if (argc != 2) {
      throw std::invalid_argument("Invalid arguments");
    }

    if (!isTaskNumber(argv[1])) {
      throw std::invalid_argument("Invalid task number");
    }
    int taskNumber = std::atoi(argv[1]);
    if (taskNumber == 1) {
      diurdeva::task1(std::cin, std::cout);
    }
    else if (taskNumber == 2) {
      diurdeva::task2(std::cin, std::cout);
    }
    else {
      throw std::invalid_argument("Invalid task number");
    }
  }
  catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    return 1;
  }
  return 0;
}

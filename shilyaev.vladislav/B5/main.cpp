#include <iostream>
#include "task-words.hpp"
#include "task-shape.hpp"

int main(int argc, char *argv[])
{
  if (argc != 2) {
    std::cerr << "Wrong argument count";
    return 1;
  }
  std::string task = argv[1];
  if (task == "1") {
    return shilyaev::runWordsTask(std::cin, std::cout);
  } else if (task == "2") {
    return shilyaev::runShapeTask(std::cin, std::cout);
  } else {
    std::cerr << "No such task";
    return 1;
  }
}

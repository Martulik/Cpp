#include <iostream>
#include "task-sort.hpp"
#include "task-copy.hpp"

int main(int argc, char *argv[])
{
  if (argc <= 1) {
    std::cerr << "Task not specified";
    return 1;
  }
  int taskNumber = std::atoi(argv[1]);
  switch (taskNumber) {
    case 1: {
      return taskSort(argc, argv);
    }
    case 2: {
      return taskCopy(argc, argv);
    }
    default: {
      std::cerr << "Unknown task";
      return 1;
    }
  }
}

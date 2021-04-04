#include <iostream>
#include "task-sort.hpp"
#include "task-copy.hpp"
#include "task-iterators.hpp"
#include "task-random.hpp"

int main(int argc, char *argv[])
{
  if (argc <= 1) {
    std::cerr << "Task not specified";
    return 1;
  }
  int taskNumber = std::atoi(argv[1]);
  switch (taskNumber) {
    case 1: {
      return shilyaev::taskSort(argc, argv);
    }
    case 2: {
      return shilyaev::taskCopy(argc, argv);
    }
    case 3: {
      return shilyaev::taskIterators(argc);
    }
    case 4: {
      return shilyaev::taskRandom(argc, argv);
    }
    default: {
      std::cerr << "Unknown task";
      return 1;
    }
  }
}

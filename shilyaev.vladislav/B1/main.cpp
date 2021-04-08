#include <iostream>
#include "task-sort.hpp"
#include "task-file.hpp"
#include "task-processing.hpp"
#include "task-random.hpp"
#include "string-convert.hpp"

int main(int argc, char *argv[])
{
  if (argc <= 1) {
    std::cerr << "Task not specified";
    return 1;
  }
  boost::optional< unsigned long > taskNumber = shilyaev::toNatural(argv[1]);
  if (!taskNumber) {
    std::cerr << "Task must be an integer";
    return 1;
  }
  switch (*taskNumber) {
    case 1: {
      return shilyaev::taskSort(argc, argv);
    }
    case 2: {
      return shilyaev::taskFile(argc, argv);
    }
    case 3: {
      return shilyaev::taskProcessing(argc);
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

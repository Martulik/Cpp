#include <iostream>
#include <string>
#include "tasks.hpp"
#include "compare-function.hpp"
#include "tools.hpp"

namespace lab = diurdeva;

std::string error = "Null";
int code = 0;

int setError(std::string err)
{
  code = 1;
  error = err;
  return code;
}

int main(int argc, char *argv[])
{
  if ((argc < 2) || (argc > 4)) {
    std::cerr << "Incorrect number of arguments.\n";
    return 1;
  }

  char *ptr = nullptr;
  int taskNumber = std::strtol(argv[1], &ptr, 10);
  if (*ptr != 0x00) {
    std::cerr << "Incorrect argument.\n";
    return 1;
  }

  if (taskNumber == 1 && argc == 3) {
    const std::function< bool(int, int) > &compare = lab::getCompare< int >(argv[2]);
    code = compare ? lab::task1(compare) : setError("Invalid direction");
  } else if (taskNumber == 2 && argc == 3) {
    code = lab::task2(argv[2]);
  } else if (taskNumber == 3 && argc == 2) {
    code = lab::task3();
  } else if (taskNumber == 4 && argc == 4) {
    const std::function< bool(double, double) > &compare = lab::getCompare< double >(argv[2]);
    code = compare && lab::checkIsNumber(argv[3]) ?
            lab::task4(compare, atoi(argv[3])) : setError("Invalid direction");
  } else {
    code = setError("Incorrect number of arguments.\n");
  }

  if (error != "Null") {
    std::cerr << error;
  }
  return code;
}

#include <iostream>
#include <string>
#include <ctime>
#include "tasks.hpp"
#include "compare-function.hpp"
#include "tools.hpp"

namespace lab = diurdeva;

int main(int argc, char *argv[])
{
  srand(time(NULL));
  lab::Error err;

  if ((argc < 2) || (argc > 4)) {
    err.set("Wrong number of arguments\n");
  }

  if (!err.isError() || !lab::isNumber(argv[1]) || atoi(argv[1]) <= 0 || atoi(argv[1]) >= 5) {
    err.set("Incorrect number for task\n");
  }
  int taskNumber = err.isError() ? atoi(argv[1]) : 0;

  if (taskNumber == 1 && argc == 3) {
    const std::function< bool(int, int) > &compare = lab::getCompare<int>(argv[2]);
    if (compare) {
      lab::task1(compare, err);
    } else {
      err.set("Incorrect direction\n");
    }
  } else if (taskNumber == 2 && argc == 3) {
    lab::task2(argv[2], err);
  } else if (taskNumber == 3 && argc == 2) {
    lab::task3(err);
  } else if (taskNumber == 4 && argc == 4) {
    const std::function< bool(double, double) > &compare = lab::getCompare<double>(argv[2]);
    if (compare && lab::isNumber(argv[3])) {
      lab::task4(compare, atoi(argv[3]));
    } else {
      err.set("Incorrect argument\n");
    }
  } else {
    err.set("Incorrect number for task\n");
  }

  if (!err.isError()) {
    std::cerr << err.getError();
    return 1;
  }
  return 0;
}

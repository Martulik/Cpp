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

  if ((argc < 2) || (argc > 4)) {
    std::cerr << "Incorrect number of arguments.\n";
    return 1;
  }

  if (!lab::isDigit(argv[1]))
  {
    std::cerr << "Incorrect first argument (task number)";
    return 1;
  }

  int taskNumber = atoi(argv[1]);
  std::string error = "Null";
  int code = 0;

  if (taskNumber == 1 && argc == 3) {
    const std::function< bool(int, int) > &compare = lab::getCompare< int >(argv[2]);
    error = compare ? "Null" : "Incorrect direction";
    code = (error == "Null") ? lab::task1(compare) : 1;
  } else if (taskNumber == 2 && argc == 3) {
    code = lab::task2(argv[2]);
  } else if (taskNumber == 3 && argc == 2) {
    code = lab::task3();
  } else if (taskNumber == 4 && argc == 4) {
    const std::function< bool(double, double) > &compare = lab::getCompare< double >(argv[2]);
    error = compare && lab::isDigit(argv[3]) ? "Null" : "Incorrect direction";
    code = (error == "Null") ? lab::task4(compare, atoi(argv[3])) : 1;
  } else {
    error = "Incorrect number of arguments.\n";
    code = 1;
  }

  if (error != "Null") {
    std::cerr << error;
  }
  return code;
}

#ifndef TASKS_HPP
#define TASKS_HPP

#include <functional>
#include "error.hpp"

namespace diurdeva {
  int task1(const std::function< bool(int, int) > compare, Error &error_obj);
  int task2(const char *fileName, Error &error_obj);
  int task3(Error &error_obj);
  int task4(const std::function< bool(double, double) > compare, const int size);
}

#endif

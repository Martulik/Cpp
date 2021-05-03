#ifndef TASKS_HPP
#define TASKS_HPP

#include <functional>
#include "error.hpp"

namespace diurdeva {
  void task1(const std::function< bool(int, int) > compare, Error &error_obj);
  void task2(const char *fileName, Error &error_obj);
  void task3(Error &error_obj);
  void task4(const std::function< bool(double, double) > compare, const int size);
}

#endif

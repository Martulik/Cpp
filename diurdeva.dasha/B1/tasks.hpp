#ifndef TASKS_HPP
#define TASKS_HPP

#include <functional>

namespace diurdeva {
  int task1(const std::function< bool(int, int) > compare);
  int task2(const char *fileName);
  int task3();
  int task4(const std::function< bool(double, double) > compare, const int size);
}

#endif

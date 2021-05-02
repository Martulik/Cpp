#ifndef TASKS_HPP
#define TASKS_HPP

#include <cstring>
#include <vector>
#include <random>

namespace ferapontov
{
  void task1(const char* mode);
  void task2(const char* file);
  void task3();
  void task4(const char* mode, int size, std::random_device& rd);
}

#endif

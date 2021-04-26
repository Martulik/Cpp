#ifndef TASKS_HPP
#define TASKS_HPP

#include <iostream>
#include <stdexcept>

#include <vector>
#include <forward_list>

#include "comparator.hpp"
#include "strategies.hpp"
#include "sort.hpp"
#include "print.hpp"

namespace lysenko
{
  int task1(const char* order);
  int task2(const char* fileName);
  int task3();
  int task4(const char* order, const char* numberOfArguments);

  void fillRandom(double* myVectPointer, int size);
}

#endif

#include "task.hpp"

#include <cstddef>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>

#include "tools.hpp"

namespace lab = savchuk;

void lab::doTask2(const char* fileName)
{
  std::ifstream ifs(fileName);
  if (!ifs)
  {
    throw std::runtime_error("can't open file");
  }
  std::stringstream buf;
  size_t count = 0;
  int x;
  while (ifs >> x)
  {
    ++count;
    buf << x << ' ';
  }
  if (count == 0)
  {
    throw std::runtime_error("array can't be empty");
  }
  if (ifs.fail() && !ifs.eof())
  {
    throw std::runtime_error("incorrect input format");
  }
  if (ifs.bad())
  {
    throw std::runtime_error("input file error");
  }
  ifs.close();
  std::unique_ptr< int[] > arr = std::make_unique< int[] >(count);
  for (size_t i = 0; i < count; ++i)
  {
    buf >> arr[i];
  }
  std::vector< int > vec(arr.get(), arr.get() + count);
  print(vec.cbegin(), vec.cend(), std::cout);
}
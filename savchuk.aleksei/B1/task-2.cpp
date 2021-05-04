#include "tasks.hpp"

#include <cstddef>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>

#include "tools.hpp"

namespace lab = savchuk;

void lab::doTask2(const char* fileName)
{
  std::ifstream ifs(fileName);
  if (!ifs)
  {
    throw std::runtime_error("Can't open file");
  }
  size_t capacity = 1000;
  size_t size = 0;
  std::unique_ptr< char[] > arr = std::make_unique< char[] >(capacity);
  while (!ifs.eof())
  {
    ifs.read(arr.get() + size, capacity - size);
    size += ifs.gcount();
    if (size == capacity)
    {
      capacity *= 2;
      std::unique_ptr< char[] > tmp = std::make_unique< char[] >(capacity);
      for (size_t i = 0; i < size; ++i)
      {
        tmp[i] = arr[i];
      }
      arr.swap(tmp);
    }
  }
  if (ifs.bad())
  {
    throw std::runtime_error("Input file error");
  }
  ifs.close();
  std::vector< char > vec(arr.get(), arr.get() + size);
  std::vector< char >::const_iterator it = vec.cbegin();
  while (it != vec.cend())
  {
    std::cout << *it;
    ++it;
  }
}

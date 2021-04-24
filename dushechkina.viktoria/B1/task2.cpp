#include <forward_list>
#include <fstream>
#include <functional>
#include <iostream>
#include <vector>

#include "tasks.hpp"
#include "functions.hpp"
#include "sort.hpp"

void task2(const char* filename)
{
  if (filename == nullptr)
  {
    throw std::invalid_argument("Filename is undefined");
  }
  std::ifstream stream(filename);
  if (!stream)
  {
    throw std::runtime_error("File is not open");
  }
  size_t capacity = 1;
  size_t size = 0;
  std::unique_ptr<char[]> data = std::make_unique<char[]>(capacity);
  while (stream)
  {
    stream.read(data.get() + size, capacity - size);
    size += stream.gcount();
    if (size == capacity)
    {
      capacity *= 2;
      std::unique_ptr<char[]> temp = std::make_unique<char[]>(capacity);
      for (size_t i = 0; i < size; i++)
      {
        temp[i] = std::move(data[i]);
      }
      data = std::move(temp);
    }
  }
  std::vector<char> vector(data.get(), data.get() + size);
  print(vector, "");
}
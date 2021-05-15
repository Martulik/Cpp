#include "tasks.hpp"
#include "functions.hpp"

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <vector>
#include <memory>

void pyatizbyantsev::taskTwo(const char* fileName)
{
  std::ifstream file(fileName);
  file.open(fileName);
  if (!file.is_open())
  {
    throw std::invalid_argument("Unable to read the file");
  }

  size_t capacity = 1000;
  size_t size = 0;
  std::unique_ptr< char[] > resultArray  = std::make_unique< char[] >(capacity);

  while (!file.eof())
  {
    file.read(resultArray.get() + size, capacity - size);
    size += file.gcount();

    if (file.fail() && (!file.eof()))
    {
      throw std::invalid_argument("Input error");
    }

    if (size == capacity)
    {
      capacity *= 2;
      std::unique_ptr< char[] > temp = std::make_unique< char[] >(capacity);
      for (size_t i = 0; i < size; ++i)
      {
        temp[i] = resultArray[i];
      }
      resultArray.swap(temp);
    }
  }
  file.close();
  std::vector< char > vector(resultArray.get(), resultArray.get() + size);
  print(vector.begin(), vector.end(), "");
}

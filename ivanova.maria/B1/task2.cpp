#include "tasks.hpp"

#include <iostream>
#include <vector>
#include <stdexcept>
#include <memory>

#include "functions.hpp"

namespace iva = ivanova;

using unPtr = std::unique_ptr<char[], decltype(&free)>;

int iva::task2(const char *fileName)
{
  if (fileName == nullptr)
  {
    std::cerr << ("The inFile with this fileName does not exist!");
    exit(1);
  }
  size_t maxArraySize = 128;
  std::ifstream inFile(fileName);
  if (!inFile.is_open())
  {
    std::cerr << ("Can't open the file!");
    exit(1);
  }
  unPtr array(static_cast< char * >(malloc(maxArraySize)), &free);
  size_t countElements = 0;
  while (inFile)
  {
    inFile.read(&array[countElements], maxArraySize - countElements);
    countElements += inFile.gcount();
    if (countElements == maxArraySize)
    {
      maxArraySize *= 2;
      unPtr newArray(static_cast< char * >(realloc(array.get(), maxArraySize)), &free);
      if (!newArray)
      {
        inFile.close();
        throw std::bad_alloc();
      }
      array.release();
      std::swap(array, newArray);
    }
  }
  inFile.close();
  if (inFile.is_open())
  {
    std::cerr << ("The file was not closed!");
    exit(1);
  }
  std::vector< char > resultVector(&array[0], &array[countElements]);
  print(resultVector, std::cout);
  return 0;
}


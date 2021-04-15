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
  size_t maxArraySize = 128;
  std::ifstream inFile(fileName);
  if (!inFile.is_open())
  {
    std::cerr << ("Can't open the file!");
    return 1;
  }
  unPtr array(static_cast< char * >(malloc(maxArraySize)), &free);
  size_t countElements = 0;
  while (!inFile.eof())
  {
    inFile.read(&array[countElements], maxArraySize - countElements);
    countElements += inFile.gcount();
    if (countElements == maxArraySize)
    {
      maxArraySize *= 2;
      unPtr newArray(static_cast< char * >(realloc(array.get(), maxArraySize)), &free);
      for (size_t i = 0; i < countElements; i++)
      {
        newArray[i] = std::move(array[i]);
      }
      array = std::move(newArray);
    }
  }
  inFile.close();
  std::vector< char > resultVector(&array[0], &array[countElements]);
  print(resultVector, std::cout);
  return 0;
}


#include "tasks.hpp"

#include <iostream>
#include <vector>
#include <stdexcept>
#include <memory>

#include "functions.hpp"

namespace iva = ivanova;

using unPtr = std::unique_ptr< char[] >;

int iva::task2(const char *fileName)
{
  std::ifstream inFile;
  inFile.open(fileName);
  if (!inFile)
  {
    std::cerr << ("Can't open the file!");
    return 1;
  }
  if (inFile.peek() == EOF)
  {
    return 0;
  }
  size_t maxArraySize = 128;
  size_t countElements = 0;
  unPtr array = std::make_unique< char[] >(maxArraySize);
  while (!inFile.eof())
  {
    inFile.read(array.get() + countElements, maxArraySize - countElements);
    countElements += inFile.gcount();
    if (countElements == maxArraySize)
    {
      maxArraySize *= 2;
    }
    unPtr newArray = std::make_unique< char[] > (maxArraySize);
    for (size_t i = 0; i < countElements; i++)
    {
      newArray[i] = std::move(array[i]);
    }
    std::swap(array, newArray);
  }
  inFile.close();
  char *first = array.get() + countElements;
  size_t second = maxArraySize - countElements;
  std::vector< char > resultVector(*first, second);
  print(resultVector, std::cout);
  return 0;
}


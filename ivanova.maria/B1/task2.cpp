#include "tasks.hpp"

#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <memory>

#include "functions.hpp"
namespace ivanova
{
  using unPtr = std::unique_ptr < char[], decltype(&free) >;
  int task2(const char *fileName)
  {
    int exitCode = 0;
    if (fileName == nullptr)
    {
      exitCode = 1;
      throw std::invalid_argument("The inFile with this fileName does not exist!");
    }
    size_t maxArraySize = 128;
    std::ifstream inFile(fileName);
    if (!inFile.is_open())
    {
      exitCode = 1;
      throw std::logic_error("Can't open the file!");
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
          exitCode = 1;
          throw std::bad_alloc();
        }
        array.release();
        std::swap(array, newArray);
      }
    }
    inFile.close();
    if (inFile.is_open())
    {
      exitCode = 1;
      throw std::ios_base::failure("The file was not closed!");
    }
    std::vector< char > resultVector(&array[0], &array[countElements]);
    print(resultVector, std::cout);
return exitCode;
  }
}

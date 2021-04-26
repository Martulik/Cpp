#include "tasks.hpp"

#include <fstream>

#include "functions.hpp"

namespace lab = shkurov;

void lab::taskTwo(const char* filename)
{
  std::ifstream file;
  file.open(filename);
  if (!file.is_open())
  {
    throw std::invalid_argument("No file found with such name.\n");
  }

  size_t sizeOfRead = 0;
  size_t strCapacity = 1024;
  std::unique_ptr< char[] > str(std::make_unique< char[] >(strCapacity));

  while (file.good())
  {
    file.read(str.get(), strCapacity - sizeOfRead);
    sizeOfRead = file.gcount();
    strCapacity *= 2;

    std::unique_ptr< char[] > temp(std::make_unique< char[] >(strCapacity));

    for (size_t i = 0; i < sizeOfRead; i++)
    {
      temp[i] = str[i];
    }

    str = std::move(temp);
  }

  std::vector< char > strVec(str.get(), str.get() + sizeOfRead);
  printContainer(strVec, static_cast< char >(0));
}

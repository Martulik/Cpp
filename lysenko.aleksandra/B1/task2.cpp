#include "tasks.hpp"

#include <memory>
#include <fstream>

int lysenko::task2(const char* fileName)
{
  std::ifstream myFile;

  myFile.open(fileName);

  if (myFile.is_open())
  {
    if (myFile.peek() == EOF)
    {
      return 0;
    }

    size_t currCapacity = 1;
    size_t currPosition = 0;
    std::unique_ptr< char[] > resultArray = std::make_unique< char[] >(currCapacity);

    if (myFile.eof())
    {
      return 0;
    }

    while (!myFile.eof())
    {
      currCapacity *= 2;
      std::unique_ptr< char[] > tempArray = std::make_unique< char[] >(currCapacity);
      myFile.read(tempArray.get() + currPosition, currCapacity - currPosition);

      if (myFile.fail() && (!myFile.eof()))
      {
        std::cerr << "Input error";
        return 1;
      }

      for (size_t i = 0; i < currPosition; ++i)
      {
        tempArray[i] = std::move(resultArray[i]);
      }

      std::swap(tempArray, resultArray);

      currPosition += myFile.gcount();
    }

    std::vector< char > myVector(resultArray.get(), resultArray.get() + currPosition);

    lysenko::print< lysenko::strategyForAt, std::vector< char > >(myVector, 0);

    return 0;
  }
  else
  {
    std::cerr << "Unable to open the file";
    return 1;
  }
}

#include "tasks.hpp"

#include <memory>
#include <fstream>

int lysenko::task2(const char* fileName)
{
  std::ifstream myFile;

  myFile.open(fileName);

  if (myFile.peek() == EOF)
  {
    return 1;
  }

  if (myFile.is_open())
  {
    size_t currCapacity = 1;
    size_t currPosition = 0;
    std::unique_ptr< char [] > resultArray = std::make_unique< char [] >(currCapacity);

    if (myFile.eof())
    {
      std::cerr << "File can not be empty";
      return 1;
    }

    while (!myFile.eof())
    {
      currCapacity *= 2;
      std::unique_ptr< char [] > tempArray = std::make_unique< char [] >(currCapacity);
      myFile.read(tempArray.get() + currPosition, currCapacity - currPosition);

      if (myFile.fail() || myFile.bad())
      {
        std::cerr <<"Input error";
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
    std::cerr << "Fail to open the file";
    return 1;
  }
}

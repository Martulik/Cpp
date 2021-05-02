#include "tasks.hpp"

#include <memory>
#include <fstream>

#include <vector>

#include "comparator.hpp"
#include "strategies.hpp"
#include "sort.hpp"
#include "print.hpp"

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

    size_t currCapacity = 2;
    size_t currPosition = 0;
    std::unique_ptr< char[] > resultArray = std::make_unique< char[] >(currCapacity);

    if (myFile.eof())
    {
      return 0;
    }

    while (!myFile.eof())
    {
      myFile.read(resultArray.get() + currPosition, currCapacity - currPosition);
      currPosition += myFile.gcount();

      if (myFile.fail() && (!myFile.eof()))
      {
        std::cerr << "Input error";
        return 1;
      }

      if (currPosition == currCapacity)
      {
        currCapacity *= 2;
        std::unique_ptr< char[] > tempArray = std::make_unique< char[] >(currCapacity);
        for (size_t i = 0; i < currPosition; ++i)
        {
          tempArray[i] = std::move(resultArray[i]);
        }
        resultArray.swap(tempArray);
      }
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

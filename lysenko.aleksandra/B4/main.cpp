#include <iostream>
#include <vector>
#include <iterator>

#include "DataStruct.h"
#include "helpFunctions.h"

int main()
{
  try
  {
    std::istream_iterator< lysenko::DataStruct > inputIt(std::cin);
    std::istream_iterator< lysenko::DataStruct> eof;

    std::vector< lysenko::DataStruct > myVector(inputIt, eof);
    lysenko::sortVector(myVector);
    lysenko::printVector(myVector, std::cout);
  }
  catch (std::invalid_argument& err)
  {
    std::cerr << err.what();
    return 1;
  }
  return 0;
}

#include <iostream>
#include <vector>
#include <iterator>
#include <stdexcept>
#include <algorithm>

#include "DataStruct.h"

int main()
{
  try
  {
    std::istream_iterator< lysenko::DataStruct >inpIt(std::cin);
    std::istream_iterator< lysenko::DataStruct >eof;
    std::vector< lysenko::DataStruct > myVector(inpIt, eof);
    std::sort(myVector.begin(), myVector.end());
    std::copy(myVector.begin(), myVector.end(), std::ostream_iterator< lysenko::DataStruct >(std::cout, "\n"));
  }
  catch (std::invalid_argument& err)
  {
    std::cerr << err.what();
    return 1;
  }

  return 0;
}

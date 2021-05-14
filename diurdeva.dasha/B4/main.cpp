#include "dataStruct.hpp"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>

int main()
{
  try
  {
    std::istream_iterator< diurdeva::DataStruct > input(std::cin);
    std::istream_iterator< diurdeva::DataStruct > lastIterator;
    std::vector< diurdeva::DataStruct > vector(input, lastIterator);
    if (std::cin.fail() && !std::cin.eof()) {
      throw std::ios_base::failure("Reading failed\n");
    }
    sort(vector.begin(), vector.end(), diurdeva::compare);
    std::copy(vector.begin(), vector.end(), std::ostream_iterator< diurdeva::DataStruct >(std::cout, "\n"));
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what();
    return 1;
  }
  return 0;
}

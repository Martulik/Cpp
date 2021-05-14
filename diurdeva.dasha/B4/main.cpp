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
    std::vector< diurdeva::DataStruct > vector;
    std::istream_iterator< diurdeva::DataStruct > input(std::cin);
    std::move(input, std::istream_iterator< diurdeva::DataStruct >(), std::back_inserter(vector));
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

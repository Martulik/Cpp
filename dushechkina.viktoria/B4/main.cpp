#include <iostream>
#include <vector>
#include <iterator>
#include <sstream>
#include <algorithm>
#include "data-struct.hpp"

int main()
{
  try
  {
    std::istream_iterator< dushechkina::DataStruct > begin(std::cin);
    std::istream_iterator< dushechkina::DataStruct > end;
    std::vector< dushechkina::DataStruct > vector(begin, end);
    if (std::cin.fail() && !std::cin.eof())
    {
      throw std::invalid_argument("Invalid input\n");
    }
    std::sort(vector.begin(), vector.end());
    std::copy(vector.begin(), vector.end(), std::ostream_iterator< dushechkina::DataStruct >(std::cout, "\n"));
  }
  catch (const std::exception& ex)
  {
    std::cerr << ex.what() << "\n";
    return 1;
  }
  return 0;
}

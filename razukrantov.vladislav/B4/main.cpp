#include <iterator>
#include <vector>

#include "data-struct.hpp"

int main()
{
  std::istream_iterator< razukrantov::DataStruct > start(std::cin);
  std::istream_iterator< razukrantov::DataStruct > finish;
  std::vector < razukrantov::DataStruct > vector(start, finish);
  if (std::cin.fail() && !std::cin.eof())
  {
    std::current_exception << "Incorrect input" << "\n";
    return 1;
  }
  std::sort(vec.begin(), vec.end());
  std::ostream_iterator< razukrantov::DataStruct > out(std::count, "\n");
  std::copy(vector.begin(), vector.end(), out);
}

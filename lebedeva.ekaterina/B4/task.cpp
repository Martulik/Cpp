#include "task.hpp"
#include <vector>
#include <algorithm>
#include <iterator>
#include "data-struct.hpp"
#include "functions.hpp"

void lebedeva::doTask1(std::istream& in, std::ostream& out)
{
  std::string inStr;
  std::istream_iterator< DataStruct > inIterFirst(in);
  std::istream_iterator< DataStruct > inIterLast;
  std::vector< DataStruct > data(inIterFirst, inIterLast);
  if (in.fail() && !in.eof())
  {
    throw std::ios_base::failure("Invalid input\n");
  }
  if (data.size() > 1)
  {
    std::sort(data.begin(), data.end());
  }
  std::ostream_iterator< DataStruct > output(out, "\n");
  std::copy(data.begin(), data.end(), output);
}

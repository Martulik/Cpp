#include "tasks.hpp"
#include <string>
#include <iostream>
#include <iterator>
#include <set>

void ferapontov::task1(std::istream& in, std::ostream& out)
{
  std::istream_iterator< std::string > begin(in);
  std::istream_iterator< std::string > end;
  std::set< std::string > set(begin, end);
  std::copy(set.begin(), set.end(), std::ostream_iterator< std::string >(out, "\n"));
}
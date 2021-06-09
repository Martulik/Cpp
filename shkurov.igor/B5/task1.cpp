#include "tasks.hpp"

#include <iostream>
#include <unordered_set>
#include <string>

namespace lab = shkurov;
using istreamIt = std::istream_iterator< std::string >;

void lab::task1(std::istream& in, std::ostream& out)
{
  std::unordered_set< std::string > set((istreamIt(in)), istreamIt());
  std::copy(set.begin(), set.end(), std::ostream_iterator< std::string >(out, "\n"));
}

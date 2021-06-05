#include "tasks.hpp"

#include <unordered_set>
#include <string>

namespace lab = shkurov;
using istreamIt = std::istream_iterator< std::string >;

void task1(std::istream& in, std::ostream& out)
{
  std::unordered_set< std::string > set;
  std::copy(istreamIt(in), istreamIt(), std::inserter(set, std::next(set.begin())));
  std::copy(istreamIt(in), istreamIt(), std::ostream_iterator< std::string >( out, "\n"));
}

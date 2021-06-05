#include "tasks.hpp"

#include <unordered_set>
#include <string>

namespace lab = shkurov;
using istreamIt = std::istream_iterator< std::string >;

void task1(std::istream& in, std::ostream& out)
{
  std::unordered_set< std::string > set(istreamIt(in), istreamIt());
  std::copy(istreamIt(in), istreamIt(), std::ostream_iterator< std::string >( out, "\n"));
}

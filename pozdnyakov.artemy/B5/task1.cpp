#include "tasks.hpp"
#include <set>
#include <iterator>
#include <algorithm>

namespace poz = pozdnyakov;

void poz::task1(std::istream& in, std::ostream& out)
{
  auto eos = std::istream_iterator< std::string >();
  std::set< std::string > textSet(std::istream_iterator< std::string >(in), eos);
  std::copy(textSet.cbegin(), textSet.cend(), std::ostream_iterator< std::string >(out, "\n"));
}

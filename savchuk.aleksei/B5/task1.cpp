#include "tasks.hpp"

#include <set>
#include <string>
#include <iterator>
#include <algorithm>
#include <iostream>

namespace lab = savchuk;

void lab::doTask1(std::istream& is, std::ostream& os)
{
  std::istream_iterator< std::string > first(is);
  std::istream_iterator< std::string > last;
  std::set< std::string > words(first, last);
  std::copy(words.cbegin(), words.cend(), std::ostream_iterator< std::string >(os, "\n"));
}

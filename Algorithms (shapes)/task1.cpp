#include "task1.hpp"
#include <iostream>
#include <set>
#include <iterator>

namespace lab = ezerinia;

void lab::task1(std::istream &in, std::ostream &out)
{
  std::set< std::string > words;
  words.insert(std::istream_iterator< std::string >(in), std::istream_iterator< std::string >());
  std::copy(words.begin(), words.end(), std::ostream_iterator< std::string >(out, "\n"));
}

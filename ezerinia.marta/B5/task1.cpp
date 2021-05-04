#include "task1.hpp"
#include <fstream>
#include <iostream>
#include <set>
#include <iterator>

namespace lab = ezerinia;

void lab::task1()
{
  std::set< std::string > words;
  words.insert(std::istream_iterator< std::string >(std::cin), std::istream_iterator< std::string >());
  std::copy(words.begin(), words.end(), std::ostream_iterator< std::string >(std::cout, "\n"));
}

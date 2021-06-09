#include "functions.hpp"
#include <iterator>

std::set< std::string >& lebedeva::doInputWords(std::istream& in)
{
  std::istream_iterator< std::string > inIterFirst(in);
  std::istream_iterator< std::string > inIterLast;
  std::set< std::string > words(inIterFirst, inIterLast);
  return words;
}

void lebedeva::doOutputWords(std::ostream& out, std::set< std::string >& words)
{
  std::ostream_iterator< std::string > outIter(out, "\n");
  std::copy(words.begin(), words.end(), outIter);
}

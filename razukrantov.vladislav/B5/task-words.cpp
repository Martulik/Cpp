#include "tasks.hpp"

#include <iostream>
#include <iterator>
#include <set>

void razukrantov::wordsTask(std::istream& in, std::ostream& out)
{
  std::istream_iterator< std::string > startIter(in);
  std::istream_iterator< std::string > finishIter;
  std::set< std::string > words(startIter, finishIter);
  std::ostream_iterator< std::string > outIter(out, "\n");
  std::copy(words.begin(), words.end(), outIter);
}

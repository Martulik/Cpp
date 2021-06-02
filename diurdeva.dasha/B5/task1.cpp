#include "task1.hpp"
#include <iostream>
#include <iterator>
#include <unordered_set>

void diurdeva::task1(std::istream& in, std::ostream& out)
{
  std::istream_iterator< std::string > firstIterator(in);
  std::istream_iterator< std::string > lastIterator;
  std::unordered_set< std::string > words(firstIterator, lastIterator);
  if (std::cin.fail() && !std::cin.eof()) {
    throw std::runtime_error("Stream reading failed");
  }
  std::ostream_iterator< std::string > output(out, "\n");
  std::copy(words.begin(), words.end(), output);
}

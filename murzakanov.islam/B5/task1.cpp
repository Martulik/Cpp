#include "tasks.hpp"

#include <iostream>
#include <unordered_set>
#include <string>
#include <iterator>

void murzakanov::task1(std::istream& in, std::ostream& out)
{
  std::unordered_set< std::string > words{std::istream_iterator< std::string >(in), std::istream_iterator< std::string >()};
  std::copy(words.begin(), words.end(), std::ostream_iterator< std::string >(out, "\n"));
}

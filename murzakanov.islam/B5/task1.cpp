#include "tasks.hpp"

#include <iostream>
#include <unordered_set>
#include <string>
#include <iterator>

int murzakanov::task1(std::istream& in, std::ostream& out)
{
  std::istream_iterator firstIt< std::string >(in);
  std::istream_iterator lastIt< std::string>;
  std::unordered_set< std::string > words(firstIt, lastIt);
  if (in.fail() && !in.eof())
  {
    std::cerr << "Input error\n";
    return;
  }
  std::copy(words.begin(), words.end(), std::ostream_iterator< std::string >(out, "\n"));
}

#include "tasks.hpp"

#include <iostream>
#include <unordered_set>
#include <string>
#include <iterator>

int murzakanov::task1(std::istream& in, std::ostream& out)
{
  std::istream_iterator< std::string > firstIt(in);
  std::istream_iterator< std::string > lastIt;
  std::unordered_set< std::string > words(firstIt, lastIt);
  if (in.fail() && !in.eof())
  {
    std::cerr << "Input error\n";
    return 1;
  }
  std::copy(words.begin(), words.end(), std::ostream_iterator< std::string >(out, "\n"));
  return 0;
}

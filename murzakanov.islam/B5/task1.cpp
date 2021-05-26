#include "tasks.hpp"

#include <iostream>
#include <unordered_set>
#include <string>
#include <iterator>

int murzakanov::task1(std::istream& in, std::ostream& out)
{
  int code = 0;
  std::istream_iterator< std::string > firstIt(in);
  std::istream_iterator< std::string > lastIt;
  std::unordered_set< std::string > words(firstIt, lastIt);
  if (in.fail() && !in.eof())
  {
    std::cerr << "Input error\n";
    code = 1;
  }
  else
  {
    std::copy(words.begin(), words.end(), std::ostream_iterator< std::string >(out, "\n"));
  }
  return code;
}

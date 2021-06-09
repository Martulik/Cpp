#include "tasks.hpp"
#include <iostream>
#include <iterator>
#include <string>
#include <set>
#include "functions.hpp"

void lebedeva::doTask1(std::istream& in, std::ostream& out)
{
  std::set< std::string > words = doInputWords(in);
  doOutputWords(out, words);
}

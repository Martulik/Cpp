#include "tasks.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <iterator>

int lysenko::task1(std::istream& in, std::ostream& out)
{
  std::istream_iterator< std::string > begin(in);
  std::istream_iterator< std::string > end;
  std::set< std::string > uniqueWords(begin, end);
  std::copy(uniqueWords.begin(), uniqueWords.end(), std::ostream_iterator< std::string >(out, "\n"));
  return 0;
}

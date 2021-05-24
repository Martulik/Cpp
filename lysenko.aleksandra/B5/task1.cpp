#include "tasks.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <iterator>

int lysenko::task1(std::istream& in, std::ostream& out)
{
  std::set< std::string > uniqueWords;
  while (!in.eof())
  {
    in >> std::ws;
    std::string word;
    in >> word;
    if (word.size() != 1)
    {
      uniqueWords.insert(word);
    }
  }
  std::copy(uniqueWords.begin(), uniqueWords.end(), std::ostream_iterator< std::string >(out, "\n"));
  return 0;
}

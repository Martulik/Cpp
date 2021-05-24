#include "tasks.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>

int lysenko::task1(std::istream& in, std::ostream& out)
{
  std::set< std::string > uniqueWords;
  while (!in.eof())
  {
    std::streampos numberOfReadLetters = 0;
    std::string word;
    in >> std::ws;
    if (!((in.peek() == ' ') || (in.peek() == '\n') || (in.peek() == '\t')))
    {
      char wordLetter;
      in >> wordLetter;
      numberOfReadLetters += 1;;
    }
    else
    {
      char delimiter;
      in >> delimiter;
      in.seekg(in.tellg() - numberOfReadLetters);
      getline(in, word, delimiter);

      uniqueWords.insert(word);
    }
  }
  std::copy(uniqueWords.begin(), uniqueWords.end(), std::ostream_iterator< std::string >(out, "\n"));
  return 0;
}

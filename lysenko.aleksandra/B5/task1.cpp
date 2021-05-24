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
    std::streampos numberOfReadLetters = 0;
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
      std::string word;
      in.seekg(in.tellg() - numberOfReadLetters);
      getline(in, word, delimiter);
      if (word.size() != 0)
      {
        uniqueWords.insert(word);
      }
    }
  }
  std::copy(uniqueWords.begin(), uniqueWords.end(), std::ostream_iterator< std::string >(out, "\n"));
  return 0;
}

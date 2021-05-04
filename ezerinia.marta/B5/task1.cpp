#include "task1.hpp"
#include <fstream>
#include <iostream>
#include <set>

namespace lab = ezerinia;

void lab::task1(const char *input)
{
  std::ifstream file;
  file.open(input);
  if (!file) {
    throw std::runtime_error("File error");
  }
  std::set< std::string > words;
  while (!file.eof()) {
    std::string word;
    file >> word;
    words.insert(word);
  }
  file.close();
  std::copy(words.begin(), words.end(), std::ostream_iterator< std::string >(std::cout, "\n"));
}

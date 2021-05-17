#include <iostream>
#include <set>
#include "task2.hpp"

namespace dan = doroshin;

int task1(std::istream& in, std::ostream& out)
{
  std::set< std::string > dict;
  while(in) {
    std::string word;
    in >> std::ws >> word;
    if(!word.empty()) {
      dict.emplace(std::move(word));
    }
  }
  for(auto&& word: dict) {
    out << word << '\n';
  }
  return 0;
}

int main(int argc, char* argv[])
{
  if(argc != 2) {
    std::cerr << "Provide a task number\n";
    return 1;
  }
  if(argv[1][1] != '\0') {
    std::cerr << "Extra characters in task number\n";
    return 1;
  }
  if(argv[1][0] == '1') {
    return task1(std::cin, std::cout);
  }
  else if(argv[1][0] == '2') {
    return dan::task2(std::cin, std::cout, std::cerr);
  }
  else {
    std::cerr << "Unknown task number\n";
    return 1;
  }
  return 0;
}

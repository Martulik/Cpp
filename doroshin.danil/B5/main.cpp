#include <iostream>
#include <set>
#include <iterator>
#include "task2.hpp"

namespace dan = doroshin;

int task1(std::istream& in, std::ostream& out)
{
  std::istream_iterator< std::string > iBegin(in), iEnd;
  std::set< std::string > dict(iBegin, iEnd);
  std::ostream_iterator< std::string > iOut(out, "\n");
  std::move(dict.begin(), dict.end(), iOut);
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

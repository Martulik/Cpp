#include "task-words.hpp"
#include <iostream>
#include <iterator>
#include <set>

namespace shilyaev {
  int runWordsTask()
  {
    std::istream_iterator< std::string > istreamIterator(std::cin);
    std::istream_iterator< std::string > istreamIteratorEnd;
    std::set< std::string > words(istreamIterator, istreamIteratorEnd);
    if (std::cin.fail() && !std::cin.eof()) {
      std::cerr << "Input error";
      return 2;
    }
    std::ostream_iterator< std::string > ostreamIterator(std::cout, "\n");
    std::copy(words.begin(), words.end(), ostreamIterator);
    return 0;
  }
}

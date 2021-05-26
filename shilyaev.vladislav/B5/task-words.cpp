#include "task-words.hpp"
#include <iostream>
#include <iterator>
#include <set>

namespace shilyaev {
  int runWordsTask(std::istream &istream, std::ostream &ostream, std::ostream &err)
  {
    std::istream_iterator< std::string > istreamIterator(istream);
    std::istream_iterator< std::string > istreamIteratorEnd;
    std::set< std::string > words(istreamIterator, istreamIteratorEnd);
    if (istream.fail() && !istream.eof()) {
      err << "Input error";
      return 2;
    }
    std::ostream_iterator< std::string > ostreamIterator(ostream, "\n");
    std::copy(words.cbegin(), words.cend(), ostreamIterator);
    return 0;
  }
}

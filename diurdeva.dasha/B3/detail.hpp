#ifndef DETAIL_HPP
#define DETAIL_HPP

#include <string>

namespace diurdeva {
  bool refactorAndCheckName(std::string& name);
  bool isNumberValid(const std::string&);
  bool isBookmarkValid(const std::string&);
}

#endif

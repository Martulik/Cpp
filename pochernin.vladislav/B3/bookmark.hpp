#ifndef BOOKMARK_HPP
#define BOOKMARK_HPP

#include <string>

namespace pochernin
{
  struct Bookmark
  {
    std::string name;
  };
  bool operator<(const Bookmark& lhs, const Bookmark& rhs);
}

#endif

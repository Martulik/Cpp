#include "bookmark.hpp"

bool pochernin::operator<(const Bookmark& lhs, const Bookmark& rhs)
{
  return lhs.name < rhs.name;
}

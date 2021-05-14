#include "bookmark.hpp"

bool pochernin::operator<(const Bookmark& lhs, const Bookmark& rhs)
{
  return lhs.name < rhs.name;
}

std::istream& pochernin::operator>>(std::istream& in, Bookmark& bookmark)
{
  in >> std::ws >> bookmark.name;
  return in;
}

#include "detail.hpp"

bool diurdeva::isBookmarkValid(const std::string& bookmark)
{
  for (auto&& symbol: bookmark)
  {
    if (!isalnum(symbol) && (symbol != '-'))
    {
      return false;
    }
  }

  return !bookmark.empty();
}

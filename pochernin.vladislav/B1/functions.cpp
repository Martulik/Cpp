#include "functions.hpp"

bool pochernin::isAscending(const char* sortingDirection)
{
  if (sortingDirection == nullptr)
  {
    throw(std::invalid_argument("Incorrect sorting direction"));
  }
  if (!strcmp(sortingDirection, "ascending"))
  {
    return true;
  }
  else if (!strcmp(sortingDirection, "descending"))
  {
    return false;
  }
  else
  {
    throw(std::invalid_argument("Incorrect sorting direction"));
  }
}

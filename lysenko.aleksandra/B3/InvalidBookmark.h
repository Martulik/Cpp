#ifndef INVALID_BOOKMARK
#define INVALID_BOOKMARK

#include <exception>

class InvalidBookmark: public std::exception
{
public:
  virtual const char* what() const noexcept
  {
    return  "<INVALID BOOKMARK>";
  }
};
#endif


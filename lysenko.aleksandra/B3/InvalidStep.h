#ifndef INVALID_STEP
#define INVALID_STEP

#include <exception>

class InvalidStep : public std::exception
{
public:
  virtual const char* what() const noexcept
  {
    return  "<INVALID STEP>";
  }
};
#endif

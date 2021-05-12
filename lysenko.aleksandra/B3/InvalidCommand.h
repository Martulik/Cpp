#ifndef INVALID_COMMAND
#define INVALID_COMMAND

#include <exception>

class InvalidCommand : public std::exception
{
public:
  virtual const char* what() const noexcept
  {
    return  "<INVALID COMMAND>";
  }
};
#endif

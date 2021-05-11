#ifndef INVALID_BOOKMARK
#define INVALID_BOOKMARK

#include <exception>

class InvalidBookmark : public std::exception
{
public:
  virtual const char* what() const noexcept
  {
    return  "<INVALID BOOKMARK>";
  }
};
#endif

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

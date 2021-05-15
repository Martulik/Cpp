#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

namespace lysenko
{
  class InvalidStep: public std::exception
  {
  public:
    virtual const char* what() const noexcept;
  };

  class InvalidbookMark: public std::exception
  {
  public:
    virtual const char* what() const noexcept;
  };

  class InvalidCommand: public std::exception
  {
  public:
    virtual const char* what() const noexcept;
  };
}

#endif
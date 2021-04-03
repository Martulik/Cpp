#include "exceptions.hpp"

const char* pozdnyakov::ScaleException::what() const noexcept
{
  return error_;
}

const char* pozdnyakov::ShapeArgException::what() const noexcept
{
  return error_;
}

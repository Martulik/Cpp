#include "exceptions.hpp"

const std::string pozdnyakov::ScaleException::what() const
{
  return error_;
}

const std::string pozdnyakov::ShapeArgException::what() const
{
  return error_;
}

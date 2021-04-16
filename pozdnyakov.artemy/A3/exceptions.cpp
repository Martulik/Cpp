#include "exceptions.hpp"

const std::string ScaleException::what() const
{
  return error_;
}

const std::string ShapeArgException::what() const
{
  return error_;
}

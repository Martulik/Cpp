#include "task-phone-book-exception.hpp"

const char *shilyaev::InvalidCommandException::what() const noexcept
{
  return "Invalid Command";
}

const char *shilyaev::InvalidStepException::what() const noexcept
{
  return "Invalid Step";
}

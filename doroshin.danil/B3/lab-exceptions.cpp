#include "lab-exceptions.hpp"

namespace dan = doroshin;

const char* dan::InvalidBookmarkException::what() const noexcept
{
  return "<INVALID BOOKMARK>";
}

const char* dan::EmptyPhoneBookException::what() const noexcept
{
  return "<EMPTY>";
}

const char* dan::InvalidCommandException::what() const noexcept
{
  return "<INVALID COMMAND>";
}

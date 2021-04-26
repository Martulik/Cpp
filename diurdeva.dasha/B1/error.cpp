#include "error.hpp"

diurdeva::Error::Error() :
  error_message_("Success")
{}

void diurdeva::Error::set(const std::string& err)
{
  error_message_ = err;
}

bool diurdeva::Error::isError() const
{
  if (error_message_ == "Success") {
    return true;
  }
  else {
    return false;
  }
}

std::string diurdeva::Error::getError() const
{
  return error_message_;
}

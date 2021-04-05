#include "lab-exception.hpp"

doroshin::LabException::LabException(std::string msg, bool fatal):
  message_(std::move(msg)),
  fatal_(fatal)
{}

const char* doroshin::LabException::what() const noexcept
{
  return message_.c_str();
}

bool doroshin::LabException::fatal() const noexcept
{
  return fatal_;
}

#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <exception>
#include <string>

namespace pozdnyakov
{
  class ScaleException: public std::exception
  {
  public:
    ScaleException() = default;
    const char* what() const noexcept override;

  private:
    const char* error_ = static_cast<char*>(const_cast<char*>("Wrong scale coefficient"));
  };

  class ShapeArgException: public std::exception
  {
  public:
    ShapeArgException() = default;
    const char* what() const noexcept override;

  private:
    const char* error_ = static_cast<char*>(const_cast<char*>("Wrong shape argument"));
  };
}

#endif

#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <exception>
#include <string>

namespace pozdnyakov
{
  class ScaleException
  {
  public:
    ScaleException() = default;
    const std::string what() const;

  private:
    const std::string error_ = "Wrong scale coefficient";
  };

  class ShapeArgException
  {
  public:
    ShapeArgException() = default;
    const std::string what() const;

  private:
    const std::string error_ = "Wrong shape argument";
  };
}

#endif

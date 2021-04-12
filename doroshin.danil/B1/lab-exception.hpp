#ifndef LAB_EXCEPTION_HPP
#define LAB_EXCEPTION_HPP

#include <exception>
#include <string>

namespace doroshin
{
  class LabException: public std::exception
  {
  public:
    explicit LabException(std::string msg, bool fatal = true) noexcept;

    bool fatal() const noexcept;
    const char* what() const noexcept override;
  private:
    std::string message_;
    bool fatal_;
  };
}

#endif //LAB_EXCEPTION_HPP

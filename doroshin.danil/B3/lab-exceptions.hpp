#ifndef LAB_EXCEPTIONS_HPP
#define LAB_EXCEPTIONS_HPP

#include <exception>

namespace doroshin
{
  class PhoneBookException: public std::exception
  {
  public:
    const char* what() const noexcept = 0;
  };

  class InvalidBookmarkException: public PhoneBookException
  {
  public:
    const char* what() const noexcept override;
  };

  class EmptyPhoneBookException: public PhoneBookException
  {
  public:
    const char* what() const noexcept override;
  };

  class InvalidCommandException: public std::exception
  {
  public:
    const char* what() const noexcept override;
  };
}

#endif //LAB_EXCEPTIONS_HPP

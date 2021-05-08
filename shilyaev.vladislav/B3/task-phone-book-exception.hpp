#ifndef TASK_PHONE_BOOK_EXCEPTION_HPP
#define TASK_PHONE_BOOK_EXCEPTION_HPP

#include <exception>

namespace shilyaev {
  class InvalidCommandException: public std::exception {
    const char *what() const noexcept override;
  };

  class InvalidStepException: public std::exception {
    const char *what() const noexcept override;
  };
}

#endif

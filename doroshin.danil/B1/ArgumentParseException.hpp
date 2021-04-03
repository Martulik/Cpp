#ifndef ARGUMENT_PARSE_EXCEPTION_HPP
#define ARGUMENT_PARSE_EXCEPTION_HPP

#include <exception>
#include <string>

class ArgumentParseException: public std::exception
{
public:
  ArgumentParseException(std::string msg);

  const char* what() const noexcept override;
private:
  std::string message_;
};

#endif //ARGUMENT_PARSE_EXCEPTION_HPP

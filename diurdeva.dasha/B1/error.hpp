#ifndef ERROR_HPP
#define ERROR_HPP

#include <string>

namespace diurdeva {
  class Error {
  public:
    Error();
    void set(const std::string& error);
    bool isError() const;
    std::string getError() const;
  private:
    std::string error_message_;
  };
}

#endif

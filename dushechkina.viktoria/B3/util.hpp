#ifndef UTIL_HPP
#define UTIL_HPP
#include <iosfwd>
#include <string>
namespace dushechkina
{
  void checkForFailInput(const std::istream& in);
  void checkForEmptyInput(const std::string& in);
  constexpr const char* EMPTY = "<EMPTY>\n";
  constexpr const char* INVALID_STEP = "<INVALID STEP>\n";
  constexpr const char* INVALID_COMMAND = "<INVALID COMMAND>\n";
  constexpr const char* INVALID_BOOKMARK = "<INVALID BOOKMARK>\n";
}
#endif

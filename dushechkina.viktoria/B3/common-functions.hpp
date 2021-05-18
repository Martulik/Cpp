#ifndef COMMON_FUNCTIONS_HPP
#define COMMON_FUNCTIONS_HPP
#include <iosfwd>
#include <string>
namespace dushechkina
{
 void checkForFailInput(const std::istream& in);
 void checkForEmptyInput(const std::string& in);
}
#endif

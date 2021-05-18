#ifndef COMMON_FUNCTIONS_HPP
#define COMMON_FUNCTIONS_HPP
#include <iosfwd>
#include <string>
namespace dushechkina
{
 void checkForFailInput(const std::istream& in);
 void checkForEmptyInput(const std::string& in);
 void empty(std::ostream& out);
 void invalidCommand(std::ostream& out);
 void invalidBookmark(std::ostream& out);
 void invalidStep(std::ostream& out);
 void incorrectIndex(std::ostream& out);
}
#endif

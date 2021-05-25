#ifndef ERROR_MESSAGES_HPP
#define ERROR_MESSAGES_HPP
#include <iostream>

namespace lebedeva
{
  void invalidCommand(std::ostream& out);
  void invalidBookmark(std::ostream& out);
  void invalidStep(std::ostream& out);
  void empty(std::ostream& out);
}
#endif

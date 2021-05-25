#include "error-messages.hpp"

void lebedeva::invalidCommand(std::ostream& out)
{
  out << "<INVALID COMMAND>\n";
}

void lebedeva::invalidBookmark(std::ostream& out)
{
  out << "<INVALID BOOKMARK>\n";
}

void lebedeva::invalidStep(std::ostream& out)
{
  out << "<INVALID STEP>\n";
}

void lebedeva::empty(std::ostream& out)
{
  out << "<EMPTY>\n";
}

#include "functions.hpp"

void razukrantov::invalidCommand(std::ostream& out)
{
	out << "<INVALID COMMAND>\n";
}

void razukrantov::invalidBookmark(std::ostream& out)
{
	out << "<INVALID BOOKMARK>\n";
}

void razukrantov::invalidStep(std::ostream& out)
{
	out << "INVALID STEP>\n";
}

void razukrantov::empty(std::ostream& out)
{
	out << "<EMPTY>\n";
}

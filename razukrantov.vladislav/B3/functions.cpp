#include "functions.hpp"

#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

std::istream& razukrantov::readName(std::istream& in, std::string& name)
{
	name.clear();
	in >> std::ws;
	if (in.get() != '"')
	{
		in.setstate(std::ios_base::failbit);
		return in;
	}
	while (!in.eof())
	{
		char next = in.get();
		if (in.good())
		{
			if (next == '\\')
			{
				name += in.get();
			}
			else if (next != '"')
			{
				name += next;
			}
			else
			{
				break;
			}
		}
		else
		{
			in.setstate(std::ios_base::failbit);
		}
	}
	return in;
}

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
	out << "<INVALID STEP>\n";
}

void razukrantov::empty(std::ostream& out)
{
	out << "<EMPTY>\n";
}

#include "note.hpp"

#include <ostream>

std::ostream& razukrantov::operator<<(std::ostream& out, const razukrantov::note_t& note)
{
	out << note.number << ' ' << note.name << '\n';
	return out;
}

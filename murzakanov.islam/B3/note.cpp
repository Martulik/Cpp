#include "note.hpp"
#include <iostream>

std::ostream& murzakanov::operator<<(std::ostream& out, const murzakanov::note_t& note)
{
  out << note.number << " " << note.name << "\n";
  return out;
}

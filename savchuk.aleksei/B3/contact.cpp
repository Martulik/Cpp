#include "contact.hpp"

#include <ostream>

namespace lab = savchuk;

std::ostream& lab::operator<<(std::ostream& os, const lab::contact_t& contact)
{
  os << contact.number << ' ' << contact.name << '\n';
  return os;
}

#include "entry.hpp"
#include <iomanip>

namespace dan = doroshin;

std::istream& dan::operator>>(std::istream& in, Entry& ent)
{
  in >> ent.number_;
  if(in.peek() != ' ') {
    in.setstate(std::ios::failbit);
    return in;
  }
  in >> ent.name_;
  return in;
}

std::ostream& dan::operator<<(std::ostream& out, const Entry& ent)
{
  std::ios_base::fmtflags flags { out.flags() };
  out << std::setfill('0') << std::setw(12) << ent.number_ << ' ' << ent.name_;
  out.flags(flags);
  return out;
}

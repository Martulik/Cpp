#include "name.hpp"
#include "iostream"

namespace dan = doroshin;

std::istream& quotedString(std::istream& in, std::string& res)
{
  res.clear();
  while(in.get() != '"') {
    if(!in) {
      return in;
    }
  }
  while(!in.eof()) {
    char next = in.get();
    if(in.good()) {
      if(next == '\\') {
        res += in.get();
      }
      else if(next != '"') {
        res += next;
      }
      else {
        break;
      }
    }
    else {
      in.setstate(std::ios::failbit);
    }
  }
  return in;
}

std::istream& dan::operator>>(std::istream& in, Name& name)
{
  return quotedString(in, name.name_);
}

std::ostream& dan::operator<<(std::ostream& out, const Name& name)
{
  out << name.name_;
  return out;
}

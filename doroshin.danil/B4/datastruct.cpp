#include "datastruct.hpp"
#include <sstream>

namespace dan = doroshin;

std::istream& dan::operator>>(std::istream& in, DataStruct& data)
{
  const auto require_comma = [&](std::istream& is) -> std::istream& {
    if(is.get() != ',') {
      is.setstate(std::ios::failbit);
      in.setstate(std::ios::failbit);
    }
    return is;
  };

  std::string line_;
  if(std::getline(in, line_)) {
    std::istringstream line(line_);
    line >> data.key1;
    if(!require_comma(line)) {
      return in;
    }
    line >> data.key2;
    if(!require_comma(line)) {
      return in;
    }
    std::getline(line, data.str);
  }
  return in;
}

bool dan::sort_order(const DataStruct& lhs, const DataStruct& rhs)
{
  if(lhs.key1 != rhs.key1) {
    return lhs.key1 < rhs.key1;
  }
  else if (lhs.key2 != rhs.key2) {
    return lhs.key2 < rhs.key2;
  }
  else {
    return lhs.str.size() < rhs.str.size();
  }
}

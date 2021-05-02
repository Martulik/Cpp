#include "datastruct.hpp"
#include <sstream>

namespace dan = doroshin;

std::istream& dan::operator>>(std::istream& in, DataStruct& data)
{
  const auto fail = [&]() {
    in.setstate(in.rdstate() | std::ios::failbit);
  };

  std::string line_;
  if(std::getline(in, line_)) {
    std::istringstream line(line_);
    line >> data.key1;
    if(data.key1 < -5 || data.key1 > 5) {
      fail();
      return in;
    }
    if(line.get() != ',') {
      fail();
      return in;
    }
    line >> data.key2;
    if(data.key2 < -5 || data.key2 > 5) {
      fail();
      return in;
    }
    if(line.get() != ',') {
      fail();
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

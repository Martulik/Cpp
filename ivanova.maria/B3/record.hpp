#ifndef B3_RECORD_HPP
#define B3_RECORD_HPP

#include <iostream>

namespace ivanova
{
  struct Record
  {
    std::pair< std::string, std::string > data;
  };

  std::istream &operator >>(std::istream &in, Record &info);
  std::ostream &operator <<(std::ostream &out, Record &info);

  std::string getName(const std::string &name);
  bool checkNumber(const std::string &number);
  bool checkMark(const std::string &mark);
}

#endif

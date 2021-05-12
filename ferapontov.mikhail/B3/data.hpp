#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include <iostream>

namespace ferapontov
{
  struct data_t
  {
    std::string name;
    int number;
  };
  std::ostream& operator<<(std::ostream& out, const data_t& src);
}
#endif

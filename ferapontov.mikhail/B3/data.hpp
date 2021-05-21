#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include <iosfwd>

namespace ferapontov
{
  struct data_t
  {
    std::string name;
    std::string number;
  };
  std::ostream& operator<<(std::ostream& out, const data_t& src);
}
#endif

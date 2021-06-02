#ifndef LINE_HPP
#define LINE_HPP
#include <string>

namespace lebedeva
{
  struct Line
  {
    std::string lineTemp{};
    operator std::string() const
    {
      return lineTemp;
    }
  };
  std::istream& operator>>(std::istream& is, Line& line);
  std::ostream& operator<<(std::ostream& os, const Line& line);
}

#endif

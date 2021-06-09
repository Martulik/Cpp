#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <iosfwd>
#include <set>
#include <string>

namespace lebedeva
{
  std::set< std::string >& doInputWords(std::istream& in);
  void doOutputWords(std::ostream& out, std::set< std::string >& words);
}
#endif

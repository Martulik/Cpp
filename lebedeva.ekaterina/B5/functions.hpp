#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <iosfwd>
#include <set>
#include <string>
#include <vector>
#include "shape.hpp"

namespace lebedeva
{
  std::set< std::string > doInputWords(std::istream& in);
  void doOutputWords(std::ostream& out, std::set< std::string >& words);
  std::vector< Shape > doInputShapes(std::istream& in);

  void doSomeOutput(std::ostream& out, std::vector< Shape > shapes);
}
#endif

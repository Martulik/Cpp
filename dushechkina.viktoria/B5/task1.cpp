#include "tasks.hpp"

#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <set>
#include <stdexcept>

void dushechkina::task1(std::istream& in, std::ostream& out)
{
  std::istream_iterator< std::string > iter(in);
  std::set< std::string > vector(iter, std::istream_iterator < std::string >());
  std::copy(vector.begin(), vector.end(), std::ostream_iterator< std::string >(out, "\n"));
}

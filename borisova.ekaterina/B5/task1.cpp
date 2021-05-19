#include "tasks.hpp"
#include <iostream>
#include <iterator>
#include <string>
#include <unordered_set>

namespace lab = borisova;

void lab::doTask1(std::istream& in, std::ostream& out)
{
  using iterIn = std::istream_iterator<std::string>;
  std::unordered_set< std::string > temp{ iterIn(in), iterIn() };
  if (in.fail() && !in.eof())
  {
    throw std::invalid_argument("Invalid input\n");
  }
  std::copy(temp.begin(), temp.end(), std::ostream_iterator< std::string >(out, "\n"));
}

#include "Words.hpp"
#include <iostream>
#include <sstream>
#include <iterator>


std::istream &ivanova::operator >>(std::istream &in, ivanova::Words &list)
{
  std::istream_iterator< std::string > input(in);
  std::vector< std::string > newVec (input, std::istream_iterator< std::string > ());
  list.vector_ = std::move(newVec);
  return in;
}

std::ostream &ivanova::operator<<(std::ostream &out, ivanova::Words str)
{
  std::copy(str.vector_.begin(), str.vector_.end(), std::ostream_iterator< std::string > (out, "\n");
  return out;
}


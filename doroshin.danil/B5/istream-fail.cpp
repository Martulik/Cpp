#include "istream-fail.hpp"
#include <iostream>

std::istream& doroshin::fail(std::istream& in)
{
  in.setstate(in.rdstate() | std::ios::failbit);
  return in;
}

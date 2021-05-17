#ifndef B5_TASK1_HPP
#define B5_TASK1_HPP
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <iterator>

namespace ivanova
{
  int task1(std::istream &in, std::ostream &out)
  {
    std::istream_iterator< std::string > iss(in);
    std::set< std::string > vector(iss, std::istream_iterator < std::string >());
    std::copy(vector.begin(), vector.end(), std::ostream_iterator< std::string >(out, "\n"));
    return 0;
  }
}
#endif
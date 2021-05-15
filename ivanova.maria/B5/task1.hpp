#ifndef B5_TASK1_HPP
#define B5_TASK1_HPP
#include <iosfwd>
#include <string>
#include <vector>
#include <iterator>
//#include "Words.hpp"

namespace ivanova
{
  int task1(std::istream &in, std::ostream &out)
  {
    std::istream_iterator< std::string> iss(in);
    if (in.fail() || !in.eof())
    {
      std::cerr << "reading failed";
      return 1;
    }
    std::vector< std::string > vec(iss, std::istream_iterator< std::string > ());
    std::copy(vec.begin(), vec.end(), std::ostream_iterator< std::string > (out, "\n"));
    return 0;
  }
}
#endif
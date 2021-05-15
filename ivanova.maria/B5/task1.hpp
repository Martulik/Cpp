#ifndef B5_TASK1_HPP
#define B5_TASK1_HPP
#include <iostream>
#include <string>
#include <vector>
#include <iterator>

namespace ivanova
{
  int task1(std::istream &in, std::ostream &out)
  {
    std::istream_iterator< std::string> iss(in);
    std::vector< std::string > vec(iss, std::istream_iterator< std::string > ());
    if (in.fail() && !in.eof())
    {
      std::cerr << "failed reading";
      return 1;
    }
    std::copy(vec.begin(), vec.end(), std::ostream_iterator< std::string > (out, "\n"));
    return 0;
  }
}
#endif
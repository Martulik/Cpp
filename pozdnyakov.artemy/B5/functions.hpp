#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <functional>
#include <algorithm>
#include <cassert>
#include <string>

namespace pozdnyakov
{
  template < class T, class InputIterator >
  void for_each_and_first(InputIterator it1, InputIterator it2, std::function< void(T, T) >& op)
  {
    assert(it1 != it2);
    std::function< void(T) > boundOp = std::bind(op, *it1, std::placeholders::_1);
    std::for_each(std::next(it1), it2, boundOp);
  }
  template < class T, class InputIterator >
  void for_comb(InputIterator it1, InputIterator it2, std::function< void(T, T) >& op)
  {
    std::function< void(InputIterator) > boundForEach = std::bind(for_each_and_first< T, InputIterator >, std::placeholders::_1, it2, op);
  notFor:
    if (it1 != it2)
    {
      boundForEach(it1);
      it1++;
      goto notFor;
    }
  }
  void checkLineEnding(const std::string& str);
  bool compChar(char a, char b);
  bool compCharNeg(char a, char b);
  void removeWS(std::string& str);
}

#endif

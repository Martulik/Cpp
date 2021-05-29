#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <functional>
#include <cassert>

namespace pozdnyakov
{
  template < class InputIterator, class T, class Callable >
  void for_comb(InputIterator it1, InputIterator it2, Callable op)
  template < class InputIterator, class T, class Callable >
  void for_each_and_first(InputIterator it1, InputIterator it2, Callable op)
}

template < class InputIterator, class T, class Callable >
void poz::for_comb(InputIterator it1, InputIterator it2, Callable op)
{
  auto boundOp = std::bind(poz::for_each_and_first, std::placeholders::_1, it2, op);
  std::for_each(it1, it2, boundOp);
}

template < class InputIterator, class Callable >
void poz::for_each_and_first(InputIterator it1, InputIterator it2, Callable op)
{
  assert(it1 != it2);
  auto boundOp = std::bind(op, *it1, std::placeholders::_2);
  std::for_each(std::next(it1), it2, boundOp);
}

#endif

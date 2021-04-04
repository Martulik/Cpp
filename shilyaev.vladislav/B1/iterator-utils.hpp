#ifndef ITERATOR_UTILS_HPP
#define ITERATOR_UTILS_HPP

#include <iostream>

template < typename Iterator >
void print(Iterator begin, const Iterator &end);

template < typename Iterator >
Iterator advanced(Iterator iterator);

template < typename T >
void print(T t);

template <>
void print< char >(char t);

template < typename Iterator >
void print(Iterator begin, const Iterator &end)
{
  for (; begin != end; begin++) {
    print(*begin);
  }
  std::cout << '\n';
}

template < typename Iterator >
Iterator advanced(Iterator iterator)
{
  return ++iterator;
}

template < typename T >
void print(T t)
{
  std::cout << t << ' ';
}

#endif

#ifndef COMPARATOR_HPP
#define COMPARATOR_HPP

#include <cstring>

template<typename T>
bool cmpAscending(const T& a, const T& b)
{
  return a < b;
}

template<typename T>
bool cmpDescending(const T& a, const T& b)
{
  return a > b;
}

template<typename T>
bool (*getComparator(const char* order))(const T&, const T&)
{
  bool (*comparator)(const T&, const T&) = nullptr;
  if (strcmp(order, "ascending") == 0)
  {
    comparator = cmpAscending<T>;
  }
  else if (strcmp(order, "ascending") == 0)
  {
    comparator = cmpDescending<T>;
  }
  return comparator;
}

#endif
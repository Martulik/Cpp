#ifndef B1_SORT_HPP
#define B1_SORT_HPP

#include <functional>
#include <string>
#include "strategy.hpp"

namespace dushechkina
{
  template<template<class> class Strategy, class T>
  void sort(T& container, std::function<bool(const typename T::value_type, const typename T::value_type)> comparator)
  {
    typename Strategy<T>::iterator i = Strategy<T>::begin(container);
    typename Strategy<T>::iterator j = Strategy<T>::begin(container);
    typename Strategy<T>::iterator end = Strategy<T>::end(container);
    while (i != end)
    {
      j = i;
      while (++j != end)
      {
        typename T::value_type& temp = Strategy<T>::get(container, j);
        typename T::value_type& temp1 = Strategy<T>::get(container, i);
        if (comparator(temp, temp1))
        {
          std::swap(temp, temp1);
        }
      }
      i++;
    }
  }
}
#endif

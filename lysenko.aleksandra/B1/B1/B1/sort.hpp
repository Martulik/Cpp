#ifndef SORT_HPP
#define SORT_HPP

#include <vector>
#include <forward_list>
#include "strategies.hpp"

namespace lysenko
{
  template< template< typename > typename sortBy, typename container_type >
  void sortShaker(container_type& container,
    bool (*cmp)(const typename container_type::value_type& a, const typename container_type::value_type& b))
  {
    if (cmp == nullptr)
    {
      throw std::invalid_argument("The comparator was not passed");
    }

    typedef sortBy<container_type> sortStrategy;
    typedef typename sortStrategy::iterator iterator;

    iterator left = 0;
    iterator right = sortStrategy::getEnd(container) - 1;
    while (left <= right)
    {
      for (iterator i = right; i > left; --i)
      {
        if (cmp), sortStrategy::getElement(container, i), sortStrategy::getElement(container, i - 1)))
        {
          std::swap(sortStrategy::getElement(container,i), sortStrategy::getElement(container, i - 1));
        }
        ++left;

        for (iterator i = left ; i < right; ++i)
        {
          if (cmp), sortStrategy::getElement(container, i + 1), sortStrategy::getElement(container, i)))
        {
        std::swap(sortStrategy::getElement(container, i + 1), sortStrategy::getElement(container, i));
        }
        --right;
    }
  }
}
#endif
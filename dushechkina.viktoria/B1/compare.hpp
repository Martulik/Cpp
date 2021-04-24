#ifndef B1_COMPARE_HPP
#define B1_COMPARE_HPP

#include <functional>
#include <stdexcept>
#include <string>
#include "strategy.hpp"

namespace dushechkina
{
  template<class T>
  std::function<bool(const T, const T)> getSortingOrder(const char* order)
  {
    std::string ascending = "ascending";
    std::string descending = "descending";
    if (order == nullptr)
    {
      throw std::invalid_argument("Sorting order is undefined");
    }
    if (order == ascending)
    {
      return std::less<const T>();
    }
    if (order == descending)
    {
      return std::greater<const T>();
    }
    else
    {
      throw std::invalid_argument("Sorting order is incorrect");
    }
  }
}
#endif

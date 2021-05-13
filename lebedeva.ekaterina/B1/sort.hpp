#ifndef SORT_HPP
#define SORT_HPP
#include <functional>
#include "access.hpp"

namespace lebedeva
{
  template < template< typename > class Access, class T >
  void sort(T& data, std::function< bool( typename T::value_type, typename T::value_type) > comp)
  {
    using Iterator = typename Access< T >::Iterator;
    using acc = Access< T >;
    using valueType = typename T::value_type;
    for (Iterator i = acc::begin(data); i != acc::end(data); ++i)
    {
      for (Iterator j = i; j != acc::end(data); ++j)
      {
        valueType& temp1 = acc::get(data, i);
        valueType& temp2 = acc::get(data, j);
        if (comp(temp1, temp2))
        {
          std::swap(temp1, temp2);
        }
      }
    }
  }
}

#endif

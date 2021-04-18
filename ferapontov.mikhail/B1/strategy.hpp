#ifndef STRATEGY_HPP
#define STRATEGY_HPP

#include <vector>

namespace ferapontov
{
  template< typename T >
  struct index_access
  {
    using iterator_t = size_t;
    using container_t = std::vector<T>;

    static iterator_t begin(const container_t&)
    {
      return 0;
    }

    static iterator_t end(const container_t& data)
    {
      return data.size();
    }

    static T& element(container_t& data, iterator_t& index)
    {
      return data[index];
    }
  };

  template< typename T >
  struct at_access
  {
    using iterator_t = size_t;
    using container_t = std::vector<T>;

    static iterator_t begin(const container_t&)
    {
      return 0;
    }

    static iterator_t end(const container_t& data)
    {
      return data.size();
    }

    static T& element(container_t& data, iterator_t& index)
    {
      return data.at(index);
    }
  };
}

#endif 

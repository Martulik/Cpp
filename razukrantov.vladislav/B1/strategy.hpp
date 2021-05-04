#ifndef STRATEGY_HPP
#define STRATEGY_HPP

namespace razukrantov
{
  template< typename T >
  struct bracketsAcess
  {
    using iterator = size_t;
    using container = std::vector<T>;

    static iterator begin(const container&)
    {
      return 0;
    }

    static iterator end(const container& container)
    {
      return container.size();
    }

    static T& get(container& container, iterator& iterator)
    {
      return container[iterator];
    }
  };

  template < typename T >
  struct atAccess
  {
    using iterator = size_t;
    using container = std::vector<T>;

    static iterator begin(const container&)
    {
      return 0;
    }

    static iterator end(const container& container)
    {
      return container.size();
    }
    static T& get(container& container, iterator& iterator)
    {
      return container.at(iterator);
    }
  };
}

#endif

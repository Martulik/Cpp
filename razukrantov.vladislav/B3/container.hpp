#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <iterator>
#include <cstddef>

namespace razukrantov
{
  class Container
  {
  public:
    using valueType = unsigned int;
    class Iterator: public std::iterator< std::bidirectional_iterator_tag, valueType >
    {
    public:
      Iterator& operator++();
      Iterator operator++(int);
      Iterator& operator--();
      Iterator operator --(int);
      const valueType& operator*();
      const valueType* operator->();
      bool operator==(const Iterator&) const;
      bool operator!=(const Iterator&) const;

    private:
      friend class Container;
      valueType index_;
      valueType value_;
      explicit Iterator(valueType number);
    };

    Container() = default;
    Iterator begin() const noexcept;
    Iterator end() const noexcept;
  };
}

#endif

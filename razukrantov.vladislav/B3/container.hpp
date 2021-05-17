#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <iterator>
#include <cstddef>

namespace razukrantov
{
  class Container
  {
  public:
    class Iterator: public std::iterator< std::bidirectional_iterator_tag, unsigned int >
    {
    public:
      Iterator& operator++();
      Iterator operator++(int);
      Iterator& operator--();
      Iterator operator --(int);
      size_t& operator*();
      size_t* operator->();
      bool operator==(const Iterator&) const;
      bool operator!=(const Iterator&) const;

    private:
      friend class Container;
      size_t index_;
      size_t value_;
      Iterator(size_t number);
    };

    Container() = default;
    Iterator begin() const noexcept;
    Iterator end() const noexcept;
  };
}

#endif

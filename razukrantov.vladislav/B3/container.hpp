#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <iterator>
#include <cstddef>

namespace razukrantov
{
  class Container
  {
  public:
    class Iterator : public std::iterator< std::bidirectional_iterator_tag, unsigned int >
    {
    public:
      //using ValueType = unsigned int;
      Iterator();

      Iterator& operator++();
      Iterator operator++(int);
      Iterator& operator--();
      Iterator operator --(int);
      size_t& operator*();
      size_t* operator->();
      bool operator==(const Iterator&) const;
      bool operator!=(const Iterator&) const;

    private:
      size_t index_;
      size_t value_;
    };

    Container() = default;
    Iterator begin();
    Iterator end();
  };
}

#endif

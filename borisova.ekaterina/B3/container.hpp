#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <iterator>

namespace borisova
{
  class Container
  {
  public:

    class Iterator;
    Container() = default;
    Iterator begin() const;
    Iterator end() const;
  };

  class Container::Iterator: public std::iterator< std::bidirectional_iterator_tag, size_t >
  {
  public:
    Iterator();
    Iterator& operator++();
    Iterator operator++(int);
    Iterator& operator--();
    Iterator operator--(int);
    bool operator==(const Iterator& src) const;
    bool operator!=(const Iterator& src) const;
    size_t& operator*();
    size_t* operator->();
    Iterator getBegin() const;
    Iterator getEnd() const;

  private:
    Iterator(size_t index);
    size_t index_;
    size_t value_;
    constexpr size_t factorial(size_t index);
  };
}

#endif

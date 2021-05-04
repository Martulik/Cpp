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
    Iterator begin();
    Iterator end();
  };

  class Container::Iterator: public std::iterator< std::bidirectional_iterator_tag, size_t >
  {
  public:

    Iterator(size_t index);
    Iterator& operator++();
    Iterator operator++(int);
    Iterator& operator--();
    Iterator operator--(int);
    bool operator==(const Iterator& src) const;
    bool operator!=(const Iterator& src) const;
    size_t& operator*();

  private:
    size_t index_;
    size_t value_;
  };

  const size_t minimum = 1;
  const size_t maximum = 11;
}

#endif

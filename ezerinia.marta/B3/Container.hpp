#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <iterator>

namespace ezerinia {
  class Container {
  public:
    class Iterator;
    Container() = default;
    Iterator begin();
    Iterator end();
  };
  class Container::Iterator: public std::iterator< std::bidirectional_iterator_tag, unsigned int > {
  public:
    Iterator(size_t index);
    Iterator &operator++();
    Iterator &operator--();
    Iterator operator++(int);
    Iterator operator--(int);
    bool operator==(const Iterator &src) const;
    bool operator!=(const Iterator &src) const;
    unsigned int &operator*();
    unsigned int *operator->();
  private:
    size_t index_;
    unsigned int value_;
    unsigned int getFactorial(size_t index) const;
  };
}
#endif

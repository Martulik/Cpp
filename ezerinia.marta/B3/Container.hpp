#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <iterator>

class Container {
public:
  Container() = default;

  class Iterator;

  Iterator begin();

  Iterator end();
};

class Container::Iterator: public std::iterator< std::bidirectional_iterator_tag, unsigned int > {
public:
  Iterator(size_t index);

  bool operator==(const Iterator &src) const;

  bool operator!=(const Iterator &src) const;

  unsigned int &operator*();

  unsigned int *operator->();

  Iterator &operator++();

  Iterator &operator--();

  Iterator operator++(int);

  Iterator operator--(int);

private:
  size_t index_;
  unsigned int value_;

  unsigned int getFactorial(size_t index) const;
};

#endif

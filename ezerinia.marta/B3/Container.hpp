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

class Container::Iterator {
public:
  Iterator(size_t index);

  bool operator==(const Iterator &other) const;

  bool operator!=(const Iterator &other) const;

  unsigned int &operator*();

  unsigned int *operator->();

  Iterator &operator++();

  Iterator &operator--();

  Iterator operator++(int);

  Iterator operator--(int);

private:
  size_t index_;
  unsigned int value_;

  unsigned int getValue(size_t index) const;
};

#endif

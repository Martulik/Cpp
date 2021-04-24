#ifndef FACTORIAL_CONTAINER_HPP
#define FACTORIAL_CONTAINER_HPP

#include <iterator>

namespace shilyaev {
  class FactorialContainer {
  public:
    class Iterator: public std::iterator< std::bidirectional_iterator_tag, unsigned int > {
    public:
      using ValueType = unsigned int;

      Iterator(ValueType value, ValueType lastMultiplier);
      const ValueType &operator*() const;
      Iterator &operator++();
      Iterator operator++(int);
      Iterator &operator--();
      Iterator operator--(int);
      friend bool operator==(const Iterator &a, const Iterator &b);
      friend bool operator!=(const Iterator &a, const Iterator &b);
    private:
      ValueType value_;
      ValueType lastMultiplier_;
    };

    Iterator begin() const;
    Iterator end() const;
  };
}

#endif

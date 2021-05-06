#ifndef FACTORIAL_CONTAINER_HPP
#define FACTORIAL_CONTAINER_HPP

#include <iterator>

namespace shilyaev {
  class FactorialContainer {
  public:
    class Iterator: public std::iterator< std::bidirectional_iterator_tag, unsigned int > {
    public:
      using ValueType = unsigned int;
      Iterator() = default;
      Iterator(ValueType value, ValueType lastMultiplier);
      const ValueType &operator*() const;
      Iterator &operator++();
      Iterator operator++(int);
      Iterator &operator--();
      Iterator operator--(int);
    private:
      ValueType value_;
      ValueType lastMultiplier_;
    };

    Iterator begin() const;
    Iterator end() const;
  };

  bool operator==(const FactorialContainer::Iterator &a, const FactorialContainer::Iterator &b);
  bool operator!=(const FactorialContainer::Iterator &a, const FactorialContainer::Iterator &b);
}

#endif

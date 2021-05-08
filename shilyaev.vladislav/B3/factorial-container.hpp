#ifndef FACTORIAL_CONTAINER_HPP
#define FACTORIAL_CONTAINER_HPP

#include <iterator>

namespace shilyaev {
  class FactorialContainer {
  public:
    class Iterator: public std::iterator< std::bidirectional_iterator_tag, unsigned int > {
    public:
      using ValueType = unsigned int;
      Iterator();
      const ValueType &operator*() const;
      const ValueType *operator->() const;
      Iterator &operator++();
      Iterator operator++(int);
      Iterator &operator--();
      Iterator operator--(int);
    private:
      friend class FactorialContainer;
      ValueType value_;
      ValueType lastMultiplier_;
      Iterator(ValueType value, ValueType lastMultiplier);
    };

    Iterator begin() const;
    Iterator end() const;
  };

  bool operator==(const FactorialContainer::Iterator &a, const FactorialContainer::Iterator &b);
  bool operator!=(const FactorialContainer::Iterator &a, const FactorialContainer::Iterator &b);
}

#endif

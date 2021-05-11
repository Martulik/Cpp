#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <iterator>

namespace diurdeva {
  class Container
  {
  public:
    using ValueType = unsigned int;
    Container() = default;
    class IteratorFact : public std::iterator< std::bidirectional_iterator_tag, ValueType >
    {
    public:
      IteratorFact();

      const ValueType* operator->() const;
      const ValueType& operator*() const;
      IteratorFact& operator++();
      IteratorFact operator++(int);
      IteratorFact& operator--();
      IteratorFact operator--(int);

      bool operator==(const IteratorFact& rhs) const;
      bool operator!=(const IteratorFact& rhs) const;
    private:
      friend class Container;
      ValueType value_;
      ValueType pos_;
      IteratorFact(ValueType value, ValueType pos);
    };

    IteratorFact begin() const;
    IteratorFact end() const;
  };
}

#endif

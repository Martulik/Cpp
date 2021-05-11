#ifndef FACTORIAL_CONTAINER_HPP
#define FACTORIAL_CONTAINER_HPP

#include <iterator>

namespace pochernin
{
  class FactorialContainer
  {
    public:
    using ValueType = unsigned int;

    class FactorialIterator: public std::iterator< std::bidirectional_iterator_tag, ValueType >
    {
    public:
      bool operator ==(const FactorialIterator& rhs) const;
      bool operator !=(const FactorialIterator& rhs) const;

      ValueType& operator *() const;
      ValueType* operator ->() const;

      FactorialIterator& operator ++();
      FactorialIterator operator ++(int);
      FactorialIterator* operator --();
      FactorialIterator operator --(int);


    private:
      friend class FactorialContainer;
      ValueType num_;
      ValueType factorial_;

      FactorialIterator() = delete;
      FactorialIterator(ValueType num, ValueType factorial);
    };

    FactorialContainer() = default;

    FactorialIterator begin() const;
    FactorialIterator end() const;
  };
}

#endif

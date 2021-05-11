#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iterator>

namespace pozdnyakov
{
  class FactorialIterator: public std::iterator< std::bidirectional_iterator_tag, size_t >
  {
  public:
    FactorialIterator& operator++();
    FactorialIterator operator++(int);
    FactorialIterator& operator--();
    FactorialIterator operator--(int);
    size_t& operator*();
    size_t* operator->();
    bool operator==(const FactorialIterator& it) const;
    bool operator!=(const FactorialIterator& it) const;
  private:
    friend class FactorialContainer;
    static const size_t MAX_NUM = 10;
    size_t n_;
    size_t value_;
    FactorialIterator() = default;
    FactorialIterator(size_t n, size_t value);
  };
  size_t getFactorial(size_t n);
}

#endif

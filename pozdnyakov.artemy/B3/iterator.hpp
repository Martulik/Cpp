#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iterator>

namespace pozdnyakov
{
  class FactorialIterator: public std::iterator< std::bidirectional_iterator_tag, unsigned long >
  {
  public:
    FactorialIterator& operator++();
    FactorialIterator operator++(int);
    FactorialIterator& operator--();
    FactorialIterator operator--(int);
    unsigned long& operator*();
    unsigned long* operator->();
    bool operator==(const FactorialIterator& it) const;
    bool operator!=(const FactorialIterator& it) const;
  private:
    friend class FactorialContainer;
    static const unsigned MAX_NUM = 10;
    unsigned n_;
    unsigned long value_;
    FactorialIterator() = default;
    FactorialIterator(unsigned n, unsigned long value);
  };
  unsigned long getFactorial(unsigned n);
}

#endif

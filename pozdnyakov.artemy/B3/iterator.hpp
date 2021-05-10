#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iterator>

namespace pozdnyakov
{
  class FactorialIterator: public std::iterator< std::bidirectional_iterator_tag, size_t >
  {
  public:
    FactorialIterator& operator++();
    FactorialIterator& operator--();
    size_t& operator*();
    size_t* operator->();
    bool operator==(const FactorialIterator& it) const;
    bool operator!=(const FactorialIterator& it) const;
  private:
    friend class FactorialContainer;
    size_t n_;
    size_t value_;
    Iterator();
    Iterator(size_t num, size_t value);
  };
}

#endif

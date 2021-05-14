#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iterator>

namespace pozdnyakov
{
  class FactorialIterator: public std::iterator< std::bidirectional_iterator_tag, unsigned long >
  {
  public:
    using value_type = unsigned long;
    using number_type = unsigned;
    FactorialIterator();
    FactorialIterator& operator++();
    FactorialIterator operator++(int);
    FactorialIterator& operator--();
    FactorialIterator operator--(int);
    value_type& operator*();
    value_type* operator->();
    bool operator==(const FactorialIterator& it) const;
    bool operator!=(const FactorialIterator& it) const;
  private:
    friend class FactorialContainer;
    static constexpr number_type MAX_NUM = 10;
    number_type n_;
    value_type value_;
    FactorialIterator();
    FactorialIterator(number_type n, value_type value);
  };
}

#endif

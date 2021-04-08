#ifndef FACTORIALS_HPP
#define FACTORIALS_HPP

#include <iterator>

namespace doroshin
{
  class Factorials
  {
  public:
    using value_t = unsigned long long;

    class iterator;

    Factorials(value_t begin, value_t end);

    iterator begin();
    iterator end();
  private:
    value_t begin_;
    value_t end_;
  };

  class Factorials::iterator:
      public std::iterator< std::bidirectional_iterator_tag, value_t >
  {
  public:
    using reference = value_type;

    iterator(value_type);

    friend bool operator==(const iterator&, const iterator&);

    reference operator*() const;

    iterator& operator++();
    iterator operator++(int);

    iterator& operator--();
    iterator operator--(int);
  private:
    value_type arg_;
    value_type value_;
  };

  bool operator==(const Factorials::iterator&, const Factorials::iterator&);
  bool operator!=(const Factorials::iterator&, const Factorials::iterator&);
}

#endif //FACTORIALS_HPP

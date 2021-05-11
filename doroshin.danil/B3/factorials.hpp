#ifndef FACTORIALS_HPP
#define FACTORIALS_HPP

#include <cassert>
#include <iterator>

namespace doroshin
{
  class Factorials
  {
  public:
    using value_t = unsigned long long;

    class iterator;

    constexpr Factorials(value_t begin, value_t end);

    iterator cbegin() const;
    iterator cend() const;
  private:
    value_t begin_;
    value_t end_;
  };

  class Factorials::iterator: public std::iterator< std::bidirectional_iterator_tag, value_t >
  {
  public:
    using reference = value_type;

    constexpr iterator(value_type);

    reference operator*() const;

    iterator& operator++();
    iterator operator++(int);

    iterator& operator--();
    iterator operator--(int);
  private:
    value_type arg_;
    value_type value_;
  };

  constexpr Factorials::value_t factorial(unsigned int n)
  {
    Factorials::value_t res = 1;
    for(; n > 1; --n) {
      res *= n;
    }
    return res;
  }

  bool operator==(const Factorials::iterator&, const Factorials::iterator&);
  bool operator!=(const Factorials::iterator&, const Factorials::iterator&);
}

constexpr doroshin::Factorials::Factorials(value_t begin, value_t end):
  begin_(begin),
  end_(end)
{
  assert(begin <= end);
}

constexpr doroshin::Factorials::iterator::iterator(value_type n):
  arg_(n),
  value_(factorial(n))
{}

#endif //FACTORIALS_HPP

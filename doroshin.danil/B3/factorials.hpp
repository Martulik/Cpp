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

    constexpr Factorials(value_t begin, value_t end) noexcept;

    iterator begin() const noexcept;
    iterator end() const noexcept;
  private:
    value_t begin_;
    value_t end_;
  };

  class Factorials::iterator: public std::iterator< std::bidirectional_iterator_tag, value_t >
  {
  public:
    using reference = value_type;

    constexpr iterator(value_type) noexcept;

    reference operator*() const noexcept;
    value_type* operator->() noexcept;

    iterator& operator++() noexcept;
    iterator operator++(int) noexcept;

    iterator& operator--() noexcept;
    iterator operator--(int) noexcept;
  private:
    value_type arg_;
    value_type value_;
  };

  constexpr Factorials::value_t factorial(unsigned int n) noexcept
  {
    Factorials::value_t res = 1;
    for(; n > 1; --n) {
      res *= n;
    }
    return res;
  }

  bool operator==(const Factorials::iterator&, const Factorials::iterator&) noexcept;
  bool operator!=(const Factorials::iterator&, const Factorials::iterator&) noexcept;
}

constexpr doroshin::Factorials::Factorials(value_t begin, value_t end) noexcept:
  begin_(begin),
  end_(end)
{
  assert(begin <= end);
}

constexpr doroshin::Factorials::iterator::iterator(value_type n) noexcept:
  arg_(n),
  value_(factorial(n))
{}

#endif //FACTORIALS_HPP

#ifndef UDOUBLE_HPP
#define UDOUBLE_HPP

#include <cmath>
#include <stdexcept>

namespace doroshin
{
  // constexpr functions are automatically inline
  // thus they cannot be shared between translation units
  // and have to be declared in the header
  class udouble_t
  {
    double value_;
  public:
    constexpr explicit udouble_t() noexcept:
      value_()
    {}

    constexpr explicit udouble_t(const double value) noexcept:
      value_(std::fabs(value))
    {}

    constexpr operator double() const noexcept
    {
      return value_;
    }
  };

  constexpr udouble_t make_abs(const double value)
  {
    if(value < 0)
      throw std::invalid_argument("Unsigned double value must be non-negative");
    return udouble_t(value);
  }

  inline namespace literals
  {
    constexpr udouble_t operator""_ud(const unsigned long long value) noexcept
    {
      return udouble_t(static_cast< double >(value));
    }

    constexpr udouble_t operator""_ud(const long double value) noexcept
    {
      return udouble_t(static_cast< double >(value));
    }
  }
}

#endif //UDOUBLE_HPP

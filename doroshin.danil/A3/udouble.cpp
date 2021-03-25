#include "udouble.hpp"
#include <stdexcept>
#include <cmath>

namespace dan = doroshin;

dan::udouble_t::udouble_t() noexcept:
  value_()
{}

dan::udouble_t::udouble_t(const double value) noexcept:
  value_(std::fabs(value))
{}

dan::udouble_t::operator double() const noexcept
{
  return value_;
}

dan::udouble_t dan::literals::operator""_ud(const unsigned long long value) noexcept
{
  return udouble_t(static_cast< double >(value));
}

dan::udouble_t dan::literals::operator""_ud(const long double value) noexcept
{
  return udouble_t(static_cast< double >(value));
}

dan::udouble_t dan::make_abs(const double value)
{
  if(value < 0)
    throw std::invalid_argument("udouble_t value must be non-negative");
  return udouble_t(value);
}

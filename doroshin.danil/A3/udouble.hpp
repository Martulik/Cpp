#ifndef UDOUBLE_HPP
#define UDOUBLE_HPP

namespace doroshin
{
  class udouble_t
  {
    double value_;
  public:
    explicit udouble_t() noexcept;
    explicit udouble_t(double) noexcept;

    operator double() const noexcept;
  };

  udouble_t make_abs(double);

  inline namespace literals
  {
    udouble_t operator""_ud(unsigned long long) noexcept;
    udouble_t operator""_ud(long double) noexcept;
  }
}

#endif //UDOUBLE_HPP

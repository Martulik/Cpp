#ifndef TOOLS_HPP
#define TOOLS_HPP

namespace savchuk
{
  constexpr size_t calcucateFactorial(size_t n)
  {
    size_t res = 1;
    for (size_t i = n; i > 0; --i)
    {
      res *= i;
    }
    return res;
  }
}

#endif

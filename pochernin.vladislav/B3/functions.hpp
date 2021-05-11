#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

namespace pochernin
{
  using ValueType = unsigned int;

  const ValueType maxNumber = 11;
  const ValueType minNumber = 1;

  int getTaskNumber(const char* string);
  ValueType getFactorial(ValueType number);
}

#endif

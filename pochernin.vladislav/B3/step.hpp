#ifndef STEP_HPP
#define STEP_HPP

#include <iostream>

namespace pochernin
{
  struct Step
  {
    bool isFirst = false;
    bool isLast = false;
    bool isSpecific = false;
    int steps = 0;
    bool isCorrect() const;
  };
  std::istream& operator>>(std::istream& in, Step& step);
}

#endif

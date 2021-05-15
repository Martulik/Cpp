#include "step.hpp"

#include <string>
#include <stdexcept>

bool pochernin::Step::isCorrect() const
{
  return ((isFirst != false) || (isLast != false) || (isSpecific != false));
}

std::istream& pochernin::operator>>(std::istream& in, Step& step)
{
  std::string stepString;
  in >> std::ws >> stepString;
  if (stepString == "first")
  {
    step.isFirst = true;
    step.isLast = false;
    step.isSpecific = false;
    step.steps = 0;
  }
  else if (stepString == "last")
  {
    step.isFirst = false;
    step.isLast = true;
    step.isSpecific = false;
    step.steps = 0;
  }
  else
  {
    try
    {
      step.isFirst = false;
      step.isLast = false;
      step.isSpecific = true;
      step.steps = std::stoi(stepString);
    }
    catch (std::exception& error)
    {
      step.isFirst = false;
      step.isLast = false;
      step.isSpecific = false;
      step.steps = 0;
    }
  }

  return in;
}
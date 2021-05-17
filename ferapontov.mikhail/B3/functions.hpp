#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <string>

namespace ferapontov
{
  constexpr unsigned long getFarctorial(unsigned int num)
  {
    if (num == 1)
    {
      return 1;
    }
    return num * getFarctorial(num -1);
  }

  std::string read(std::istream& in);
  std::string checkName(std::string& name);
  std::string checkMarkName(std::string& markName);
  void checkInsertMode(std::string& mode);
  int checkNumber(std::string& num);
  bool checkSteps(std::string& steps);
}

#endif

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
    return num * getFarctorial(num - 1);
  }

  std::string read(std::istream& in);
  std::string readName(std::istream& in);
  std::string checkMarkName(const std::string& markName);
  void checkInsertMode(const std::string& mode);
  void checkNumber(const std::string& num);
  bool checkStepsKeyWords(const std::string& steps);
  bool checkStepsNum(const std::string& steps);
}

#endif

#ifndef TEST_FUNCTIONS_HPP
#define TEST_FUNCTIONS_HPP
#include <memory>
#include "test-variables.hpp"

namespace lebedeva
{
  std::unique_ptr< Interface > makeEmptyInterface();
  void addRec(std::unique_ptr< Interface >& src);
  bool storeRec(std::unique_ptr< Interface >& src);
  bool insertRec(std::unique_ptr< Interface >& src);
  bool moveMark(std::unique_ptr< Interface >& src, int n);
  bool deleteMark(std::unique_ptr< Interface >& src);
}
#endif

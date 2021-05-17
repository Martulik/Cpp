#ifndef TEST_VALUES_HPP
#define TEST_VALUES_HPP

#include <cstddef>
#include <array>

namespace savchuk
{
  constexpr size_t size = 3;

  constexpr std::array< const char*, size > correctValues = { "1, 2, fgh", "5, -3, xdf", "-5, -5, vxr" };
  constexpr std::array< const char*, size > incorrectValues = { "-5f, 3, asd", "1, 2. bni", "3 4, btk" };
  constexpr std::array< const char*, size > invalidKeys = { "-5, 6, wrt", "6, 0, sdf", "7, -9, dfg" };
}

#endif

#ifndef TEST_VALUES_HPP
#define TEST_VALUES_HPP

#include <cstddef>
#include <array>

namespace savchuk
{
  constexpr size_t size = 3;

  constexpr std::array< const char*, size > correctValues = { "1, 2, fgh\n", "5, -3, xdf\n", "-5, -5, vxr\n" };
  constexpr std::array< const char*, size > incorrectValues = { "-5f, 3, asd\n", "1, 2. bni\n", "3 4, btk\n" };
  constexpr std::array< const char*, size > invalidKeys = { "-5, 6, wrt\n", "6, 0, sdf\n", "7, -9, dfg\n" };
}

#endif

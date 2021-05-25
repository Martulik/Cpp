#include <array>

namespace savchuk
{
  constexpr std::array< const char*, 2 > correctInput = { "3 (3; 5) ( 5;6) (2;3)\n",
                                                          "4 (6 ;7) (-3;1) (-8;-9) ( 0 ; 0 )\n" };

  constexpr std::array< const char*, 7 > incorrectInput = { "3 (f; 9) (9; 0) (-3; 8)\n",
                                                            "3 (1; 4) 8; 0) (3;4)\n",
                                                            "3 (7; 9) (1 ;8) (3, 7)\n",
                                                            "4 (8; 8) (1; 7)\n",
                                                            "3 \n (1;1) (2;2) (3;3)\n",
                                                            "3 (\n4; 3) (1;5) (9;-3)\n",
                                                            "3 (5; \n6) (2;1) (5;3)\n"};
}

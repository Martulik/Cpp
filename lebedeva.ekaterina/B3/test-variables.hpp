#ifndef TEST_VARIABLES_HPP
#define TEST_VARIABLES_HPP
#include "phonebook_interface.hpp"

namespace lebedeva
{
  const record_t rec1 = { "MCB\"nZdwzUyQ,sV", "874561451455" };
  const record_t rec2 = { "miSfKHyCyHJ", "863813529565" };
  const record_t rec3 = { "nrrjWCppZOAtYG", "653702220203" };

  const int zeroStep = 0;
  const int posStep = 1;
  const int negStep = -1;
  const int commandFirst = 101;
  const int commandLast = 110;

  const std::string cur = "current";
  const std::string markname1 = "mark1";
  const std::string newmarkname1 = "newmark1";
  const std::string markname2 = "mark2";
  const std::string markname3 = "mark3";

  const Interface::Steps first = Interface::Steps::first;
  const Interface::Steps last = Interface::Steps::last;
  const Interface::Where bef = Interface::Where::before;
  const Interface::Where aft = Interface::Where::after;
}
#endif

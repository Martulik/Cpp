#ifndef TEST_FUNCTIONS_HPP
#define TEST_FUNCTIONS_HPP
#include <memory>
#include "phonebook_interface.hpp"

namespace lebedeva
{
  std::unique_ptr< Interface > makeEmptyInterface();
  bool addRec(std::unique_ptr< Interface >& src, record_t& rec, std::string& markName);
  bool storeRec(std::unique_ptr< Interface >& src, std::string& markName, std::string& newMarkName);
  bool insertRec(std::unique_ptr< Interface >& src, );

  record_t rec1 = { "MCB\"nZdwzUyQ,sV", "874561451455" };
  record_t rec2 = { "miSfKHyCyHJ", "863813529565" };
  record_t rec3 = { "nrrjWCppZOAtYG", "653702220203" };

  int zeroStep = 0;
  int posStep = 1;
  int negStep = -1;

  std::string markname1 = "mark1";
  std::string markname2 = "mark2";
  std::string markname3 = "mark3";

  Interface::Steps s1 = Interface::Steps::first;
  Interface::Steps s2 = Interface::Steps::last;
}
#endif

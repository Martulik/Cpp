#include "tasks.h"

#include <iostream>

#include "UsersInterface.h"
#include "commands.h"

int lysenko::task1()
{
  lysenko::UsersInterface myInterface;
  std::string myCommand;

  while (std::getline(std::cin, myCommand))
  {
    readCommand(myCommand, myInterface);
  }

  if (!std::cin.eof())
  {
    std::cerr << "Error with reading command \n";
    return 2;
  }

  return 0;
}

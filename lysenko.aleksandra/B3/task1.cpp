#include <iostream>

#include "UsersInterface.h"
#include "commands.h"

int task1(std::istream& input)
{
  lysenko::UsersInterface myInterface;
  std::string myCommand;

  while (std::getline(input, myCommand))
  {
    readCommand(myCommand, myInterface);
  }

  if (!input.eof())
  {
    std::cerr << "Error with reading command \n";
    return 2;
  }

  return 0;
}

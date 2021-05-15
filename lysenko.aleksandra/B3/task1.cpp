#include "tasks.h"

#include <iostream>
#include <string>

#include "PhoneBook.h"
#include "commands.h"

int lysenko::task1(std::istream& in, std::ostream& out)
{
  lysenko::PhoneBook myBook;
  std::string myCommand;

  while (std::getline(in, myCommand))
  {
    readCommand(myCommand, out, myBook);
  }

  if (!in.eof())
  {
    std::cerr << "Error with reading command \n";
    return 2;
  }

  return 0;
}

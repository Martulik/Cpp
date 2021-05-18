#include "tasks.h"

#include <iostream>
#include <string>

#include "PhoneBook.h"
#include "commands.h"
#include "Exceptions.h"

int lysenko::task1(std::istream& in, std::ostream& out)
{
  PhoneBook myBook;
  std::string myCommand;

  try
  {
    while (std::getline(in, myCommand))
    {
      readCommand(myCommand, out, myBook);
    }
    if (!in.eof())
    {
      std::cerr << "Error with reading command \n";
      return 2;
    }
  }
  catch (InvalidCommand& err)
  {
    std::cout << err.what();
  }
  catch (InvalidbookMark& err)
  {
    std::cout << err.what();
  }
  catch (InvalidStep& err)
  {
    std::cout << err.what();
  }

  return 0;
}

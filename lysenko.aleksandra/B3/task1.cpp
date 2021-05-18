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

  while (std::getline(in, myCommand))
  {
    try
    {
      readCommand(myCommand, out, myBook);
    }
    catch (InvalidCommand& err)
    {
      std::cout << err.what() << "\n";
    }
    catch (InvalidbookMark& err)
    {
      std::cout << err.what() << "\n";
    }
    catch (InvalidStep& err)
    {
      std::cout << err.what() << "\n";
    }
  }
  if (!in.eof())
  {
    std::cerr << "Error with reading command \n";
    return 2;
  }

  return 0;
}

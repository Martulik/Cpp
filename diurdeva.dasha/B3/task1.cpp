#include "task1.hpp"
#include <sstream>
#include "comands.hpp"

void diurdeva::task1()
{
  PhonebookManager book;
  std::string string;

  while (std::getline(std::cin, string))
  {
    if (in.fail()) {
      throw std::runtime_error("Read fail");
    }
    std::stringstream input(string);
    std::string command;
    input >> command;
    if (command == "add")
    {
      add(phoneBook, input);
    }
    else if (command == "store")
    {
      store(phoneBook, input);
    }
    else if (command == "insert")
    {
      insert(phoneBook, input);
    }
    else if (command == "delete")
    {
      deleteRecord(phoneBook, input);
    }
    else if (command == "show")
    {
      show(phoneBook, input);
    }
    else if (command == "move")
    {
      move(phoneBook, input);
    }
    else
    {
      invalidCommand(std::cout);
    }
  }

}

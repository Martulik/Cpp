#include "task1.hpp"
#include <sstream>
#include <iostream>
#include "comands.hpp"

void diurdeva::task1()
{
  PhonebookManager book;
  std::string string;

  while (std::getline(std::cin, string))
  {
    if (std::cin.fail()) {
      throw std::runtime_error("Read fail");
    }
    std::stringstream input(string);
    std::string command;
    input >> command;
    if (command == "add")
    {
      add(book, input);
    }
    else if (command == "store")
    {
      store(book, input);
    }
    else if (command == "insert")
    {
      insert(book, input);
    }
    else if (command == "delete")
    {
      deleteRecord(book, input);
    }
    else if (command == "show")
    {
      show(book, input, std::cout);
    }
    else if (command == "move")
    {
      move(book, input);
    }
    else
    {
      invalidCommand(std::cout);
    }
  }

}

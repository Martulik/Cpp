#include "task1.hpp"
#include <sstream>
#include <iostream>
#include "comands.hpp"

void diurdeva::parseCommand(PhonebookManager& phoneBook, const std::string& command, std::stringstream& sin)
{
  if (command == "add")
  {
    add(phoneBook, sin);
  }
  else if (command == "store")
  {
    store(phoneBook, sin);
  }
  else if (command == "insert")
  {
    insert(phoneBook, sin);
  }
  else if (command == "delete")
  {
    deleteRecord(phoneBook, sin);
  }
  else if (command == "show")
  {
    show(phoneBook, sin);
  }
  else if (command == "move")
  {
    move(phoneBook, sin);
  }
  else
  {
    std::cout << "<INVALID COMMAND>\n";
  }
}

void diurdeva::task1()
{
  PhonebookManager book;
  std::string string;

  while (std::getline(std::cin, string))
  {
    std::stringstream input(string);
    std::string command;
    input >> command;
    diurdeva::parseCommand(book, command, input);
  }

  if (!std::cin.eof() && !std::cin.good())
  {
    throw std::runtime_error("Error! Failed reading data!\n");
  }
}

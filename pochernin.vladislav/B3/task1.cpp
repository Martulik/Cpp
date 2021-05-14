#include "tasks.hpp"

#include <iostream>
#include <string>
#include <sstream>

#include "phone-book.hpp"
#include "phone-book-interface.hpp"
#include "note.hpp"
#include "functions.hpp"

void pochernin::task1(std::istream& in, std::ostream& out)
{
  pochernin::PhoneBook book;
  pochernin::PhoneBookInterface interface(book);
  std::string string;
  while(std::getline(in, string))
  {
    std::stringstream input(string);
    std::string command;
    input >> command;
    if (command == "add")
    {
      Note note;
      input >> note;
      if ((note.number == "") || (note.name == ""))
      {
        pochernin::invalidCommand(out);
      }
    }
    else
    {
      pochernin::invalidCommand(out);
    }
  }
}
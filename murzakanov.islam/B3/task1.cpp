#include "tasks.hpp"

#include <iostream>
#include <algorithm>
#include <sstream>

#include "phone-book.hpp"
#include "phonebookinteface.hpp"
#include "tools.hpp"

void murzakanov::task1(std::istream& in, std::ostream& out)
{
  namespace mur = murzakanov;
  mur::PhoneBook book;
  mur::BookInterface bookInterface(book);
  std::string line;
  while (std::getline(in, line) && !line.empty())
  {
    std::istringstream in(line);
    std::string command;
    in >> command;
    if (command == "add")
    {
      std::string number;
      in >> number;
      if (!std::all_of(number.begin(), number.end(), ::isdigit))
      {
        murzakanov::invalidCommand(out);
        continue;
      }
      std::string name;
      mur::readName(in, name);
      if (in)
      {
        bookInterface.add({number, name});
      }
      else
      {
        murzakanov::invalidCommand(out);
      }
    }
    else if (command == "store")
    {
      std::string bookmark;
      std::string newBookmark;
      in >> bookmark >> newBookmark;
      bookInterface.store(bookmark, newBookmark, out);
    }
    else if (command == "insert")
    {
      std::string place;
      std::string mark;
      std::string number;
      std::string name;
      in >> place >> mark >> number;
      if (!std::all_of(number.begin(), number.end(), ::isdigit))
      {
        murzakanov::invalidCommand(out);
        continue;
      }
      if (place != "before" && place != "after")
      {
        murzakanov::invalidCommand(out);
        continue;
      }
      mur::readName(in, name);
      if (in)
      {
        if (place == "before")
        {
          bookInterface.insertBefore(mark, {number, name}, out);
        }
        else if (place == "after")
        {
          bookInterface.insertAfter(mark, {number, name}, out);
        }
      }
      else
      {
        murzakanov::invalidCommand(out);
      }
    }
    else if (command == "delete")
    {
      std::string mark;
      in >> mark;
      bookInterface.deleteNote(mark, out);
    }
    else if (command == "show")
    {
      std::string mark;
      in >> mark;
      bookInterface.show(mark, out);
    }
    else if (command == "move")
    {
      std::string mark;
      std::string steps;
      in >> mark >> steps;
      try
      {
        int stepsNum = std::stoi(steps);
        bookInterface.move(mark, stepsNum, out);
      }
      catch(const std::invalid_argument&)
      {
        if (steps == "first")
        {
          bookInterface.move(mark, steps, out);
        }
        else if (steps == "last")
        {
          bookInterface.move(mark, steps, out);
        }
        else
        {
          murzakanov::invalidStep(out);
        }
      }
    }
    else
    {
      murzakanov::invalidCommand(out);
    }
  }
}

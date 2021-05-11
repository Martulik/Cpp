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
      if (bookInterface.contains(bookmark))
      {
        bookInterface.store(bookmark, newBookmark);
      }
      else
      {
        murzakanov::invalidBookmark(out);
      }
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
      if (in && bookInterface.contains(mark))
      {
        if (place == "before")
        {
          bookInterface.insertBefore(mark, {number, name});
        }
        else if (place == "after")
        {
          bookInterface.insertAfter(mark, {number, name});
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
      if (bookInterface.contains(mark))
      {
        bookInterface.deleteNote(mark);
      }
      else
      {
        murzakanov::invalidBookmark(out);
      }
    }
    else if (command == "show")
    {
      std::string mark;
      in >> mark;
      if (bookInterface.contains(mark))
      {
        if (!bookInterface.empty())
        {
          out << bookInterface.show(mark);
        }
        else
        {
          murzakanov::empty(out);
        }
      }
      else
      {
        murzakanov::invalidBookmark(out);
      }
    }
    else if (command == "move")
    {
      std::string mark;
      std::string steps;
      in >> mark >> steps;
      if (bookInterface.contains(mark))
      {
        try
        {
          int stepsNum = std::stoi(steps);
          bookInterface.move(mark, stepsNum);
        }
        catch(const std::invalid_argument&)
        {
          if (steps == "first")
          {
            bookInterface.move(mark, steps);
          }
          else if (steps == "last")
          {
            bookInterface.move(mark, steps);
          }
          else
          {
            murzakanov::invalidStep(out);
          }
        }
      }
      else
      {
        mur::invalidBookmark(out);
      }

    }
    else
    {
      murzakanov::invalidCommand(out);
    }
  }
}

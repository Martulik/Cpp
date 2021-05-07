#include "tasks.hpp"

#include <iostream>
#include <sstream>
#include <string>

#include "phone-book.hpp"
#include "phonebookinteface.hpp"
#include "tools.hpp"

void murzakanov::task1()
{
  namespace mur = murzakanov;
  mur::PhoneBook book;
  mur::BookInterface bookInterface(book);
  std::string line;
  while (std::getline(std::cin, line) && !line.empty())
  {
    std::istringstream in(line);
    std::string command;
    in >> command;
    if (command == "add")
    {
      std::string number;
      in >> number;
      if (!mur::checkIsNum(number))
      {
        std::cout << "<INVALID COMMAND>\n";
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
        std::cout << "<INVALID COMMAND>\n";
      }
    }
    else if (command == "store")
    {
      std::string bookmark;
      std::string newBookmark;
      in >> bookmark >> newBookmark;
      bookInterface.store(bookmark, newBookmark, std::cout);
    }
    else if (command == "insert")
    {
      std::string place;
      std::string mark;
      std::string number;
      std::string name;
      in >> place >> mark >> number;
      if (!mur::checkIsNum(number))
      {
        std::cout << "<INVALID COMMAND>\n";
        continue;
      }
      if (place != "before" && place != "after")
      {
        std::cout << "<INVALID COMMAND>\n";
        continue;
      }
      mur::readName(in, name);
      if (place == "before")
      {
        bookInterface.insertBefore(mark, {number, name}, std::cout);
      }
      else if (place == "after")
      {
        bookInterface.insertAfter(mark, {number, name}, std::cout);
      }
    }
    else if (command == "delete")
    {
      std::string mark;
      in >> mark;
      bookInterface.deleteNote(mark, std::cout);
    }
    else if (command == "show")
    {
      std::string mark;
      in >> mark;
      bookInterface.show(mark, std::cout);
    }
    else if (command == "move")
    {
      std::string mark;
      std::string steps;
      in >> mark >> steps;
      try
      {
        int stepsNum = std::stoi(steps);
        bookInterface.move(mark, stepsNum, std::cout);
      }
      catch(const std::invalid_argument&)
      {
        if (steps == "first")
        {
          bookInterface.move(mark, steps, std::cout);
        }
        else if (steps == "last")
        {
          bookInterface.move(mark, steps, std::cout);
        }
        else
        {
          std::cout << "<INVALID STEP>\n";
        }
      }
    }
    else
    {
      std::cout << "<INVALID COMMAND>\n";
    }
  }
}

#include "tasks.hpp"

#include <string>
#include <iostream>
#include <sstream>

#include "tools.hpp"
#include "error-messages.hpp"
#include "user-interface.hpp"

namespace lab = savchuk;

void lab::task1(std::istream& is, std::ostream& os)
{
  UserInterface userInterface;
  std::string str;
  while (std::getline(is, str) && !str.empty())
  {
    try
    {
      std::istringstream ss(str);
      std::string command;
      ss >> command;
      if (command == "add")
      {
        std::string number = readNumber(ss);
        std::string name = readName(ss);
        userInterface.add({ number, name });
      }
      else if (command == "store")
      {
        std::string markName = readMarkName(ss);
        std::string newMarkName = readMarkName(ss);
        userInterface.store(markName, newMarkName);
      }
      else if (command == "insert")
      {
        std::string position = readPosition(ss);
        std::string markName = readMarkName(ss);
        std::string number = readNumber(ss);
        std::string name = readName(ss);
        if (position == "before")
        {
          userInterface.insertBefore(markName, { number, name });
        }
        else
        {
          userInterface.insertAfter(markName, { number, name });
        }
      }
      else if (command == "delete")
      {
        std::string markName = readMarkName(ss);
        userInterface.remove(markName);
      }
      else if (command == "show")
      {
        std::string markName = readMarkName(ss);
        os << userInterface.getContact(markName);
      }
      else if (command == "move")
      {
        std::string markName = readMarkName(ss);
        std::string steps = readSteps(ss);
        userInterface.move(markName, steps);
      }
      else
      {
        throw std::invalid_argument(INVALID_COMMAND);
      }
    }
    catch (const std::invalid_argument& err)
    {
      os << err.what() << '\n';
    }
  }
  if (is.fail() && !is.eof())
  {
    throw std::runtime_error(INPUT_ERROR);
  }
}

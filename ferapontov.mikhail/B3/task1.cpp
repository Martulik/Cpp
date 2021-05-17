#include "tasks.hpp"
#include "UserInterface.hpp"
#include <sstream>
#include "functions.hpp"

namespace fer = ferapontov;

void fer::task1(std::istream& in, std::ostream& out)
{
  fer::Interface UI;
  std::string command;

  while(std::getline(in, command) && !command.empty())
  {
    try
    {
      std::istringstream stream(command);
      std::string action;
      stream >> action;
      if (action == "add")
      {
        std::string number = read(stream);
        std::string name = read(stream);
        checkName(name);
        int num = checkNumber(number);
        UI.add(name, num);
      }
      else if (action == "store")
      {
        std::string oldMarkName= read(stream);
        std::string newMarkName = read(stream);
        checkMarkName(oldMarkName);
        checkMarkName(newMarkName);
        UI.store(oldMarkName, newMarkName);
      }
      else if (action == "insert")
      {
        std::string mode = read(stream);
        checkInsertMode(mode);
        std::string markName = read(stream);
        checkMarkName(markName);
        std::string number = read(stream);;
        int num = checkNumber(number);
        std::string name = read(stream);
        name = checkName(name);
        UI.insertNote(mode, markName, name, num);
      }
      else if (action == "delete")
      {
        std::string markName = read(stream);
        checkMarkName(markName);
        UI.deleteNote(markName);
      }
      else if (action == "show")
      {
        std::string markName = read(stream);
        markName = checkMarkName(markName);
        out << UI.show(markName);
      }
      else if (action == "move")
      {
        std::string markName = read(stream);
        checkMarkName(markName);
        std::string steps = read(stream);
        if (checkSteps(steps))
        {
          UI.move(markName, steps);
        }
        else
        {
          throw std::invalid_argument("<INVALID STEPS>");
        }
      }
      else
      {
        throw std::invalid_argument("<INVALID COMMAND>");
      }
    }
    catch(const std::invalid_argument& e)
    {
      out << e.what() << "\n";
    }
  }
}

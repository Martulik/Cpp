#include "tasks.hpp"
#include <sstream>
#include "UserInterface.hpp"
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
      std::string action = read(stream);
      if (action == "add")
      {
        std::string number = read(stream);
        checkNumber(number);
        std::string name = readName(stream);
        UI.add(name, number);
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
        checkNumber(number);
        std::string name = readName(stream);
        UI.insertNote(mode, markName, name, number);
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
        out << UI.show(markName) << '\n';
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
          throw std::invalid_argument("<INVALID STEP>");
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

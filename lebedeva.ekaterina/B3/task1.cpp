#include "tasks.hpp"
#include <string>
#include <sstream>
#include "phonebook_interface.hpp"

using constIter = std::map< std::string, lebedeva::PhoneBook::constIter >::const_iterator;

void lebedeva::doTask1(std::istream& in, std::ostream& out)
{
  Interface obj;
  std::string str;
  while (std::getline(in, str))
  {
    if (in.fail())
    {
      throw std::runtime_error("Input error in task 1\n");
    }
    std::stringstream input(str);
    std::string command;
    input >> command;

    if (command == "add")
    {
      record_t recToAdd;
      in >> std::ws >> recToAdd.phoneNumber;
      if (checkNumber(recToAdd.phoneNumber))
      {
        std::getline(in >> std::ws, recToAdd.name);
        if (!recToAdd.name.empty())
        {
          obj.add(recToAdd);
        }
        else
        {
          out << "<INVALID COMMAND>\n";
        }
      }
      else
      {
        out << "<INVALID COMMAND>\n";
      }
    }
    else if (command == "store")
    {
      std::string markName;
      std::string newMarkName;

      in >> std::ws >> markName;
      in >> std::ws >> newMarkName;

      constIter iter = obj.find(markName);
      if (iter != obj.end())
      {
        obj.store(markName, newMarkName);
      }
      else
      {
        out << "<INVALID COMMAND>\n";
      }
    }
    else if (command == "insert")
    {
      std::string whr;
      std::string markName;
      record_t recToIns;

      in >> std::ws >> whr;
      in >> std::ws >> markName;
      in >> std::ws >> recToIns.phoneNumber;
      std::getline(in >> std::ws, recToIns.name);

      if (!(recToIns.name.empty()) && checkNumber(recToIns.phoneNumber))
      {
        constIter iter = obj.find(markName);
        if (iter != obj.end())
        {
          if (whr == "before")
          {
            obj.insert(Interface::Where::before, markName, recToIns);
          }
          else if (whr == "after")
          {
            obj.insert(Interface::Where::after, markName, recToIns);
          }
          else
          {
            out << "<INVALID COMMAND>\n";
          }
        }
        else
        {
          out << "<INVALID COMMAND>\n";
        }
      }
      else
      {
        out << "<INVALID COMMAND>\n";
      }
    }
    else if (command == "delete")
    {
      std::string markName;
      in >> std::ws >> markName;
      constIter iter = obj.find(markName);
      if (iter != obj.end())
      {
        obj.deleteRec(markName);
      }
      else
      {
        out << "<INVALID COMMAND>\n";
      }
    }
    else if (command == "show")
    {
      // input markName
      // find it in obj
      // obj.show(markName, out);
      // out << '\n';
      // if not found
      out << "<INVALID COMMAND>\n";
    }
    else if (command == "move")
    {
      // input markName and steps
      // find markName in obj
      // check if steps is a known word or int digit
      // obj.move(markName, steps);
      // if not found
      out << "<INVALID COMMAND>\n";
    }
    else
    {
      out << "<INVALID COMMAND>\n";
    }
  }
}

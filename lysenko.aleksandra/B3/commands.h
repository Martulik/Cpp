#ifndef COMMANDS_H
#define COMMANDS_H

#include "exceptions.h"

#include <iostream>
#include <string>
#include <map>
#include "UsersInterface.h"

namespace lysenko
{
  const std::map< std::string, void (*)(std::istream&, lysenko::UsersInterface&) > commandsMap
  (
    {
        {"add", executeAdd},
        {"store", executeStore},
        {"insert", executeInsert},
        {"delete", executeDelete},
        {"show", executeShow},
        {"move", executeMove}
    }
  );

  typedef std::map< std::string, void (*)(std::istream&, lysenko::UsersInterface&) >::const_iterator iteratorInt;

  bool checkCorrectNumberAndName(std::string& name, std::string& number);
  bool checkIfThisMarkNameContains(std::string& markName, UsersInterface& myInterface);

  void readCommand(const std::string& inputCommand, lysenko::UsersInterface& myInterface);
  void executeAdd(std::istream& input, lysenko::UsersInterface& myInterface);
  void executeStore(std::istream& input, lysenko::UsersInterface& myInterface);
  void executeInsert(std::istream& input, lysenko::UsersInterface& myInterface);
  void executeDelete(std::istream& input, lysenko::UsersInterface& myInterface);
  void executeShow(std::istream& input, lysenko::UsersInterface& myInterface);
  void executeMove(std::istream& input, lysenko::UsersInterface& myInterface);
}

#endif
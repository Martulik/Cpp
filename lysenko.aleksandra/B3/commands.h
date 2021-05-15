#ifndef COMMANDS_H
#define COMMANDS_H

#include <string>
#include <map>
#include <functional>

#include "PhoneBook.h"

namespace lysenko
{
  using iteratorInt = std::map< std::string, std::function< void (std::istream&, lysenko::PhoneBook&) > >::const_iterator;

  bool isDigitsOnly(std::string& number);
  bool checkCorrectNumberAndName(std::string& name, std::string& number);
  bool checkIfThisMarkNameContains(std::string& markName, PhoneBook& myBook);

  void readCommand(const std::string& inputCommand, std::ostream& out, lysenko::PhoneBook& myBook);

  void executeAdd(std::istream& in, lysenko::PhoneBook& myBook);
  void executeStore(std::istream& in, lysenko::PhoneBook& myBook);
  void executeInsert(std::istream& in, lysenko::PhoneBook& myBook);
  void executeDelete(std::istream& in, lysenko::PhoneBook& myBook);
  void executeMove(std::istream& in, lysenko::PhoneBook& myBook);

  void executeShow(std::istream& in, std::ostream& out, lysenko::PhoneBook& myBook);

  const std::map< std::string, std::function< void (std::istream&, lysenko::PhoneBook&) > >commandsMap
  (
    {
        {"add", executeAdd},
        {"store", executeStore},
        {"insert", executeInsert},
        {"delete", executeDelete},
        {"move", executeMove}
    }
  );
}

#endif

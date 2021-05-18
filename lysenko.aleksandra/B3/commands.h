#ifndef COMMANDS_H
#define COMMANDS_H

#include <string>
#include <map>
#include <functional>

#include "PhoneBook.h"

namespace lysenko
{
  bool isDigitsOnly(const std::string& number);
  bool checkCorrectNumberAndName(const std::string& name, const std::string& number);

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
        { "add", executeAdd },
        { "store", executeStore },
        { "insert", executeInsert },
        { "delete", executeDelete },
        { "move", executeMove }
    }
  );
}

#endif

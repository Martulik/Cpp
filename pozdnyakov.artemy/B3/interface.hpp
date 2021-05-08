#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <utility>
#include <list>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <memory>
#include "phonebook.hpp"

namespace pozdnyakov
{
  class Interface
  {
  public:
    using argsType = std::vector< std::string >;
    using bmsType = std::map< std::string, int >;
    using bookPtr = std::unique_ptr< Phonebook >;
    Interface(std::unique_ptr< Phonebook > book, std::ostream& out);
    void doCommand(argsType args);

  private:
    bookPtr book_;
    bmsType bookmarks_;
    std::ostream& out_;
    const std::map< std::string, void(Interface::*)(argsType) > commands_
    {
      {"add", &Interface::doAdd},
      {"store", &Interface::doStore},
      {"insert", &Interface::doInsert},
      {"delete", &Interface::doDelete},
      {"show", &Interface::doShow},
      {"move", &Interface::doMove},
    };
    void doAdd(argsType args);
    void doStore(argsType args);
    void doInsert(argsType args);
    void doDelete(argsType args);
    void doShow(argsType args);
    void doMove(argsType args);
  };
  Phonebook::iterator getEntry(Interface::bookPtr& book, Interface::bmsType bms, std::string bmName);
  bool compareEntry(std::pair< int, std::string > entry, int number);
  bool checkBookmark(Interface::bmsType bms, std::string name, std::ostream& out);
}

#endif

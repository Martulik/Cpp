#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <utility>
#include "bm-container.hpp"
#include "command-table.hpp"

namespace pozdnyakov
{
  class Interface
  {
  public:
    using argsType = std::vector< std::string >&;
    using bookPtr = std::unique_ptr< Phonebook >;
    Interface(std::unique_ptr< Phonebook > book, std::istream& in, std::ostream& out);
    void doCommand(argsType args);
    void start();

  private:
    bookPtr book_;
    std::istream& in_;
    std::ostream& out_;
    BmContainer bookmarks_;
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
  CommandTable getTable();
}

#endif

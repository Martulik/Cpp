#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <utility>
#include <list>
#include <iostream>
#include <string>
#include <memory>
#include "phonebook.hpp"

namespace pozdnyakov
{
  class Interface
  {
  public:
    using argsType = std::vector< std::string >;
    Interface(std::unique_ptr< Phonebook > book, std::ostream& out);
    void doCommand(argsType args);

  private:
    std::unique_ptr< poz::Phonebook > book_;
    std::map< std::string, int > bookmarks_;
    std::ostream& out_;
    const std::map< std::string, void(*command)(argsType) > commands_
    {
      {"add", doShow},
      {"store", doShow},
      {"insert", doInsert},
      {"delete", doDelete},
      {"show", doShow},
      {"move", doMove},
    };
    void doAdd(argsType args);
    void doStore(asrgsType args);
    void doInsert(argsType args);
    void doDelete(argsType args);
    void doShow(argsType args);
    void doMove(argsType args);
  }
}

#endif

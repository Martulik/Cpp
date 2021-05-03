#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <utility>
#include <list>
#include <string>
#include "phonebook.hpp"

namespace pozdnyakov
{
  class Interface
  {
  public:
    Interface() = delete;
    static void doCommand(char* argv[]);

  private:
    static void doAdd(char* argv[]);
    static void doStore(char* argv[]);
    static void doInsert(char* argv[]);
    static void doDelete(char* argv[]);
    static void doShow(char* argv[]);
    static void doMove(char* argv[]);
    static std::map< char*, int > bookmarks;
    // store only keys, because of iterator invalidation
    static std::map< char*, void(*command)(char**) > commands
    {
      {"add", doShow},
      {"store", doShow},
      {"insert", doInsert},
      {"delete", doDelete},
      {"show", doShow},
      {"move", doMove},
    };
  }
}

#endif

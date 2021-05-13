#ifndef USER_INTERFACE_HPP
#define USER_INTERFACE_HPP

#include "book.hpp"
#include <map>

namespace ferapontov
{
  class Interface
  {
    public:
      void add(int number, std::string name); //pushback
      
      void store(std::string oldMark, std::string newMark);
      void insert(std::string mode, std::string markName, int number, std::string name);
      void deleteNote(std::string markName);
      void show(std::string markName);
      void move(std::string markName, int steps);
    private:
      PhoneBook book_;
      std::map< std::string, iter > bookmarks_;
  };
}

#endif

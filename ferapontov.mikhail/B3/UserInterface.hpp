#ifndef USER_INTERFACE_HPP
#define USER_INTERFACE_HPP

#include "book.hpp"
#include <map>

namespace ferapontov
{
  class Interface
  {
    public:
      Interface();

      void add(std::string& name, int number);
      void store(std::string& oldMark, std::string& newMark);
      void insertNote(std::string& mode, std::string& markName, int number, std::string& name);
      void deleteNote(std::string& markName);
      void show(std::ostream& out, std::string& markName);
      void move(std::string& markName, int steps);
    private:
      PhoneBook book_;
      std::map< std::string, iter > bookmarks_;

      void checkBookMark(std::string& name) const;
  };
}

#endif

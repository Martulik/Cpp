#ifndef USER_INTERFACE_HPP
#define USER_INTERFACE_HPP

#include "book.hpp"
#include <map>

namespace ferapontov
{
  class Interface
  {
    public:
      using map_iter = std::map< std::string, const_iter >::iterator;
      using const_map_iter = std::map< std::string, const_iter >::const_iterator;
      Interface();

      void add(const std::string& name, const std::string& number);
      void store(const std::string& firstMark, const std::string& secondMark);
      void insertNote(std::string& mode, std::string& markName, std::string& name, std::string& number);
      void deleteNote(std::string& markName);
      ferapontov::data_t show(std::string& markName);
      void move(std::string& markName, std::string& steps);
    private:
      PhoneBook book_;
      std::map< const std::string, const_iter > bookmarks_;

      void checkBookMark(const std::string& name) const;
  };
}

#endif

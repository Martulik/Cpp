#ifndef USER_INTERFACE_HPP
#define USER_INTERFACE_HPP

#include <map>
#include "book.hpp"

namespace ferapontov
{
  class Interface
  {
    public:
      using map_iter = std::map< std::string, const_iter >::iterator;
      using const_map_iter = std::map< std::string, const_iter >::const_iterator;
      Interface();

      void add(const data_t& note);
      void store(const std::string& firstMark, const std::string& secondMark);
      void insertNote(const std::string& mode, const std::string& markName, const data_t& note);
      void deleteNote(const std::string& markName);
      ferapontov::data_t show(const std::string& markName);
      void move(const std::string& markName, const std::string& steps);
    private:
      PhoneBook book_;
      std::map< const std::string, const_iter > bookmarks_;

      void checkBookMark(const std::string& name) const;
  };
}

#endif

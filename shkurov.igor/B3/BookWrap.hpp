#ifndef USER_INTERFACE_HPP
#define USER_INTERFACE_HPP

#include <iosfwd>
#include <string>
#include <map>
#include <memory>

#include "PhoneBook.hpp"

namespace shkurov
{
  class BookWrap
  {
    public:
      using bookPtr = std::unique_ptr< PhoneBook >;
      using iterator = std::map< std::string, PhoneBook::const_iterator_t >::iterator;
      BookWrap(PhoneBook& book, std::ostream& out);
      void doAction(const std::string& tag, std::istringstream& istr);
      void pushBack(const std::string& number, const std::string& name);
      void pushFront(const std::string& number, const std::string& name);
    private:
      bookPtr book_;
      std::map< std::string, PhoneBook::const_iterator_t > bookmarks_;
      std::ostream& out_;
  };
}

#endif

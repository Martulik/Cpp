#ifndef USER_INTERFACE_HPP
#define USER_INTERFACE_HPP

#include <map>

#include "phone-book.hpp"

namespace savchuk
{
  class UserInterface
  {
    public:
      UserInterface();

      void add(const contact_t& contact);
      void store(const std::string& markName, const std::string& newMarkName);
      void insertBefore(const std::string& markName, const contact_t& contact);
      void insertAfter(const std::string& markName, const contact_t& contact);
      void remove(const std::string& markName);
      const contact_t& getContact(const std::string& markName) const;
      void move(const std::string& markName, const std::string& steps);

    private:
      PhoneBook phoneBook_;
      std::map< std::string, PhoneBook::const_iterator > bookmarks_;

      void checkMark(const std::string& markName) const;
  };
}

#endif

#ifndef USERINTERFACE_HPP
#define USERINTERFACE_HPP

#include <string>
#include <map>
#include "PhoneBook.hpp"

namespace ezerinia {
  class UserInterface {
  public:
    UserInterface();
    void add(PhoneBook::data &record);
    void store(std::string &bookmark, std::string &newBookmark);
    void insert(const std::string &position, std::string &bookmark, PhoneBook::data &record);
    void deleteRecord(std::string &bookmark);
    void show(std::string &bookmark);
    void move(std::string &bookmark, int steps);
    void move(std::string &bookmark, const std::string &movePosition);
  private:
    std::map< std::string, PhoneBook::iterator > bookmarks_;
    PhoneBook phoneBook_;
  };
}
#endif

#ifndef USERINTERFACE_HPP
#define USERINTERFACE_HPP

#include <string>
#include <map>
#include "PhoneBook.hpp"
#include "record_t.hpp"

namespace ezerinia {
  class UserInterface {
  public:
    enum class posOfInsert{
      before,
      after
    };
    enum class posOfMove{
      first,
      last
    };
    UserInterface();
    void add(record_t &record);
    void store(std::string &oldMarkName, std::string &newMarkName);
    void insert(posOfInsert position, std::string &bookmark, record_t &record);
    void deleteRecord(std::string &bookmark);
    void show(std::string &bookmark);
    void move(std::string &bookmark, int steps);
    void move(std::string &bookmark, posOfMove position);
  private:
    std::map< std::string, PhoneBook::iterator > bookmarks_;
    PhoneBook phoneBook_;
  };
}
#endif

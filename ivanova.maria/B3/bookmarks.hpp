#ifndef B3_BOOKMARKS_HPP
#define B3_BOOKMARKS_HPP

#include <map>
#include <iostream>

#include "phonebook.hpp"
namespace ivanova
{
  class Bookmarks
  {
    public:
      enum InsertType
      {
        BEFORE,
        AFTER
      };
      enum positionMove
      {
        FIRST,
        LAST
      };

    Bookmarks();
    void add(const PhoneBook::Record &iter);
    void store(const PhoneBook::Record &data);
    void insert(InsertType dir, const std::string &markName, const PhoneBook::Record &rec);
    void deleteMark(const std::string &markName);
    void show(const std::string &markName);
    void move(const std::string &markName, int step);
    void move(const std::string &markName, positionMove position);
    bool isEmpty();

  private:
    PhoneBook phoneBook_;
    std::map< std::string, PhoneBook::iter > bookmarks_;
  };
}
#endif

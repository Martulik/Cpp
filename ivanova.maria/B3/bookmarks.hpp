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
    void add(const ivanova::Record &iter);
    void store(const std::pair< std::string, std::string > &data);
    void insert(InsertType dir, const std::string &markName, const ivanova::Record &rec);
    void deleteMark(const std::string &markName);
    void show(const std::string &markName);
    void move(const std::string &markName, int step);
    void move(const std::string &markName, positionMove position);
    bool isEmpty();

  private:
    PhoneBook phoneBook_;
    std::map< std::string, PhoneBook::iter > bookmarks_;
  };

  void invalidCommand(std::ostream& out);
  void empty(std::ostream &out);
  void invalidBookmark(std::ostream &out);
  void invalidStep(std::ostream &out);
}
#endif

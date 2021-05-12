#ifndef B3_BOOKMARKS_HPP
#define B3_BOOKMARKS_HPP

#include <map>

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
    using iter = std::map< std::string, PhoneBook::iter >::const_iterator;
    void add(const ivanova::Record &iter);
    void store(const ivanova::Record &data);
    void insert( const ivanova::Record &rec, InsertType dir, const std::string &markName);
    void deleteMark(const std::string &markName);
    void show(const std::string &markName);
    void move(const std::string &markName, int step);
    void move(const std::string &markName, positionMove position);
    bool isEmpty();
    iter findMark(const std::string &name) const;
  private:
    PhoneBook phoneBook_;
    std::map< std::string, PhoneBook::iter > bookmarks_;
  };
}
#endif

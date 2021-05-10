#ifndef USERINTERFACE_HPP
#define USERINTERFACE_HPP

#include <map>
#include "PhoneBook.hpp"

namespace ezerinia {
  class Book {
  public:
    enum class posOfInsert {
      before,
      after
    };
    enum class posOfMove {
      first,
      last
    };

    Book();
    void add(const record_t &record);
    void store(const std::string &oldMarkName, const std::string &newMarkName);
    void insert(posOfInsert position, const std::string &bookmark, record_t &record);
    void deleteRecord(const std::string &bookmark);
    void show(const std::string &bookmark, std::ostream &out) const;
    void move(const std::string &bookmark, int steps);
    void move(const std::string &bookmark, posOfMove position);
    bool containsBookmark(const std::string &bookmark) const;
    bool empty() const;
  private:
    PhoneBook phoneBook_;
    std::map< std::string, PhoneBook::const_iterator > bookmarks_;
  };
}
#endif

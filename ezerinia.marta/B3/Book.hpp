#ifndef BOOK_HPP
#define BOOK_HPP

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
    using const_iterator = std::map< std::string, PhoneBook::const_iterator >::const_iterator;
    using iterator = std::map< std::string, PhoneBook::const_iterator >::iterator;

    Book();
    void add(const record_t &record);
    void store(const std::string &oldMarkName, const std::string &newMarkName);
    void insert(const std::string &bookmark, record_t &record, posOfInsert position);
    void deleteRecord(const std::string &bookmark);
    void move(const std::string &bookmark, int steps);
    void move(const std::string &bookmark, posOfMove position);
    bool containsBookmark(const std::string &bookmark) const;
    bool empty() const;
    const_iterator findBookmark(const std::string &bookmark) const;
  private:
    PhoneBook phoneBook_;
    std::map< std::string, PhoneBook::const_iterator > bookmarks_;
  };
}
#endif

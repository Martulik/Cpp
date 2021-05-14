#ifndef PHONEBOOKINTERFACE_HPP
#define PHONEBOOKINTERFACE_HPP

#include <map>
#include "phonebook.hpp"

namespace diurdeva {
  class PhonebookManager {
  public:
    enum class InsertPosition {
      BEFORE,
      AFTER
    };

    enum class MovePosition {
      FIRST,
      LAST
    };

    using const_iterator = std::map< std::string, Phonebook::const_iterator >::const_iterator;
    PhonebookManager();
    void add(const record_t &record);
    void store(const std::string &bookmark, const std::string &name);
    void insert(InsertPosition point, const std::string &bookmark, record_t &record);
    void deleteNote(const std::string &);
    void move(const std::string &, int);
    void move(const std::string &, MovePosition);
    bool containsBookmark(const std::string &bookmark) const;
    bool empty() const;
    const_iterator findBookmark(const std::string& mark) const;
  private:
    using bookmarks = std::map< std::string, Phonebook::const_iterator >;
    Phonebook records_;
    bookmarks bookmarks_;
  };
}

#endif

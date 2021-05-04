#ifndef PHONEBOOKINTERFACE_HPP
#define PHONEBOOKINTERFACE_HPP

#include <map>
#include "phonebook.hpp"

namespace diurdeva {
  class PhonebookManager
  {
  public:
    enum class InsertPosition
    {
      BEFORE,
      AFTER
    };

    enum class MovePosition
    {
      FIRST,
      LAST
    };

    PhonebookManager();

    void add(const Phonebook::record_t& record);
    void store(const std::string& bookmark, const std::string& name);
    void insert(InsertPosition point, const std::string& bookmark, const Phonebook::record_t& record);
    void deleteNote(const std::string&);
    void show(const std::string&);
    void move(const std::string&, int);
    void move(const std::string&, MovePosition);
  private:
    using bookmarks = std::map<std::string, Phonebook::iterator>;
    Phonebook records_;
    bookmarks bookmarks_;
    bookmarks::iterator getBookmarkIterator(const std::string&);
  };
}

#endif 

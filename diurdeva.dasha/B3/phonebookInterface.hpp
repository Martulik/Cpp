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

    void add(const record_t& record);
    void store(const std::string& bookmark, const std::string& name);
    void insert(InsertPosition point, const std::string& bookmark, record_t& record);
    void deleteNote(const std::string&);
    void show(const std::string&);
    void move(const std::string&, int);
    void move(const std::string&, MovePosition);
    bool containsBookmark(const std::string& bookmark);
  private:
    using bookmarks = std::map<std::string, Phonebook::iterator>;
    Phonebook records_;
    bookmarks bookmarks_;
  };
}

#endif 

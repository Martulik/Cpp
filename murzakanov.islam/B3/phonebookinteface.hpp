#ifndef PHONE_BOOK_INTERFACE_HPP
#define PHONE_BOOK_INTERFACE_HPP

#include <memory>
#include <map>
#include <string>
#include "phone-book.hpp"
#include "note.hpp"

namespace murzakanov
{
  class BookInterface
  {
  public:
    using note_t = murzakanov::note_t;
    using iteratorType = std::map< std::string, murzakanov::PhoneBook::const_iterator >::iterator;
    using constIteratorType = std::map< std::string, murzakanov::PhoneBook::const_iterator >::const_iterator;
    explicit BookInterface(PhoneBook& book);
    void add(const note_t& note);
    void store(const std::string& bookmark, const std::string& newBookmark);
    void insertBefore(const std::string& bookmark, const note_t& note);
    void insertAfter(const std::string& bookmark, const note_t& note);
    void deleteNote(const std::string& bookmark);
    note_t show(const std::string& bookmark) const;
    void move(const std::string& bookmark, int steps);
    void move(const std::string& bookmark, const std::string& keyWord);
    bool contains(const std::string& bookmark) const;
    bool empty() const;
  private:
    std::unique_ptr< murzakanov::PhoneBook > book_;
    std::map< std::string, murzakanov::PhoneBook::const_iterator > bookmarks_;
  };
}

#endif

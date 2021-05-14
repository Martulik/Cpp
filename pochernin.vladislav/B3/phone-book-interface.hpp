#ifndef PHONE_BOOK_INTERFACE_HPP
#define PHONE_BOOK_INTERFACE_HPP

#include <memory>
#include <map>
#include <iostream>

#include "phone-book.hpp"
#include "note.hpp"
#include "bookmark.hpp"

namespace pochernin
{
  class PhoneBookInterface
  {
  public:
    using constIterator = PhoneBook::constIterator;

    explicit PhoneBookInterface(PhoneBook& book);

    void add(const Note& note);
    bool empty() const;
    bool contains(const Bookmark& bookmark) const;
    void show(const Bookmark& bookmark, std::ostream& out) const;

  private:
    std::unique_ptr< PhoneBook > book_;
    std::map< std::string, constIterator > bookmarks_;
  };
}

#endif

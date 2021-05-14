#ifndef PHONE_BOOK_INTERFACE_HPP
#define PHONE_BOOK_INTERFACE_HPP

#include <memory>
#include <map>

#include "phone-book.hpp"
#include "note.hpp"

namespace pochernin
{
  class PhoneBookInterface
  {
  public:
    using constIterator = PhoneBook::constIterator;

    explicit PhoneBookInterface(PhoneBook& book);

    void add(const Note& note);

  private:
    std::unique_ptr< PhoneBook > book_;
    std::map< std::string, constIterator > bookmarks_;
  };
}

#endif

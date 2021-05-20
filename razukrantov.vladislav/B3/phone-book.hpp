#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include <list>
#include <string>

#include "note.hpp"

namespace razukrantov
{
  class PhoneBook
  {
  public:
    using iterator = std::list< razukrantov::note_t >::iterator;
    using constIterator = std::list< razukrantov::note_t >::const_iterator;

    size_t size() const;
    bool empty() const;
    void insertAfter(constIterator iterator, const razukrantov::note_t& note);
    void insertBefore(constIterator iterator, const razukrantov::note_t& note);
    void pushBack(const razukrantov::note_t& note);
    constIterator move(constIterator it, int steps) const;
    void erase(constIterator iterator);
    constIterator begin();
    constIterator end();

  private:
    std::list< razukrantov::note_t > recordings_;
  };
}

#endif

#ifndef BOOK_HPP
#define BOOK_HPP

#include <list>
#include <iostream>
#include "note.hpp"

namespace borisova
{
  class Book
  {
  public:
    using iterator = std::list< Note >::iterator;
    void viewCurrent(iterator iter, std::ostream& out) const;
    iterator insertAfter(iterator iter, const Note &src);
    iterator insertBefore(iterator iter, const Note& src);
    void insertBack(const Note& src);
    void deleteNote(iterator iter);
    bool empty() const;
    iterator begin();
    iterator end();

  private:
    std::list< Note > phoneBook_;
  };
}

#endif

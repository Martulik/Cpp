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
    void viewCurrent(iterator iter, std::ostream& out);
    iterator insertAfter(iterator iter, Note &src);
    iterator insertBefore(iterator iter, Note& src);
    void insertBack(Note& src);
    void deleteNote(iterator iter);
    bool empty() const;
    iterator begin();
    iterator end();

  private:
    std::list< Note > phoneBook_;
  };
}

#endif

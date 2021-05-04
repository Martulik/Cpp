#ifndef BOOK_HPP
#define BOOK_HPP

#include <list>
#include "tools.hpp"
namespace borisova
{
  class Book
  {
  public:
    using iterator = std::list< Note >::iterator;

    void viewCurrent(iterator iter);
    iterator nextNote(iterator iter);
    iterator prevNote(iterator iter);
    iterator insertAfter(iterator iter, Note &src);
    iterator insertBefore(iterator iter, Note& src);
    iterator rewriteCurrent(iterator iter, Note& src);
    void insertBack(Note& src);
    void deleteNote(iterator iter);
    iterator cross(iterator iter, int n);
    bool empty();
    iterator begin();
    iterator end();

  private:
    std::list< Note > phoneBook_;
  };
}

#endif

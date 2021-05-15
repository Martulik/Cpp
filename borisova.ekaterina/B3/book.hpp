#ifndef BOOK_HPP
#define BOOK_HPP

#include <list>
#include "note.hpp"

namespace borisova
{
  class Book
  {
  public:
    Book() = default;
    using constItr = std::list< Note >::const_iterator;
    constItr insertAfter(constItr iter, const Note& src);
    constItr insertBefore(constItr iter, const Note& src);
    void insertBack(const Note& src);
    void deleteNote(constItr iter);
    bool empty() const;
    constItr begin() const;
    constItr end() const;

  private:
    std::list< Note > phoneBook_;
  };
}

#endif

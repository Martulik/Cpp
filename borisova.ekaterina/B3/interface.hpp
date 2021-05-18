#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <map>
#include <string>
#include "book.hpp"

namespace borisova
{
  class Interface
  {
  public:
    using constItr = std::map< std::string, Book::constItr >::const_iterator;
    Interface();
    void add(const Note& src);
    void store(const std::string& oldMark, const std::string& newMark);
    void insertBefore(const std::string& bookMark, const Note& src);
    void insertAfter(const std::string& bookMark, const Note& src);
    void deleteMark(const std::string& bookMark);
    void move(const std::string& bookmark, const int n);
    void move(const std::string& bookmark, const std::string step);
    constItr findMark(const std::string mark) const;
    constItr getEnd() const;
    bool isEmpty();
  private:
    Book phoneNotes_;
    std::map< std::string, Book::constItr > notes_;
  };
}

#endif

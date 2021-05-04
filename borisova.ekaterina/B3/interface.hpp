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
    Interface();
    void add(Note& src);
    void store(std::string& oldMark, std::string& newMark);
    void insertBefore(std::string& bookMark, Note& src);
    void insertAfter(std::string& bookMark, Note& src);
    void deleteMark(std::string& bookMark);
    void show(std::string& bookMark);
    void move(std::string& bookmark, int n);

  private:
    std::map<std::string, Book::iterator> notes_;
    Book phoneNotes_;
  };

  const std::string invalidCommand = "<INVALID COMMAND>\n";
  const std::string invalidBookMark = "<INVALID BOOKMARK>\n";
  const std::string empty = "<EMPTY>\n";
}

#endif

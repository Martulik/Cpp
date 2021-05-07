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
    void store(const std::string& oldMark, const std::string& newMark, std::ostream& out);
    void insertBefore(const std::string& bookMark, Note& src, std::ostream& out);
    void insertAfter(const std::string& bookMark, Note& src, std::ostream& out);
    void deleteMark(const std::string& bookMark);
    void show(const std::string& bookMark, std::ostream& out);
    void move(const std::string& bookmark, int n, std::ostream& out);
    void move(const std::string& bookmark, std::string step, std::ostream& out);

  private:
    using itr = std::map< std::string, Book::iterator >::iterator;
    std::map< std::string, Book::iterator > notes_;
    Book phoneNotes_;
  };

  void invalidCommand(std::ostream& out);
  void invalidBookMark(std::ostream& out);
  void invalidStep(std::ostream& out);
  void empty(std::ostream& out);
}

#endif

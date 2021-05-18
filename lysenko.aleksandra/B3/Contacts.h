#ifndef CONTACTS_HPP
#define CONTACTS_HPP

#include <string>
#include <list>

namespace lysenko
{
  class Contacts
  {
  public:
    struct Note
    {
      std::string name;
      std::string number;
    };

    using constIteratorNote = std::list< Note >::const_iterator;
    using iteratorNote = std::list< Note >::iterator;
    using constNote = const Note&;

    bool isEmpty() const;

    constIteratorNote getBegin() const;
    constIteratorNote getEnd() const;

    void insert(constIteratorNote curr, constNote newNote, bool before);
    void deleteNote(constIteratorNote curr);
    void pushBack(constNote newNote);

  private:
    std::list< Note > content_;
  };
}

#endif

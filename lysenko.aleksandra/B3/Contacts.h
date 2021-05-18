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

    bool isEmpty() const;

    constIteratorNote getBegin() const;
    constIteratorNote getEnd() const;

    void insert(constIteratorNote curr, const Note& newNote, bool before);
    void deleteNote(constIteratorNote curr);
    void pushBack(const Note& newNote);

  private:
    std::list< Note > content_;
  };
}

#endif

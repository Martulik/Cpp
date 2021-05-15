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

    using iterator = std::list< lysenko::Contacts::Note >::iterator;
    using constIterator = std::list< lysenko::Contacts::Note >::const_iterator;

    bool isEmpty() const;

    constIterator getBegin() const;
    constIterator getEnd() const;

    constIterator showCurrNote(constIterator curr) const;

    void replaceNote(iterator curr, Note newNote);
    void insert(constIterator curr, const Note newNote, bool before);
    void deleteNote(constIterator curr);
    void pushBack(Note newNote);

  private:
    std::list< Note > content_;
  };
}

#endif

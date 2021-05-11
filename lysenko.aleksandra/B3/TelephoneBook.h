#ifndef TELEPHONE_BOOK_HPP
#define TELEPHONE_BOOK_HPP

#include <string>
#include <list>

namespace lysenko
{
  class Book
  {
  public:
    struct Note
    {
      std::string name;
      std::string number;
    };

    typedef std::list< lysenko::Book::Note >::iterator iterator;

    bool isEmpty() const;

    iterator getBegin();
    iterator getEnd();

    iterator goToNextNote(iterator curr);
    iterator goToPrevNote(iterator curr);
    iterator goTo(iterator curr,bool forward, int amount);

    void showCurrNote(iterator curr) const;

    void replaceNote(iterator curr, Note newNote);
    void insert(iterator &curr, const Note newNote, bool before);
    iterator deleteNote(iterator& curr);
    void pushBack(Note &newNote);

  private:
    std::list< Note > content_;
  };
}

#endif

#ifndef TELEPHONE_BOOK_HPP
#define TELEPHONE_BOOK_HPP

#include <memory>

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

    typedef std::list< Note >::iterator iterator;

    iterator getBegin();
    iterator getEnd();

    iterator goToNextNote(iterator curr);
    iterator goToPrevNote(iterator curr);
    iterator goTo(iterator curr,bool forward, int amount);

    void showCurrNote(iterator curr);
    void replaceNote(iterator curr, Note newNote);
    void insert(iterator curr, const Note newNote, bool before);
    void pushBack(Note newNote);

  private:
    std::list< Note > content_;
  };
}
 
#endif


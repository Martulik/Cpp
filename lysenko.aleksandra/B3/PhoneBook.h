#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contacts.h"

#include <string>
#include <map>

namespace lysenko
{
  class PhoneBook
  {
  public:
    PhoneBook();

    using constIteratorNote = std::list< Contacts::Note >::const_iterator;

    struct bookMark
    {
      std::string markName;
      constIteratorNote contact;
    };

    using iteratorMark = std::list< PhoneBook::bookMark >::iterator;
    using constNote = const Contacts::Note&;

    void addNumber(constNote note);
    void createNewbookMarkHere(std::string oldMarkName, std::string newMarkName);
    void insertNoteNextTobookMark(bool before, std::string markName, constNote note);
    void deleteThisNote(std::string markName);
    void removeThisBookMark(std::string markName, bool forward, int steps);
    void removeThisBookMark(std::string markName, bool first);

    constIteratorNote showThisNote(std::string markName);
    bool checkIfThisMarkNameContains(std::string markName);
    bool noContacts();
  private:
    Contacts contacts_;
    std::list< bookMark > bookMarks_;

    bool checkItIsOnlyMarked(iteratorMark curr);
    iteratorMark findThisMark(std::string thisMark);
    iteratorMark getEndOfBookMarks();
  };
}
#endif

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

    using constIterator = std::list< Contacts::Note >::const_iterator;

    struct bookMark
    {
      std::string markName;
      constIterator contact;
    };

    using iteratorMark = std::list< PhoneBook::bookMark >::iterator;

    void addNumber(Contacts::Note note);
    void createNewbookMarkHere(std::string oldMarkName, std::string newMarkName);
    void insertNoteNextTobookMark(bool before, std::string markName, std::string name, std::string number);
    void deleteThisNote(std::string markName);
    void removeThisBookMark(std::string markName, bool forward, std::string steps);
    void removeThisBookMark(std::string markName, bool first);

    constIterator showThisNote(std::string markName);
    bool checkIfThisMarkNameContains(std::string& markName);
    bool noContacts();
  private:
    Contacts contacts_;
    std::list< bookMark > bookMarks_;

    bool checkItIsOnlyMarked(lysenko::PhoneBook::iteratorMark curr);
    iteratorMark findThisMark(std::string thisMark);
    iteratorMark getEndOfBookMarks();
  };
}
#endif

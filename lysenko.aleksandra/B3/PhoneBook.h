#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contacts.h"

#include <string>
#include <map>

#include "helpFunctions.h"

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

    void addNumber(std::string name, std::string number);
    void createNewbookMarkHere(std::string oldMarkName, std::string newMarkName);
    void insertNoteNextTobookMark(bool before, std::string markName, std::string name, std::string number);
    void deleteThisNote(std::string markName);
    void removeThisbookMark(std::string markName, bool first, bool last, bool forward, std::string steps);

    constIterator showThisNote(std::string markName);

    friend bool checkItIsOnlyMarked(lysenko::PhoneBook::iteratorMark curr, PhoneBook& myBook);
    friend bool noContacts(PhoneBook& myBook);
    friend lysenko::PhoneBook::iteratorMark findThisMark(std::string thisMark, PhoneBook& myBook);
    friend lysenko::PhoneBook::iteratorMark getEndOfbookMarks(PhoneBook& myBook);
  private:
    std::list< bookMark > bookMarks_;
    Contacts contacts_;
  };
}
#endif

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

    using note_t = Contacts::Note;
    using constIteratorNote = std::list< note_t >::const_iterator;

    struct bookMark
    {
      std::string markName;
      constIteratorNote contact;
    };

    using iteratorMark = std::list< PhoneBook::bookMark >::iterator;

    void addNumber(const note_t& note);
    void createNewbookMarkHere(std::string oldMarkName, std::string newMarkName);
    void insertNoteNextTobookMark(bool before, std::string markName, const note_t& note);
    void deleteThisNote(std::string markName);
    void removeThisBookMark(std::string markName, bool forward, int steps);
    void removeThisBookMark(std::string markName, bool first);

    constIteratorNote showThisNote(std::string markName);
    bool checkIfThisMarkNameContains(std::string markName);
    bool noContacts() const;
  private:
    Contacts contacts_;
    std::list< bookMark > bookMarks_;

    bool checkItIsOnlyMarked(iteratorMark curr);
    iteratorMark findThisMark(std::string thisMark);
    iteratorMark getEndOfBookMarks();
  };
}
#endif

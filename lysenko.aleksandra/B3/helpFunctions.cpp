#include "helpFunctions.h"

#include "Contacts.h"
#include "PhoneBook.h"

namespace lysenko
{
  Contacts::constIterator goToNextNote(Contacts::constIterator curr)
  {
    return ++curr;
  }

  Contacts::constIterator goToPrevNote(Contacts::constIterator curr)
  {
    return --curr;
  }

  Contacts::constIterator goTo(Contacts::constIterator curr, bool forward, int amount)
  {
    lysenko::Contacts::constIterator newCurr = curr;
    if (forward)
    {
      for (int i = 0; i < amount; ++i)
      {
        newCurr = goToNextNote(newCurr);
      }
    }
    else
    {
      for (int i = 0; i < amount; ++i)
      {
        newCurr = goToPrevNote(newCurr);
      }
    }
    return newCurr;
  }

  PhoneBook::iteratorMark getEndOfbookMarks(PhoneBook& myBook)
  {
    return myBook.bookMarks_.end();
  }

  bool noContacts(PhoneBook& myBook)
  {
    return myBook.contacts_.isEmpty();
  }


  PhoneBook::iteratorMark findThisMark(std::string thisMark, PhoneBook& myBook)
  {
    bool markIsFound = 0;
    PhoneBook::iteratorMark checkMark = myBook.bookMarks_.begin();
    while ((markIsFound == 0) && (checkMark != myBook.bookMarks_.end()))
    {
      if (checkMark->markName == thisMark)
      {
        markIsFound = 1;
      }
      else
      {
        checkMark = ++checkMark;
      }
    }
    return checkMark;
  }

  bool checkItIsOnlyMarked(PhoneBook::iteratorMark curr, PhoneBook& myBook)
  {
    int amount = 0;
    PhoneBook::iteratorMark check = myBook.bookMarks_.begin();
    PhoneBook::constIterator contact = curr->contact;
    for (size_t i = 0; i < myBook.bookMarks_.size();++i)
    {
      if (check->contact == contact)
      {
        amount += 1;
      }
      check++;
    }
    if (amount != 1)
    {
      return 0;
    }
    return 1;
  }
}

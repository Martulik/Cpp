#include "PhoneBook.h"

#include "helpFunctions.h"

#include <list>

lysenko::PhoneBook::PhoneBook():
  contacts_(),
  bookMarks_({ {"current", contacts_.getBegin()} })
{}

void lysenko::PhoneBook::addNumber(const note_t& note)
{
  iteratorMark current = findThisMark("current");
  if ((current->contact == contacts_.getBegin()) && (noContacts()))
  {
    contacts_.pushBack(note);
    current->contact = contacts_.getBegin();
  }
  else
  {
    contacts_.pushBack(note);
  }
}

void lysenko::PhoneBook::createNewbookMarkHere(std::string oldMarkName, std::string newMarkName)
{
  iteratorMark newbookMark = findThisMark(oldMarkName);
  bookMarks_.push_front({ newMarkName, newbookMark->contact });
}

void lysenko::PhoneBook::insertNoteNextTobookMark(bool before, std::string markName, const note_t& newNote)
{
  iteratorMark curr = findThisMark(markName);
  iteratorMark current = findThisMark("current");
  if ((current->contact == contacts_.getBegin()) && (contacts_.isEmpty()))
  {
    contacts_.insert(curr->contact, newNote, before);
    current->contact = contacts_.getBegin();
  }
  else
  {
    contacts_.insert(curr->contact, newNote, before);
  }
}

void lysenko::PhoneBook::deleteThisNote(std::string markName)
{
  iteratorMark curr = findThisMark(markName);
  constIteratorNote newContact;
  if (curr->contact != --contacts_.getEnd())
  {
    newContact = goToNextNote(curr->contact);
  }
  else if (curr->contact != contacts_.getBegin())
  {
    newContact = goToPrevNote(curr->contact);
  }

  if (checkItIsOnlyMarked(curr))
  {
    if (curr->contact == contacts_.getBegin())
    {
      contacts_.deleteNote(curr->contact);
      newContact = contacts_.getBegin();
      curr->contact = newContact;
    }
    else
    {
      contacts_.deleteNote(curr->contact);
      curr->contact = newContact;
    }
  }
  else
  {
    iteratorMark check = bookMarks_.begin();
    for (size_t i = 0; i < bookMarks_.size(); ++i)
    {
      if (check->contact == curr->contact)
      {
        if (i != bookMarks_.size() - 1)
        {
          check->contact = goToNextNote(check->contact);
        }
        else
        {
          check->contact = goToPrevNote(check->contact);
        }
      }
    }
    contacts_.deleteNote(curr->contact);
  }
}

lysenko::PhoneBook::constIteratorNote lysenko::PhoneBook::showThisNote(std::string markName)
{
  iteratorMark curr = findThisMark(markName);
  constIteratorNote thisNote = curr->contact;
  return thisNote;
}

void lysenko::PhoneBook::removeThisBookMark(std::string markName, bool forward, int steps)
{
  iteratorMark curr = findThisMark(markName);
  constIteratorNote note;

  if (forward)
  {
    note = goTo(curr->contact, 1, steps);
  }
  else
  {
    steps = std::abs(steps);
    note = goTo(curr->contact, 0, steps);
  }
  curr->contact = note;
}

void lysenko::PhoneBook::removeThisBookMark(std::string markName, bool first)
{
  iteratorMark curr = findThisMark(markName);
  constIteratorNote note;

  if (first)
  {
    note = contacts_.getBegin();
  }
  else
  {
    note = goToPrevNote(contacts_.getEnd());
  }
  curr->contact = note;
}

lysenko::PhoneBook::iteratorMark lysenko::PhoneBook::getEndOfBookMarks()
{
  return bookMarks_.end();
}

bool lysenko::PhoneBook::noContacts() const
{
  return contacts_.isEmpty();
}


lysenko::PhoneBook::iteratorMark lysenko::PhoneBook::findThisMark(std::string thisMark)
{
  bool markIsFound = 0;
  iteratorMark checkMark = bookMarks_.begin();
  while ((markIsFound == 0) && (checkMark != bookMarks_.end()))
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

bool lysenko::PhoneBook::checkItIsOnlyMarked(iteratorMark curr)
{
  int amount = 0;
  iteratorMark check = bookMarks_.begin();
  constIteratorNote contact = curr->contact;
  for (size_t i = 0; i < bookMarks_.size(); ++i)
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

bool lysenko::PhoneBook::checkIfThisMarkNameContains(std::string markName)
{
  iteratorMark newbookMark = findThisMark(markName);
  if (newbookMark == getEndOfBookMarks())
  {
    return 0;
  }
  return 1;
}



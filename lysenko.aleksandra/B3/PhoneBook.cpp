#include "PhoneBook.h"

#include <list>

lysenko::PhoneBook::PhoneBook():
  bookMarks_({ lysenko::PhoneBook::bookMark{"current", contacts_.getBegin()} }),
  contacts_()
{}


void lysenko::PhoneBook::addNumber(std::string name, std::string number)
{
  lysenko::Contacts::Note note{ name, number };
  iteratorMark current = findThisMark("current", *this);
  if ((current->contact == contacts_.getBegin()) && (noContacts(*this)))
  {
    contacts_.pushBack(note);
    current->contact=contacts_.getBegin();
  }
  else
  {
    contacts_.pushBack(note);
  }
}


void lysenko::PhoneBook::createNewbookMarkHere(std::string oldMarkName, std::string newMarkName)
{
  iteratorMark newbookMark = findThisMark(oldMarkName, *this);
  bookMarks_.push_front({newMarkName, newbookMark->contact});
}

void lysenko::PhoneBook::insertNoteNextTobookMark(bool before, std::string markName, std::string name, std::string number)
{
  lysenko::Contacts::Note newNote{ name, number };
  iteratorMark curr = findThisMark(markName, *this);
  iteratorMark current = findThisMark("current", *this);
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
  iteratorMark curr = findThisMark(markName,*this);
  lysenko::Contacts::constIterator newContact;
  if (curr->contact != goToPrevNote(contacts_.getEnd()))
  {
    newContact = goToNextNote(curr->contact);
  }
  else if (curr->contact != contacts_.getBegin())
  {
    newContact = goToPrevNote(curr->contact);
  }

  if (checkItIsOnlyMarked(curr, *this))
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
    for (size_t i = 0; i < bookMarks_.size() ;++i)
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

lysenko::PhoneBook::constIterator lysenko::PhoneBook::showThisNote(std::string markName)
{
  iteratorMark curr = findThisMark(markName, *this);
  constIterator thisNote = contacts_.showCurrNote(curr->contact);
  return thisNote;
}

void lysenko::PhoneBook::removeThisbookMark(std::string markName,bool first, bool last, bool forward, std::string steps )
{
  iteratorMark curr = findThisMark(markName, *this);
  constIterator note;

  if (first)
  {
    note = contacts_.getBegin();
  }
  else if (last)
  {
    note = goToPrevNote(contacts_.getEnd());
  }
  else
  {
    int intSteps = stoi(steps);
    if (forward)
    {
      note = goTo(curr->contact, 1, intSteps);
    }
    else
    {
      intSteps = abs(intSteps);
      note = goTo(curr->contact, 0, intSteps);
    }
  }
  curr->contact = note;
}

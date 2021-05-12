#include "UsersInterface.h"

#include <iostream>
#include <list>

#include "exceptions.h"

lysenko::UsersInterface::UsersInterface():
  bookMarks_(),
  telephoneBook_()
{
  bookMarks_.push_front({"current", telephoneBook_.getBegin()});
};

lysenko::UsersInterface::iteratorMark lysenko::UsersInterface::getEndOfBookMarks()
{
  return bookMarks_.end();
}

bool lysenko::UsersInterface::telephoneBookIsEmpty()
{
  return telephoneBook_.isEmpty();
}

void lysenko::UsersInterface::addNumber(std::string name, std::string number)
{
  lysenko::Book::Note note{ name, number };
  iteratorMark current = findThisMark("current");
  if ((current->contact == telephoneBook_.getBegin()) && (telephoneBookIsEmpty()))
  {
    telephoneBook_.pushBack(note);
    current->contact=telephoneBook_.getBegin();
  }
  else
  {
    telephoneBook_.pushBack(note);
  }
}

lysenko::UsersInterface::iteratorMark lysenko::UsersInterface::findThisMark(std::string thisMark)
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

void lysenko::UsersInterface::createNewBookMarkHere(std::string oldMarkName, std::string newMarkName)
{
  iteratorMark newBookMark = findThisMark(oldMarkName);
  bookMarks_.push_front({newMarkName, newBookMark->contact});
}

void lysenko::UsersInterface::insertNoteNextToBookMark(bool before, std::string markName, std::string name, std::string number)
{
  lysenko::Book::Note newNote{ name, number };
  iteratorMark curr = findThisMark(markName); 
  iteratorMark current = findThisMark("current");
  if ((current->contact == telephoneBook_.getBegin()) && (telephoneBook_.isEmpty()))
  {
    telephoneBook_.insert(curr->contact, newNote, before);
    current->contact = telephoneBook_.getBegin();
  }
  else
  {
    telephoneBook_.insert(curr->contact, newNote, before);
  }
}

bool lysenko::UsersInterface::checkItIsOnlyMarked(lysenko::UsersInterface::iteratorMark curr)
{
  int amount = 0;
  iteratorMark check = bookMarks_.begin();
  iterator contact= curr->contact;
  for (size_t i = 0; i < bookMarks_.size();++i)
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

void lysenko::UsersInterface::deleteThisNote(std::string markName)
{
  iteratorMark curr = findThisMark(markName);
  lysenko::Book::iterator newContact;
  if (curr->contact != telephoneBook_.goToPrevNote(telephoneBook_.getEnd()))
  {
    newContact = telephoneBook_.goToNextNote(curr->contact);
  }
  else
  {
    newContact = telephoneBook_.goToPrevNote(curr->contact);
  }
  if (checkItIsOnlyMarked(curr))
  {
    telephoneBook_.deleteNote(curr->contact);
    curr->contact = newContact;
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
          check->contact = telephoneBook_.goToNextNote(check->contact);
        }
        else
        {
          check->contact = telephoneBook_.goToPrevNote(check->contact);
        }
      }
    }
    telephoneBook_.deleteNote(curr->contact);
  }
}

void lysenko::UsersInterface::showThisNote(std::string markName)
{
  iteratorMark curr = findThisMark(markName);
  telephoneBook_.showCurrNote(curr->contact);
}

void lysenko::UsersInterface::removeThisBookMark(std::string markName,bool first, bool last, bool forward, std::string steps )
{
  iteratorMark curr = findThisMark(markName);
  iterator note;

  if (first)
  {
    note = telephoneBook_.getBegin();
  }
  else if (last)
  {
    note = telephoneBook_.goToPrevNote(telephoneBook_.getEnd());
  }
  else
  {
    int intSteps = stoi(steps);
    if (forward)
    {
      note = telephoneBook_.goTo(curr->contact, 1, intSteps);
    }
    else
    {
      intSteps = abs(intSteps);
      note = telephoneBook_.goTo(curr->contact, 0, intSteps);
    }
  }
  curr->contact = note;
}

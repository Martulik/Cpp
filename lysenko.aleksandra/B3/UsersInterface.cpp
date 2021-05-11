#include "UsersInterface.h"

#include <iostream>
#include <list>

#include "exceptions.h"

lysenko::UsersInterface::UsersInterface() :
  telephoneBook_(),
  bookMarks_()
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
  telephoneBook_.pushBack({name, number});
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
  iteratorMark curr = findThisMark(markName);
  telephoneBook_.insert(curr->contact, {name, number}, before);
}

void lysenko::UsersInterface::deleteThisNote(std::string markName)
{
  iteratorMark curr = findThisMark(markName);
  telephoneBook_.deleteNote(curr->contact);
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
    note = telephoneBook_.getEnd();
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

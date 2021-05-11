#include "TelephoneBook.h"

#include <iostream>

bool lysenko::Book::isEmpty() const
{
  return content_.empty();
}

lysenko::Book::iterator lysenko::Book::getBegin() 
{
  return content_.begin();
}

lysenko::Book::iterator lysenko::Book::getEnd()
{
  return content_.end();
}

void lysenko::Book::replaceNote(iterator curr, Note newNote)
{
  *curr = newNote;
}

lysenko::Book::iterator lysenko::Book::goToNextNote(iterator curr)
{
  return ++curr;
}

lysenko::Book::iterator lysenko::Book::goToPrevNote(iterator curr)
{
  return --curr;
}

lysenko::Book::iterator lysenko::Book::goTo(iterator curr, bool forward, int amount)
{
  iterator newCurr = curr;
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

void lysenko::Book::showCurrNote(iterator curr) const
{
  std::cout << curr->name << " " << curr->number;//мб некорректный вывод в соотв с условием
}

void lysenko::Book::insert(iterator curr, const Note newNote, bool before)
{
  if (before)
  {
    content_.insert(curr, newNote);
  }
  else
  {
    iterator nextOne = goToNextNote(curr);
    content_.insert(nextOne, newNote);
  }
}

void lysenko::Book::deleteNote(iterator& curr)
{
  curr = content_.erase(curr);
}

void lysenko::Book::pushBack(Note newNote)
{
  content_.push_back(newNote);
}

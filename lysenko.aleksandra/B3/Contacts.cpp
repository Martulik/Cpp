#include "Contacts.h"

bool lysenko::Contacts::isEmpty() const
{
  return content_.empty();
}

lysenko::Contacts::constIteratorNote lysenko::Contacts::getBegin() const
{
  return content_.begin();
}

lysenko::Contacts::constIteratorNote lysenko::Contacts::getEnd() const
{
  return content_.end();
}

void lysenko::Contacts::insert(constIteratorNote curr, constNote newNote, bool before)
{
  if (before)
  {
    content_.insert(curr, newNote);
  }
  else
  {
    if ((curr == content_.begin()) && (content_.empty()))
    {
      content_.push_back(newNote);
    }
    else
    {
      constIteratorNote nextOne = ++curr;
      content_.insert(nextOne, newNote);
    }
  }
}

void lysenko::Contacts::deleteNote(constIteratorNote curr)
{
  content_.erase(curr);
}

void lysenko::Contacts::pushBack(constNote newNote)
{
  content_.push_back(newNote);
}

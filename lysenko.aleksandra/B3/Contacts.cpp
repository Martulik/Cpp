#include "Contacts.h"

bool lysenko::Contacts::isEmpty() const
{
  return content_.empty();
}

lysenko::Contacts::constIterator lysenko::Contacts::getBegin() const
{
  return content_.begin();
}

lysenko::Contacts::constIterator lysenko::Contacts::getEnd() const
{
  return content_.end();
}

void lysenko::Contacts::insert(constIterator curr, const Note& newNote, bool before)
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
      constIterator nextOne = ++curr;
      content_.insert(nextOne, newNote);
    }
  }
}

void lysenko::Contacts::deleteNote(constIterator curr)
{
  content_.erase(curr);
}

void lysenko::Contacts::pushBack(Note& newNote)
{
  content_.push_back(newNote);
}

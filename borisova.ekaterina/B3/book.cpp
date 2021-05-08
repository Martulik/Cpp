#include "book.hpp"
#include <iostream>
#include "note.hpp"

namespace lab = borisova;
void lab::Book::viewCurrent(iterator iter, std::ostream& out)
{
  out << *iter;
}

lab::Book::iterator lab::Book::insertAfter(iterator iter, Note& src)
{
  iter++;
  phoneBook_.insert(iter, src);
  return iter;
}

lab::Book::iterator lab::Book::insertBefore(iterator iter, Note& src)
{
  phoneBook_.insert(iter, src);
  return iter;
}

void lab::Book::insertBack(Note& src)
{
  phoneBook_.push_back(src);
}

void lab::Book::deleteNote(iterator iter)
{
  phoneBook_.erase(iter);
}

bool lab::Book::empty() const
{
  return phoneBook_.empty();
}

lab::Book::iterator lab::Book::begin()
{
  return phoneBook_.begin();
}

lab::Book::iterator lab::Book::end()
{
  return phoneBook_.end();
}

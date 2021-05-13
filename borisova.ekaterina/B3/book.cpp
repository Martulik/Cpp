#include "book.hpp"
#include "note.hpp"

namespace lab = borisova;

lab::Book::constItr lab::Book::insertAfter(constItr iter, const Note& src)
{
  iter++;
  phoneBook_.insert(iter, src);
  return iter;
}

lab::Book::constItr lab::Book::insertBefore(constItr iter, const Note& src)
{
  phoneBook_.insert(iter, src);
  return iter;
}

void lab::Book::insertBack(const Note& src)
{
  phoneBook_.push_back(src);
}

void lab::Book::deleteNote(constItr iter)
{
  phoneBook_.erase(iter);
}

bool lab::Book::empty() const
{
  return phoneBook_.empty();
}

lab::Book::constItr lab::Book::begin() const
{
  return phoneBook_.begin();
}

lab::Book::constItr lab::Book::end() const
{
  return phoneBook_.end();
}

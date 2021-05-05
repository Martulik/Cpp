#include "book.hpp"
#include <iostream>
#include "tools.hpp"

namespace lab = borisova;
using iterator = std::list< lab::Note >::iterator;

void lab::Book::viewCurrent(iterator iter)
{
  if (iter != end())
  {
    std::cout << iter->number_ << " "<< iter->name_ << "\n";
  }
}

iterator lab::Book::nextNote(iterator iter)
{
  return ++iter;
}

iterator lab::Book::prevNote(iterator iter)
{
  return --iter;
}

iterator lab::Book::insertAfter(iterator iter, Note& src)
{
  iter++;
  phoneBook_.insert(iter, src);
  return iter;
}

iterator lab::Book::insertBefore(iterator iter, Note& src)
{
  phoneBook_.insert(iter, src);
  return iter;
}

iterator lab::Book::rewriteCurrent(iterator iter, Note& src)
{
  *iter = src;
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

iterator lab::Book::cross(iterator iter, int n)
{
  advance(iter, n);
  return iter;
}

bool lab::Book::empty()
{
  return phoneBook_.empty();
}

iterator lab::Book::begin()
{
  return phoneBook_.begin();
}

iterator lab::Book::end()
{
  return phoneBook_.end();
}

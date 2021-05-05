#include "interface.hpp"
#include <iostream>
#include <list>
#include <map>
#include "tools.hpp"

namespace lab = borisova;
using itr = std::map<std::string, lab::Book::iterator>::iterator;

lab::Interface::Interface()
{
  notes_["current"] = phoneNotes_.begin();
}

void lab::Interface::add(Note& src)
{
  phoneNotes_.insertBack(src);
  if (std::next(phoneNotes_.begin()) == phoneNotes_.end())
  {
    notes_["current"] = phoneNotes_.begin();
  }
}

void lab::Interface::store(std::string& oldMark, std::string& newMark)
{
  itr iter = notes_.find(oldMark);
  if (iter == notes_.end())
  {
    std::cout << lab::invalidBookMark;
  }
  else
  {
    notes_[newMark] = iter->second;
  }
}

void lab::Interface::insertBefore(std::string& bookMark, Note& src)
{
  itr iter = notes_.find(bookMark);
  if (iter == notes_.end())
  {
    std::cout << lab::invalidBookMark;
    return;
  }
  if (iter->second == phoneNotes_.end())
  {
    add(src);
  }
  phoneNotes_.insertBefore(iter->second, src);
}

void lab::Interface::insertAfter(std::string& bookMark, Note& src)
{
  itr iter = notes_.find(bookMark);
  if (iter == notes_.end())
  {
    std::cout << lab::invalidBookMark;
    return;
  }
  if (iter->second == phoneNotes_.end())
  {
    add(src);
  }
  phoneNotes_.insertAfter(iter->second, src);
}

void lab::Interface::deleteMark(std::string& bookMark)
{
  itr iter = notes_.find(bookMark);
  if (iter != notes_.end())
  {
    Book::iterator delIter = iter->second;
    for (itr i = notes_.begin(); i != notes_.end(); ++i)
    {
      if (i->second == delIter)
      {
        if (std::next(i->second) == phoneNotes_.end())
        {
          i->second = std::prev(delIter);
        }
        else
        {
          i->second = std::next(delIter);
        }
      }
    }

    if (iter->second == phoneNotes_.end())
    {
      std::cout << lab::empty;
    }
    phoneNotes_.deleteNote(delIter);
  }

}

void lab::Interface::show(std::string& bookMark)
{
  itr iteratr = notes_.find(bookMark);
  if (iteratr != notes_.end())
  {
    if (phoneNotes_.empty())
    {
      std::cout << lab::empty;
    }
    else
    {
      phoneNotes_.viewCurrent(iteratr->second);
    }
  }
}

void lab::Interface::move(std::string& bookmark, int n)
{
  itr iter = notes_.find(bookmark);
  if (iter == notes_.end())
  {
    std::cout << lab::invalidBookMark;
  }
  else
  {
    iter->second = phoneNotes_.cross(iter->second, n);
  }
}

void lab::Interface::move(std::string& bookmark, std::string step)
{
  itr iter = notes_.find(bookmark);
  if (iter == notes_.end())
  {
    std::cout << lab::invalidBookMark;
  }
  else
  {
    if (step == "first")
    {
      iter->second = phoneNotes_.begin();
    }
    else if (step == "last")
    {
      iter->second = --phoneNotes_.end();
    }
  }
}

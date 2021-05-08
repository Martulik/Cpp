#include "interface.hpp"
#include <iostream>
#include <list>
#include <map>
#include "book.hpp"
#include "note.hpp"

namespace lab = borisova;

lab::Interface::Interface()
{
  notes_["current"] = phoneNotes_.begin();
}

void lab::Interface::add(const Note& src)
{
  phoneNotes_.insertBack(src);
  if (std::next(phoneNotes_.begin()) == phoneNotes_.end())
  {
    notes_["current"] = phoneNotes_.begin();
  }
}

void lab::Interface::store(const std::string& oldMark, const std::string& newMark, std::ostream& out)
{
  itr iter = notes_.find(oldMark);
  if (iter == notes_.end())
  {
    lab::invalidBookMark(out);
  }
  else
  {
    notes_[newMark] = iter->second;
  }
}

void lab::Interface::insertBefore(const std::string& bookMark, const Note& src, std::ostream& out)
{
  itr iter = notes_.find(bookMark);
  if (iter == notes_.end())
  {
    lab::invalidBookMark(out);
    return;
  }
  if (iter->second == phoneNotes_.end())
  {
    add(src);
  }
  phoneNotes_.insertBefore(iter->second, src);
}

void lab::Interface::insertAfter(const std::string& bookMark, const Note& src, std::ostream& out)
{
  itr iter = notes_.find(bookMark);
  if (iter == notes_.end())
  {
    lab::invalidBookMark(out);
    return;
  }
  if (iter->second == phoneNotes_.end())
  {
    add(src);
  }
  phoneNotes_.insertAfter(iter->second, src);
}

void lab::Interface::deleteMark(const std::string& bookMark)
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
    phoneNotes_.deleteNote(delIter);
  }

}

void lab::Interface::show(const std::string& bookMark, std::ostream& out)
{
  itr iteratr = notes_.find(bookMark);
  if (iteratr != notes_.end())
  {
    if (phoneNotes_.empty())
    {
      lab::empty(out);
    }
    else
    {
      phoneNotes_.viewCurrent(iteratr->second, out);
    }
  }
  else
  {
    lab::invalidBookMark(out);
  }
}

void lab::Interface::move(const std::string& bookmark, const int n, std::ostream& out)
{
  itr iter = notes_.find(bookmark);
  if (iter == notes_.end())
  {
    lab::invalidBookMark(out);
  }
  else
  {
    std::advance(iter->second, n);
  }
}

void lab::Interface::move(const std::string& bookmark, const std::string step, std::ostream& out)
{
  itr iter = notes_.find(bookmark);
  if (iter == notes_.end())
  {
    lab::invalidBookMark(out);
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

void lab::invalidCommand(std::ostream& out)
{
  out << "<INVALID COMMAND>\n";
}

void lab::invalidBookMark(std::ostream& out)
{
  out << "<INVALID BOOKMARK>\n";
}

void lab::invalidStep(std::ostream& out)
{
  out << "<INVALID STEP>\n";
}

void lab::empty(std::ostream& out)
{
  out << "<EMPTY>\n";
}

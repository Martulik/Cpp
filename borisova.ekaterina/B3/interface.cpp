#include "interface.hpp"
#include <cassert>
#include <list>
#include <map>
#include "book.hpp"
#include "note.hpp"

namespace lab = borisova;

lab::Interface::Interface():
  phoneNotes_(),
  notes_({ { "current", phoneNotes_.begin() } })
{
}

void lab::Interface::add(const Note& src)
{
  phoneNotes_.insertBack(src);
  if (std::next(phoneNotes_.begin()) == phoneNotes_.end())
  {
    notes_["current"] = phoneNotes_.begin();
  }
}

void lab::Interface::store(const std::string& oldMark, const std::string& newMark)
{
  auto iter = notes_.find(oldMark);
  assert(iter != notes_.end());
  notes_[newMark] = iter->second;
}

void lab::Interface::insertBefore(const std::string& bookMark, const Note& src)
{
  auto iter = notes_.find(bookMark);
  assert(iter != notes_.end());
  if (iter->second == phoneNotes_.end())
  {
    add(src);
  }
  phoneNotes_.insertBefore(iter->second, src);
}

void lab::Interface::insertAfter(const std::string& bookMark, const Note& src)
{
  auto iter = notes_.find(bookMark);
  assert(iter != notes_.end());
  if (iter->second == phoneNotes_.end())
  {
    add(src);
  }
  phoneNotes_.insertAfter(iter->second, src);
}

void lab::Interface::deleteMark(const std::string& bookMark)
{
  auto iter = notes_.find(bookMark);
  if (iter != notes_.end())
  {
    Book::constItr delIter = iter->second;
    for (auto i = notes_.begin(); i != notes_.end(); ++i)
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

void lab::Interface::move(const std::string& bookmark, const int n)
{
  auto iter = notes_.find(bookmark);
  assert(iter != notes_.end());
  std::advance(iter->second, n);
}

void lab::Interface::move(const std::string& bookmark, const std::string step)
{
  auto iter = notes_.find(bookmark);
  assert(iter != notes_.end());
  if (step == "first")
  {
    iter->second = phoneNotes_.begin();
  }
  else if (step == "last")
  {
    iter->second = std::prev(phoneNotes_.end());
  }
}

lab::Interface::constItr lab::Interface::findMark(const std::string mark) const
{
  return notes_.find(mark);
}

lab::Interface::constItr lab::Interface::getEnd() const
{
  return notes_.end();
}

bool lab::Interface::isEmpty()
{
  return phoneNotes_.empty();
}

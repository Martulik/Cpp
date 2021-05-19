#include "phonebook_interface.hpp"
#include <iostream>

lebedeva::Interface::Interface():
  book_()
{
  bookmarks_["current"] = book_.begin();
}

void lebedeva::Interface::add(const record_t& rec)
{
  book_.pushBack(rec);
  if (std::next(book_.begin()) == book_.end())
  {
    bookmarks_["current"] = book_.begin();
  }
}

void lebedeva::Interface::store(const std::string& markName, const std::string& newMarkName)
{
  Iter iter = bookmarks_.find(markName);
  if (iter != bookmarks_.end())
  {
    bookmarks_[newMarkName] = iter->second;
  }
}

void lebedeva::Interface::insert(Where pos, const std::string& markName, record_t& rec)
{
  Iter iter = bookmarks_.find(markName);
  if (iter != bookmarks_.end())
  {
    if (iter->second == book_.end())
    {
      add(rec);
    }
    if (pos == Where::before)
    {
      book_.insertBefore(iter->second, rec);
    }
    if (pos == Where::after)
    {
      book_.insertAfter(iter->second, rec);
    }
  }
}

void lebedeva::Interface::deleteRec(const std::string& markName)
{
  Iter iter = bookmarks_.find(markName);
  if (iter != bookmarks_.end())
  {
    PhoneBook::constIter del = iter->second;
    for (Iter i = bookmarks_.begin(); i != bookmarks_.end(); i++)
    {
      if (i->second == del)
      {
        if (std::next(i->second) == book_.end())
        {
          i->second = std::prev(del);
        }
        else
        {
          i->second = std::next(del);
        }
      }
    }
    book_.deleteRec(del);
  }
}

void lebedeva::Interface::show(const std::string& markName, std::ostream& out)
{
  Iter iter = bookmarks_.find(markName);
  if (iter->second == book_.end())
  {
    out << "<EMPTY>";
  }
  else
  {
    out << *(iter->second);
  }
}

void lebedeva::Interface::move(const std::string& markName, int steps)
{
  Iter iter = bookmarks_.find(markName);
  if (iter != bookmarks_.end())
  {
    std::advance(iter->second, steps);
  }
}

void lebedeva::Interface::move(const std::string& markName, Steps steps)
{
  Iter iter = bookmarks_.find(markName);
  if (iter != bookmarks_.end())
  {
    if (steps == Steps::first)
    {
      iter->second = book_.begin();
    }
    if (steps == Steps::last)
    {
      iter->second = std::prev(book_.end());
    }
  }
}

lebedeva::Interface::constIter lebedeva::Interface::find(const std::string& markName) const
{
  return bookmarks_.find(markName);
}

lebedeva::Interface::constIter lebedeva::Interface::begin() const
{
  return bookmarks_.begin();
}

lebedeva::Interface::constIter lebedeva::Interface::end() const
{
  return bookmarks_.end();
}

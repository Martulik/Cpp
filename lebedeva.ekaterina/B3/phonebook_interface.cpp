#include "phonebook_interface.hpp"
#include <iostream>
#include <algorithm>

lebedeva::Interface::Interface():
  book_(),
  bookmarks_({ { "current", book_.begin() }})
{}

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

void lebedeva::Interface::insert(Where pos, const std::string& markName, const record_t& rec)
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
    if (book_.size() > 1)
    {
      std::for_each(bookmarks_.begin(), bookmarks_.end(),
        [del, this] (BookmarkMap::value_type& bookmark)
        {
          if (bookmark.second == del)
          {
            PhoneBook::constIter next = std::next(bookmark.second);
            if (next == book_.end())
            {
              bookmark.second = std::prev(del);
            }
            else
            {
              bookmark.second = std::next(del);
            }
          }
        }
      );
      book_.deleteRec(del);
    }
    else
    {
      book_.deleteRec(del);
      bookmarks_["current"] = book_.begin();
    }
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

bool lebedeva::Interface::empty() const
{
  return book_.empty();
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

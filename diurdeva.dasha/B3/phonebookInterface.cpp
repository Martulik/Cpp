#include "phonebookInterface.hpp"

#include <algorithm>
#include <iostream>

diurdeva::PhonebookManager::PhonebookManager() {
  bookmarks_["current"] = records_.begin();
}

void diurdeva::PhonebookManager::add(const Phonebook::record_t& rec)
{
  records_.pushBack(rec);
  if (std::next(records_.begin()) == records_.end()) {
    bookmarks_["current"] = records_.begin();
  }
}

void diurdeva::PhonebookManager::store(const std::string& bookmark, const std::string& newBookmark)
{
  auto iter = getBookmarkIterator(bookmark);
  if (iter != bookmarks_.end())
  {
    bookmarks_.emplace(newBookmark, iter->second);
  }
}

void diurdeva::PhonebookManager::insert(InsertPosition position, const std::string& bookmark, const Phonebook::record_t& rec)
{
  auto iter = getBookmarkIterator(bookmark);

  if (iter != bookmarks_.end())
  {
    if (iter->second == records_.end())
    {
      add(rec);
    }

    if (position == InsertPosition::AFTER)
    {
      records_.insert(std::next(iter->second), rec);
    }
    else
    {
      records_.insert(iter->second, rec);
    }
  }
}

void diurdeva::PhonebookManager::deleteNote(const std::string& bookmark)
{
  auto iter = getBookmarkIterator(bookmark);

  if (iter != bookmarks_.end())
  {
    auto eraseIter = iter->second;
    for (auto i = bookmarks_.begin(); i != bookmarks_.end(); ++i)
    {
      if (i->second == eraseIter)
      {
        if (std::next(i->second) == records_.end())
        {
          i->second = std::prev(eraseIter);
        }
        else
        {
          i->second = std::next(eraseIter);
        }
      }
    }
    records_.remove(eraseIter);
  }
}

void diurdeva::PhonebookManager::show(const std::string& bookmark)
{
  auto iter = getBookmarkIterator(bookmark);

  if (iter != bookmarks_.end())
  {
    if (records_.empty())
    {
      std::cout << "<EMPTY>" << std::endl;
      return;
    }
    records_.view(iter->second);
  }
}

void diurdeva::PhonebookManager::move(const std::string& bookmark, int n)
{
  auto iter = getBookmarkIterator(bookmark);

  if (iter != bookmarks_.end())
  {
    iter->second = records_.move(iter->second, n);
  }
}

void diurdeva::PhonebookManager::move(const std::string& bookmark, MovePosition loc)
{
  auto iter = getBookmarkIterator(bookmark);

  if (iter != bookmarks_.end())
  {
    if (loc == MovePosition::FIRST)
    {
      iter->second = records_.begin();
    }

    if (loc == MovePosition::LAST)
    {
      iter->second = records_.prev(records_.end());
    }
  }
}

diurdeva::PhonebookManager::bookmarks::iterator  diurdeva::PhonebookManager::getBookmarkIterator(const std::string& bookmark)
{
  auto iter = bookmarks_.find(bookmark);

  if (iter != bookmarks_.end())
  {
    return iter;
  }
  else
  {
    std::cout << "<INVALID BOOKMARK>" << std::endl;
    return bookmarks_.end();
  }
}

#include "bookmarks.hpp"
#include <algorithm>
#include "commands.hpp"

namespace iva = ivanova;
using iterator = std::map< std::string, iva::PhoneBook::iter >::iterator;

iva::Bookmarks::Bookmarks():
  phoneBook_(),
  bookmarks_({{"current", phoneBook_.begin()}})
{
}

void iva::Bookmarks::add(const iva::Record &record)
{
  if (!isEmpty())
  {
    phoneBook_.add(record);
  }
  else
  {
    phoneBook_.add(record);
    bookmarks_["current"] = phoneBook_.begin();
  }
}

void iva::Bookmarks::store(const iva::Record &data)
{
  iterator iter = bookmarks_.find(data.data.first);
  if (iter != bookmarks_.end())
  {
    bookmarks_.emplace(data.data.second, iter->second);
  }
}

void iva::Bookmarks::insert(const iva::Record &rec, Bookmarks::InsertType dir, const std::string &markName)
{
  iterator iter = bookmarks_.find(markName);
  if (iter != bookmarks_.end())
  {
    if (iter->second == phoneBook_.end())
    {
      add(rec);
    }
    if (dir == InsertType::BEFORE)
    {
      phoneBook_.insert(iter->second, rec);
    }
    if (dir == InsertType::AFTER)
    {
      phoneBook_.insert(std::next(iter->second), rec);
      bookmarks_.emplace(rec.data.first, std::next(iter->second));
    }
  }
}

void iva::Bookmarks::deleteMark(const std::string &markName)
{
  iterator iter = bookmarks_.find(markName);
  if (iter != bookmarks_.end())
  {
    auto tempIter = iter->second;
    auto bookmark = bookmarks_.begin();
    while (bookmark != bookmarks_.end())
    {
      if (bookmark->second == tempIter)
      {
        if (std::next(bookmark->second) == phoneBook_.end())
        {
          bookmark->second = std::prev(tempIter);
        }
        else
        {
          bookmark->second = std::next(tempIter);
        }
      }
      bookmark++;
    }
    phoneBook_.erase(tempIter);
  }
}

void iva::Bookmarks::move(const std::string &markName, Bookmarks::positionMove position)
{
  iterator it = bookmarks_.find(markName);
  if (it == bookmarks_.end())
  {
    invalidCommand(std::cout);
  }
  else if (position == positionMove::FIRST)
  {
    it->second = phoneBook_.begin();
  }
  else if (position == positionMove::LAST)
  {
    it->second = --phoneBook_.end();
  }
}

void iva::Bookmarks::move(const std::string &markName, int step)
{
  iterator iter = bookmarks_.find(markName);
  if (iter == bookmarks_.end())
  {
    invalidCommand(std::cout);
  }
  else
  {
    iter->second = phoneBook_.moveOnStep(iter->second, step);
  }
}

bool iva::Bookmarks::isEmpty()
{
  return phoneBook_.isEmpty();
}

bool ivanova::Bookmarks::findMark(const std::string &name) const
{
  return bookmarks_.find(name) == bookmarks_.end() ? false: true;
}

ivanova::Bookmarks::iter ivanova::Bookmarks::getMark(const std::string &name) const
{
    return bookmarks_.find(name);
}

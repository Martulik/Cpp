#include <algorithm>
#include "bookmarks.hpp"

namespace iva = ivanova;
using iterator = std::map< std::string, iva::PhoneBook::iter >::iterator;

iva::Bookmarks::Bookmarks()
{
  bookmarks_["current"] = phoneBook_.begin();
}

void iva::Bookmarks::add(const ivanova::Record &record)
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

void iva::Bookmarks::store(const std::pair < std::string, std::string > &data)
{
  iterator iter = bookmarks_.find(data.first);
  if (iter != bookmarks_.end())
  {
    bookmarks_.emplace(data.second, iter->second);
  }
}

void iva::Bookmarks::insert(Bookmarks::InsertType dir, const std::string &markName, const iva::Record &rec)
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

void iva::Bookmarks::show(const std::string &markName)
{
  iterator iter = bookmarks_.find(markName);
  if (iter == bookmarks_.end())
  {
    std::cerr << "<INVALID BOOKMARK>\n";
    return;
  }
  if (phoneBook_.isEmpty())
  {
    std::cout << "<EMPTY>\n";
    return;
  }
  std::cout << *iter->second;
}

void iva::Bookmarks::move(const std::string &markName, Bookmarks::positionMove position)
{
  iterator it = bookmarks_.find(markName);
  if (it == bookmarks_.end())
  {
    std::cerr << "<INVALID COMMAND>\n";
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
    std::cerr << "<INVALID COMMAND>\n";
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

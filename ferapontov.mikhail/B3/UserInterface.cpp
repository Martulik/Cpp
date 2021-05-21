#include "UserInterface.hpp"
#include <stdexcept>

namespace fer = ferapontov;
fer::Interface::Interface():
  book_(PhoneBook()),
  bookmarks_({std::make_pair("current", book_.begin())})
{
}

void fer::Interface::add(const data_t& note)
{
  book_.pushBack(note);
  if (book_.size() == 1)
  {
    bookmarks_["current"] = book_.begin();
  }
}

void fer::Interface::store(const std::string& firstMark, const std::string& secondMark)
{
  checkBookMark(firstMark);
  bookmarks_.insert(std::make_pair(secondMark, bookmarks_[firstMark]));
}

void fer::Interface::insertNote(const std::string& mode, const std::string& markName, const data_t& note)
{
  if (book_.empty())
  {
    add(note);
    return;
  }
  if (mode == "before")
  {
    book_.insertPrev(bookmarks_.find(markName)->second, note);
  }
  else if (mode == "after")
  {
    book_.insertNext(bookmarks_.find(markName)->second, note);
  }
}

fer::data_t fer::Interface::show(const std::string& markName)
{
  checkBookMark(markName);
  if (book_.empty())
  {
    throw std::invalid_argument("<EMPTY>");
  }
  const_map_iter it = bookmarks_.find(markName);
  return *it->second;
}

void fer::Interface::deleteNote(const std::string& markName)
{
  checkBookMark(markName);
  fer::const_iter oldValue = bookmarks_[markName];
  fer::const_iter newValue = book_.deletNote(bookmarks_[markName]);
  if (newValue == book_.end())
  {
    newValue = book_.begin();
  }
  for (map_iter i = bookmarks_.begin(); i != bookmarks_.end(); i++)
  {
    if (i->second == oldValue)
    {
      i->second = newValue;
    }
  }
}

void fer::Interface::move(const std::string& markName, const std::string& steps)
{
  checkBookMark(markName);
  if (steps == "last")
  {
    bookmarks_[markName] = book_.move( bookmarks_[markName], book_.size());
  }
  else if (steps == "first")
  {
    bookmarks_[markName] = book_.move( bookmarks_[markName], -1 * book_.size());
  }
  else
  {
    bookmarks_[markName] = book_.move(bookmarks_[markName], std::stoi(steps));
  }
}

void fer::Interface::checkBookMark(const std::string& name) const
{
  if (bookmarks_.find(name) == bookmarks_.end())
  {
    throw std::invalid_argument("<INVALID BOOKMARK>");
  }
}

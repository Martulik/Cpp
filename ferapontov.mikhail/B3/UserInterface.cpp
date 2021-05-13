#include "userInterface.hpp"

namespace fer = ferapontov;
fer::Interface::Interface()
{
  bookmarks_.insert(std::make_pair("current", book_.begin()));
}

void fer::Interface::add(std::string& name, int number)
{
  book_.pushBack({name, number});
}

void fer::Interface::show(std::ostream& out, std::string& markName)
{
  checkBookMark(markName);
  if (bookmarks_.empty())
  {
    throw std::invalid_argument("EMPTY");
  }
  data_t& note = book_.showCurrent(bookmarks_[markName]);
  out << note;
}

void fer::Interface::checkBookMark(std::string& name) const
{
  if (bookmarks_.find(name) == bookmarks_.end())
  {
    throw std::invalid_argument("INVALID BOOKMARK");
  }
}
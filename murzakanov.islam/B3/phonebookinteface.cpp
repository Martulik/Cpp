#include "phonebookinteface.hpp"

#include <map>
#include <string>
#include <memory>

#include "phone-book.hpp"
#include "tools.hpp"
#include "note.hpp"

murzakanov::BookInterface::BookInterface(PhoneBook& book):
  book_(std::make_unique< PhoneBook >(book))
{
  bookmarks_.insert(std::make_pair("current", book_->begin()));
}

void murzakanov::BookInterface::add(const note_t& note)
{
  book_->push_back(note);
  if (bookmarks_.size() == 1)
  {
    bookmarks_["current"] = book_->begin();
  }
}

void murzakanov::BookInterface::store(const std::string& bookmark, const std::string& newBookmark)
{
  iteratorType it = bookmarks_.find(bookmark);
  bookmarks_.insert(std::make_pair(newBookmark, it->second));
}

void murzakanov::BookInterface::insertBefore(const std::string& bookmark, const note_t& note)
{
  if (bookmark == "current" && book_->isEmpty())
  {
    add(note);
    return;
  }
  iteratorType it = bookmarks_.find(bookmark);
  book_->insertBefore(it->second, note);
}

void murzakanov::BookInterface::insertAfter(const std::string& bookmark, const note_t& note)
{
  if (bookmark == "current" && book_->isEmpty())
  {
    add(note);
    return;
  }
  iteratorType it = bookmarks_.find(bookmark);
  book_->insertAfter(it->second, note);
}

void murzakanov::BookInterface::deleteNote(const std::string& bookmark)
{
  iteratorType it = bookmarks_.find(bookmark);
  auto tempIt = it->second;
  iteratorType current = bookmarks_.begin();
  while (current != bookmarks_.end())
  {
    if (current->second == tempIt)
    {
      if (std::next(current->second) == book_->end())
      {
        current->second = book_->begin();
      }
      else
      {
        ++current->second;
      }
    }
    current++;
  }
  book_->deleteNote(tempIt);
}

murzakanov::note_t murzakanov::BookInterface::show(const std::string& bookmark) const
{
  constIteratorType it = bookmarks_.find(bookmark);
  return *it->second;
}

void murzakanov::BookInterface::move(const std::string& bookmark, int steps)
{
  iteratorType it = bookmarks_.find(bookmark);
  int distance = 0;
  if (steps > 0)
  {
    distance = std::distance(it->second, book_->end());
    if (steps >= distance)
    {
      it->second = std::prev(book_->end());
      return;
    }
  }
  else
  {
    distance = std::distance(book_->begin(), it->second);
    if (std::abs(steps) >= distance)
    {
      it->second = book_->begin();
      return;
    }
  }
  std::advance(it->second, steps);
}

void murzakanov::BookInterface::move(const std::string& bookmark, const std::string& keyWord)
{
  iteratorType it = bookmarks_.find(bookmark);
  if (keyWord == "first")
  {
    it->second = book_->begin();
  }
  else if (keyWord == "last")
  {
    if (book_->isEmpty())
    {
      it->second = book_->end();
    }
    else
    {
      it->second = std::prev(book_->end());
    }
  }
}

bool murzakanov::BookInterface::contains(const std::string& bookmark) const
{
  return (bookmarks_.find(bookmark) != bookmarks_.end());
}

bool murzakanov::BookInterface::empty() const
{
  return (book_->isEmpty());
}

#include "phone-book-interface.hpp"

#include <ostream>

#include "phone-book.hpp"

razukrantov::PhoneBookInterface::PhoneBookInterface(PhoneBook& book):
  book_(std::make_unique< PhoneBook >(book))
{
  bookmarks_.insert(std::make_pair("current", book_->begin()));
}

void razukrantov::PhoneBookInterface::add(const note_t& note)
{
  book_->pushBack(note);
  if (bookmarks_.size() == 1)
  {
    bookmarks_["current"] = book_->begin();
  }
}

bool razukrantov::PhoneBookInterface::empty() const
{
  return book_->empty();
}

bool razukrantov::PhoneBookInterface::contains(const std::string& bookmark) const
{
  return (bookmarks_.find(bookmark) != bookmarks_.end());
}

void razukrantov::PhoneBookInterface::store(const std::string& bookmark, const std::string& newBookmark)
{
  iteratorType iterator = bookmarks_.find(bookmark);
  bookmarks_.insert(std::make_pair(newBookmark, iterator->second));
}

void razukrantov::PhoneBookInterface::insertBefore(const std::string& bookmark, const note_t& note)
{
  if (book_->empty())
  {
    add(note);
  }
  else
  {
    iteratorType iterator = bookmarks_.find(bookmark);
    book_->insertBefore(iterator->second, note);
  }
}

void razukrantov::PhoneBookInterface::insertAfter(const std::string& bookmark, const note_t& note)
{
  if (book_->empty())
  {
    add(note);
  }
  else
  {
    iteratorType iterator = bookmarks_.find(bookmark);
    book_->insertAfter(iterator->second, note);
  }
}

void razukrantov::PhoneBookInterface::erase(const std::string& bookmark)
{
  iteratorType iterator = bookmarks_.find(bookmark);
  auto temp = iterator->second;
  iteratorType i = bookmarks_.begin();
  while (i != bookmarks_.end())
  {
    if (i->second == temp)
    {
      if (std::next(i->second) == book_->end())
      {
        i->second = book_->begin();
      }
      else
      {
        i->second = std::next(i->second);
      }
    }
    i = std::next(i);
  }
  book_->erase(temp);
}

void razukrantov::PhoneBookInterface::show(const std::string& bookmark, std::ostream& out) const
{
  constIterType iterator = bookmarks_.find(bookmark);
  out << *iterator->second;
}

void razukrantov::PhoneBookInterface::move(const std::string& bookmark, const std::string& steps)
{
  iteratorType iterator = bookmarks_.find(bookmark);
  if (steps == "first")
  {
    iterator->second = book_->begin();
  }
  else if (steps == "last")
  {
    if (book_->empty())
    {
      iterator->second = book_->end();
    }
    else
    {
      iterator->second = std::prev(book_->end());
    }
  }
}

void razukrantov::PhoneBookInterface::move(const std::string& bookmark, const int steps)
{
  iteratorType iterator = bookmarks_.find(bookmark);
  iterator->second = book_->move(iterator->second, steps);
}

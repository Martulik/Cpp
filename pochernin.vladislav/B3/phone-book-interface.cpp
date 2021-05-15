#include "phone-book-interface.hpp"

#include "phone-book.hpp"

using PBI = pochernin::PhoneBookInterface;

PBI::PhoneBookInterface(PhoneBook& book):
  book_(std::make_unique < PhoneBook >(book))
{
  bookmarks_.insert(std::make_pair< std::string, PBI::constIterator >("current", book_->begin()));
}

void PBI::add(const Note& note)
{
  book_->add(note);
  if (bookmarks_.size() == 1)
  {
    bookmarks_.at("current") = book_->begin();
  }
}

bool PBI::empty() const
{
  return book_->empty();
}

bool PBI::contains(const Bookmark& bookmark) const
{
  return (bookmarks_.find(bookmark.name) != bookmarks_.end());
}

void PBI::show(const Bookmark& bookmark, std::ostream& out) const
{
  out << *(bookmarks_.at(bookmark.name));
}

void PBI::insertBefore(const Bookmark& bookmark, const Note& note)
{
  if (book_->empty())
  {
    add(note);
  }
  else
  {
    book_->insertBefore(bookmarks_.at(bookmark.name), note);
  }
}

void PBI::insertAfter(const Bookmark& bookmark, const Note& note)
{
  if (book_->empty())
  {
    add(note);
  }
  else
  {
    book_->insertAfter(bookmarks_.at(bookmark.name), note);
  }
}

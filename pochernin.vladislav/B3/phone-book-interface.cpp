#include "phone-book-interface.hpp"

#include "phone-book.hpp"

using PBI = pochernin::PhoneBookInterface;

PBI::PhoneBookInterface(PhoneBook& book):
  book_(std::make_unique < PhoneBook >(book))
{
  bookmarks_.insert(std::make_pair< Bookmark, PBI::constIterator >({"current"}, book_->begin()));
}

void PBI::add(const Note& note)
{
  book_->add(note);
  if (bookmarks_.size() == 1)
  {
    bookmarks_.at({"current"}) = book_->begin();
  }
}

bool PBI::empty() const
{
  return book_->empty();
}

bool PBI::contains(const Bookmark& bookmark) const
{
  return (bookmarks_.find(bookmark) != bookmarks_.end());
}

void PBI::show(const Bookmark& bookmark, std::ostream& out) const
{
  out << *(bookmarks_.at(bookmark));
}

void PBI::insertBefore(const Bookmark& bookmark, const Note& note)
{
  if (book_->empty())
  {
    add(note);
  }
  else
  {
    book_->insertBefore(bookmarks_.at(bookmark), note);
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
    book_->insertAfter(bookmarks_.at(bookmark), note);
  }
}

void PBI::store(const Bookmark& bookmark, const Bookmark& newBookmark)
{
  constIterator iterator = bookmarks_.at(bookmark);
  bookmarks_.insert(std::make_pair(newBookmark, iterator));
}

void PBI::move (const Bookmark& bookmark, const Step& step)
{
  constIterator iterator = bookmarks_.at(bookmark);
  if (step.isFirst)
  {
    iterator = book_->begin();
  }
  else if (step.isLast)
  {
    if (book_->empty())
    {
      iterator = book_->end();
    }
    else
    {
      iterator = book_->end();
      iterator--;
    }
  }
  else if (step.isSpecific)
  {
    std::advance(iterator, step.steps);
  }
}

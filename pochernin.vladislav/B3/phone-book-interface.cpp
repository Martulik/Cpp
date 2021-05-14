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
}

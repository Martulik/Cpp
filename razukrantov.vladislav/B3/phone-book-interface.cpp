#include "phone-book-interface.hpp"

#include <ostream>

#include "phone-book.hpp"

razukrantov::PhoneBookInterface::PhoneBookInterface(PhoneBook& book) :
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

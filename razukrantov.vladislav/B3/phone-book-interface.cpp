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

void razukrantov::PhoneBookInterface::store(const std::string& bookMark, const std::string& newBookMark)
{

}

void razukrantov::PhoneBookInterface::insertBefore(const std::string& bookMark, const note_t& note)
{
	if (bookMark == "current" && book_->empty())
	{
		add(note);
		return;
	}
	book_.add
}

void razukrantov::PhoneBookInterface::insertAfter(const std::string& bookMark, const note_t& note)
{
	if (bookMark == "current" && book_->empty())
	{
		add(note);
		return;
	}
}

void razukrantov::PhoneBookInterface::erase(const std::string& bookMark)
{
	iteratorType iterator = bookmarks_.find(bookMark);
	if (iterator != bookmarks_.end())
	{
		iteratorType temp = iterator;
		iteratorType i = bookmarks_.begin();
		while (i != bookmarks_.end())
		{
			if (i->second == temp->second)
			{
				if (std::next(i->second) == book_->end())
				{
					i->second = book_->begin();
				}
				else 
				{
					i->second = std::next(temp->second);
				}
			}
			i++;
		}
		book_->erase(temp->second);
	}
}

void razukrantov::PhoneBookInterface::show(const std::string& bookMark, std::ostream& out)
{
	iteratorType iterator = bookmarks_.find(bookMark);
	return *iterator->second;
}

void razukrantov::PhoneBookInterface::move(const std::string& bookMark, const std::string& steps)
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
			iterator->second = book->end();
		}
		else
		{
			iterator->second = std::prev(book_->end());
		}
	}
	//else if 
}

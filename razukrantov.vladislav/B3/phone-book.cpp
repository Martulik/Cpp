#include "phone-book.hpp"

void razukrantov::PhoneBook::insertAfter(constIterator iterator, const note_t& note)
{
	constIterator temp = std::next(iterator);
	if (temp == end())
	{
		pushBack(note);
	}
	else
	{
		recordings_.insert(temp, note);
	}
}

void razukrantov::PhoneBook::insertBefore(constIterator iterator, const note_t& note)
{
	recordings_.insert(iterator, note);
}

void razukrantov::PhoneBook::pushBack(const note_t& note)
{
	recordings_.push_back(note);
}

razukrantov::PhoneBook::constIterator razukrantov::PhoneBook::move(razukrantov::PhoneBook::constIterator iterator, int steps) const
{
	if (steps > 0)
	{
		while (std::next(iterator) != recordings_.end() && steps != 0)
		{
			iterator = std::next(iterator);
			--steps;
		}
	}
	else
	{
		while (iterator != recordings_.begin() && (steps != 0))
		{
			iterator = std::prev(iterator);
			--steps;
		}
	}
	return iterator;
}

void razukrantov::PhoneBook::erase(constIterator iterator)
{
	recordings_.erase(iterator);
}

size_t razukrantov::PhoneBook::size() const
{
	return recordings_.size();
}

bool razukrantov::PhoneBook::empty() const
{
	return recordings_.empty();
}

razukrantov::PhoneBook::constIterator razukrantov::PhoneBook::begin()
{
	return recordings_.cbegin();
}

razukrantov::PhoneBook::constIterator razukrantov::PhoneBook::end()
{
	return recordings_.cend();
}

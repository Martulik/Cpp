#include "phone-book.hpp"

void razukrantov::PhoneBook::show(std::ostream& out, iterator iterator) const
{
	out  << iterator->number << " " << iterator->name << "\n";
}

void razukrantov::PhoneBook::insertAfter(iterator iterator, const note_t& note)
{
	iterator++;
	note_t temp{ note.name, note.number };
	recordings_.insert(iterator, temp);
}

void razukrantov::PhoneBook::insertBefore(iterator iterator, const note_t& note)
{
	note_t temp{ note.name, note.number };
	recordings_.insert(iterator, temp);
}

void razukrantov::PhoneBook::pushBack(const note_t& note)
{
	note_t temp{ note.name, note.number };
	recordings_.push_back(temp);
}

void razukrantov::PhoneBook::replace(iterator iterator, const note_t& note)
{
	iterator->name = note.name;
	iterator->number = note.number;
}

void razukrantov::PhoneBook::erase(iterator iterator)
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

razukrantov::PhoneBook::iterator razukrantov::PhoneBook::begin()
{
	recondings_.begin();
}

razukrantov::PhoneBook::iterator razukrantov::PhoneBook::end()
{
	recondings_.end();
}

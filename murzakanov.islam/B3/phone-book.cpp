#include "phone-book.hpp"
#include <iostream>

using namespace murzakanov;

PhoneBook::iterator PhoneBook::begin()
{
  return book_.begin();
}
PhoneBook::iterator PhoneBook::end()
{
  return book_.end();
}
void PhoneBook::insertAfter(iterator it, const note_t& note)
{
  iterator tempIt(it);
  ++tempIt;
  note_t tempNote{note.number, note.name};
  if (tempIt == std::prev(book_.end()))
  {
    book_.push_back(tempNote);
    return;
  }
  book_.insert(tempIt, tempNote);
}

void PhoneBook::insertBefore(iterator it, const note_t& note)
{
  note_t tempNote{note.number, note.name};
  book_.insert(it, tempNote);
}

void PhoneBook::deleteNote(iterator it)
{
  book_.erase(it);
}

void PhoneBook::push_back(const note_t& note)
{
  note_t temp{note.number, note.name};
  book_.push_back(temp);
}

void PhoneBook::replace(iterator it, const note_t& note)
{
  it->name = note.name;
  it->number = note.number;
}

void PhoneBook::show(std::ostream& out, iterator it) const
{
  out << it->number << " " << it->name << "\n";
}

size_t PhoneBook::size() const
{
  return book_.size();
}

bool PhoneBook::isEmpty() const
{
  return book_.empty();
}

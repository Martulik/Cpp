#include "phone-book.hpp"

using namespace murzakanov;

PhoneBook::iterator PhoneBook::begin()
{
  book_.begin();
}
PhoneBook::iterator PhoneBook::end()
{
  book_.end();
}
void PhoneBook::insertAfter(iterator it, const note_t& note)
{
  iterator tempIt(it + 1);
  note_t temp{note.name, note.number};
  if (tempIt == book_.end())
  {
    book_.push_back(temp);
    return;
  }
  book_.insert(tempIt, temp);
}

void PhoneBook::insertBefore(iterator it, const note_t& note)
{
  note_t temp{note.name, note.number};
  book_.insert(it, temp);
}

void PhoneBook::deleteNote(iterator it)
{
  book_.erase(it);
}

void PhoneBook::push_back(const note_t& note)
{
  note_t temp{note.name, note.number};
  book_.push_back(temp);
}

void PhoneBook::replace(iterator it, const note_t& note)
{
  it->name = note.name;
  it->number = note.number;
}

void PhoneBook::show(std::ostream& out, iterator it)
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

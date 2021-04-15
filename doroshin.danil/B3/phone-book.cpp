#include "phone-book.hpp"

namespace dan = doroshin;

dan::PhoneBook::PhoneBook():
  entries_(),
  bookmarks_()
{

}

void dan::PhoneBook::add(Entry entry)
{
  entries_.emplace_back(std::move(entry));
}

void dan::PhoneBook::store(const Name& from, const Name& to)
{
  bookmarks_.insert({to, bookmarks_.at(from)});
}

void dan::PhoneBook::insert_before(const Name& mark, Entry entry)
{
  entries_.emplace(bookmarks_.at(mark), std::move(entry));
}

void dan::PhoneBook::insert_after(const Name& mark, Entry entry)
{
  Iter i = bookmarks_.at(mark);
  entries_.emplace(++i, std::move(entry));
}

void dan::PhoneBook::delete_contents(const Name& mark)
{
  Iter del = bookmarks_.at(mark);
  for(auto& bookmark: bookmarks_) {
    if(bookmark.second == del) {
      bookmark.second++;
    }
  }
  entries_.erase(del);
}

dan::PhoneBook::Entry dan::PhoneBook::show(const Name& mark) const
{
  return *bookmarks_.at(mark);
}

void dan::PhoneBook::move_front(const Name& mark)
{
  bookmarks_.at(mark) = entries_.begin();
}

void dan::PhoneBook::move_back(const Name& mark)
{
  bookmarks_.at(mark) = --entries_.end();
}

void dan::PhoneBook::move(const Name& mark, int steps)
{
  Iter& i = bookmarks_.at(mark);
  if(steps > 0) {
    while(steps) {
      if(++i == entries_.end()) {
        i = entries_.begin();
      }
      steps--;
    }
  }
  else {
    while(steps) {
      if(i == entries_.begin()) {
        i = entries_.end();
      }
      i--;
      steps++;
    }
  }
}

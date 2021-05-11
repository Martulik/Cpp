#include "phone-book.hpp"
#include <iostream>
#include <cassert>
#include <stdexcept>
#include "lab-exceptions.hpp"

namespace dan = doroshin;

dan::PhoneBook::PhoneBook():
  entries_(),
  bookmarks_({ {"current", entries_.end()} })
{}

void dan::PhoneBook::update_current()
{
  if(bookmarks_.at("current") == entries_.end()) {
    assert(!bookmarks_.empty());
    bookmarks_.at("current") = --entries_.end();
  }
}

void dan::PhoneBook::add(Entry entry)
{
  entries_.emplace_back(std::move(entry));
  update_current();
}

void dan::PhoneBook::store(const std::string& from, const std::string& to)
{
  try {
    bookmarks_.insert({to, bookmarks_.at(from)});
  }
  catch(const std::out_of_range&) {
    throw InvalidBookmarkException();
  }
}

void dan::PhoneBook::insert_before(const std::string& mark, Entry entry)
{
  try {
    entries_.emplace(bookmarks_.at(mark), std::move(entry));
    update_current();
  }
  catch(const std::out_of_range&) {
    throw InvalidBookmarkException();
  }
}

void dan::PhoneBook::insert_after(const std::string& mark, Entry entry)
{
  try {
    Iter i = bookmarks_.at(mark);
    if(i != entries_.end()) {
      i++;
    }
    entries_.emplace(i, std::move(entry));
    update_current();
  }
  catch(const std::out_of_range&) {
    throw InvalidBookmarkException();
  }
}

void dan::PhoneBook::delete_contents(const std::string& mark)
{
  try {
    Iter del = bookmarks_.at(mark);
    for(auto&& bookmark: bookmarks_) {
      if(bookmark.second == del) {
        bookmark.second++;
        if(bookmark.second == entries_.end() && entries_.size() > 1) {
          bookmark.second = entries_.begin();
        }
      }
    }
    entries_.erase(del);
  }
  catch(const std::out_of_range&) {
    throw InvalidBookmarkException();
  }
}

dan::Entry dan::PhoneBook::show(const std::string& mark) const
{
  try {
    Iter res = bookmarks_.at(mark);
    if(res == entries_.end()) {
      throw EmptyPhoneBookException();
    }
    return *res;
  }
  catch(const std::out_of_range&) {
    throw InvalidBookmarkException();
  }
}

void dan::PhoneBook::move_front(const std::string& mark)
{
  try {
    bookmarks_.at(mark) = entries_.begin();
  }
  catch(const std::out_of_range&) {
    throw InvalidBookmarkException();
  }
}

void dan::PhoneBook::move_back(const std::string& mark)
{
  try {
    if(!entries_.empty()) {
      bookmarks_.at(mark) = --entries_.end();
    }
  }
  catch(const std::out_of_range&) {
    throw InvalidBookmarkException();
  }
}

template< typename ForwardIter >
void moveSteps(ForwardIter& i, ForwardIter begin, ForwardIter end, unsigned int steps)
{
  while(steps) {
    if(++i == end) {
      i = begin;
    }
    steps--;
  }
}

void dan::PhoneBook::move(const std::string& mark, int steps)
{
  try {
    Iter& i = bookmarks_.at(mark);
    if(steps > 0) {
      moveSteps< Iter >(i, entries_.begin(), entries_.end(), steps);
    }
    else {
      auto rev_i = std::make_reverse_iterator(++i);
      moveSteps<>(rev_i, entries_.crbegin(), entries_.crend(), -steps);
      i = --rev_i.base();
    }
  }
  catch(const std::out_of_range&) {
    throw InvalidBookmarkException();
  }
}

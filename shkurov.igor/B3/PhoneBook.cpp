#include "PhoneBook.hpp"

#include <utility>
#include <iostream>
#include <stdexcept>

namespace lab = shkurov;

lab::PhoneBook::iterator_t lab::PhoneBook::begin()
{
  return container_.begin();
}

lab::PhoneBook::iterator_t lab::PhoneBook::end()
{
  return container_.end();
}

void lab::PhoneBook::insertForward(lab::PhoneBook::const_iterator_t& it, const lab::PhoneBook::node_t& node)
{
  container_.insert(++it, node);
}

void lab::PhoneBook::insertBackward(lab::PhoneBook::const_iterator_t& it, const lab::PhoneBook::node_t& node)
{
  container_.insert(it, node);
}

lab::PhoneBook::node_t lab::PhoneBook::pullCurrent(const lab::PhoneBook::const_iterator_t& it) const
{
  return *it;
}

void lab::PhoneBook::replaceCurrent(const lab::PhoneBook::iterator_t& it, const node_t& node)
{
  node_t temp = node;
  iterator_t tempIt = it;
  std::swap(std::get<0>(*tempIt), std::get<0>(temp));
  std::swap(std::get<1>(*tempIt), std::get<1>(temp));
}

void lab::PhoneBook::pushBack(const node_t& node)
{
  container_.push_back(node);
}

void lab::PhoneBook::move(lab::PhoneBook::const_iterator_t& it, int steps)
{
  std::advance(it, steps);
}

void lab::PhoneBook::move(lab::PhoneBook::const_iterator_t& it, const std::string& pos)
{
  if (pos == "first")
  {
    it = container_.cbegin();
  }
  else if (pos == "last")
  {
    it = --container_.cend();
  }
}

size_t lab::PhoneBook::size() const
{
  return container_.size();
}

void lab::PhoneBook::deleteNode(const lab::PhoneBook::const_iterator_t& it)
{
  container_.erase(it);
}

#include "container.hpp"
#include "cassert"

constexpr int MAX_POS = 11;
constexpr int MIN_POS = 1;

constexpr int factorial(size_t n)
{
  return (n <= 1) ? 1 : (n * factorial(n - 1));
}

constexpr int MIN_VALUE = factorial(MIN_POS);
constexpr int MAX_VALUE = factorial(MAX_POS);

diurdeva::Container::IteratorFact::IteratorFact() :
  value_(0),
  pos_(0)
{}

const size_t* diurdeva::Container::IteratorFact::operator->() const
{
  return &value_;
}

const size_t& diurdeva::Container::IteratorFact::operator*() const
{
  return value_;
}

diurdeva::Container::IteratorFact& diurdeva::Container::IteratorFact::operator++()
{
  assert(pos_ < MAX_POS);
  value_ *= ++pos_;
  return *this;

}

diurdeva::Container::IteratorFact diurdeva::Container::IteratorFact::operator++(int)
{
  IteratorFact temp = *this;
  ++(*this);
  return temp;
}

diurdeva::Container::IteratorFact& diurdeva::Container::IteratorFact::operator--()
{
  assert(pos_ > MIN_POS);
  value_ /= pos_--;
  return *this;

}

diurdeva::Container ::IteratorFact diurdeva::Container::IteratorFact::operator--(int)
{
  IteratorFact temp = *this;
  --(*this);
  return temp;
}

bool diurdeva::Container::IteratorFact::operator==(const Container::IteratorFact& rhs) const
{
  return (pos_ == rhs.pos_);
}

bool diurdeva::Container::IteratorFact::operator!=(const Container::IteratorFact& rhs) const
{
  return !(*this == rhs);
}


const diurdeva::Container::IteratorFact diurdeva::Container::begin()
{
  return {MIN_VALUE, MIN_POS};
}

const diurdeva::Container ::IteratorFact diurdeva::Container::end()
{
  return {MAX_VALUE, MAX_POS};
}

diurdeva::Container::IteratorFact::IteratorFact(size_t value, size_t pos) :
  value_(value),
  pos_(pos)
{}

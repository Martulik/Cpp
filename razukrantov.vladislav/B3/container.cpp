#include "container.hpp"
#include "functions.hpp"

constexpr size_t MAX_SIZE = 11;

razukrantov::Container::Iterator::Iterator() :
	index_(1),
	value_(1)
{
}

razukrantov::Container::Iterator::Iterator(const size_t index) :
	index_(index),
	value_(razukrantov::getFactorial(index))
{
}

razukrantov::Container::Iterator& razukrantov::Container::Iterator::operator++()
{
	++index_;
	value_ *= index_;
	return *this;
}

razukrantov::Container::Iterator razukrantov::Container::Iterator::operator++(int)
{
	Iterator temp = *this;
	++(*this);
	return temp;
}

razukrantov::Container::Iterator& razukrantov::Container::Iterator::operator--()
{
	value_ /= index_;
	--index_;
	return *this;
}

razukrantov::Container::Iterator razukrantov::Container::Iterator::operator--(int)
{
	Iterator temp = *this;
	--(*this);
	return temp;
}

size_t& razukrantov::Container::Iterator::operator*()
{
	return value_;
}

size_t* razukrantov::Container::Iterator::operator->()
{
	return std::addressof(value_);
}
bool razukrantov::Container::Iterator::operator==(const Iterator& other) const
{
	return (value_ == other.value_ && other.index_ == index_);
}

bool razukrantov::Container::Iterator::operator!=(const Iterator& other) const
{
	return !(value_ == other.value_ && other.index_ == index_);
}

razukrantov::Container::Iterator razukrantov::Container::begin()
{
	return Iterator();
}

razukrantov::Container::Iterator razukrantov::Container::end()
{
	return Iterator(MAX_SIZE);
}

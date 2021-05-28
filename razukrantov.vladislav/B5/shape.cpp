#include "shape.hpp"

#include <iostream>
#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <string>

std::ostream& razukrantov::operator<<(std::ostream& out, const Shape& shape)
{
	out << shape.size() << ' ';
	std::copy(shape.begin(), shape.end(), std::ostream_iterator< Point >(out, " "));
	return out;
}

std::istream& razukrantov::operator>>(std::istream& in, Shape& shape)
{
	size_t count = 0;
	in >> count;
	if (!in)
	{
		throw(std::invalid_argument("Incorrect reading"));
	}
	if (count == 0)
	{
		return in;
	}
	Shape temp;
	temp.reserve(count);
	std::copy_n(std::istream_iterator< Point >(in), count, std::back_inserter(temp));
	std::string str;
	std::getline(in, str);
	if (!in || count != temp.size())
	{
		throw(std::invalid_argument("Incorrect reading"));
	}
	shape.swap(temp);
	return in;
}

#include "data-struct.hpp"

#include <iostream>

std::istream& razukrantov::operator>>(std::istream& in, DataStruct& ds)
{
	std::string line;
	std::getline(in, line); 
}

std::ostream& razukrantov::operator<<(std::ostream& out, const DataStruct& ds)
{
	out << ds.key1 << "," << ds.key2 << "," << ds.str;
	return out;
}

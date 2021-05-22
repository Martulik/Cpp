#ifndef DATA_STRUCT_HPP
#define DATA_STRUCT_HPP

#include <string>
#include <iosfwd>

namespace razukrantov
{
	struct DataStruct
	{
		int key1;
		int key2;
		std::string str;
	};

	std::istream& operator>>(std::istream& in, DataStruct& ds);
	std::ostream& operator<<(std::ostream& out, const DataStruct& ds);
}

#endif

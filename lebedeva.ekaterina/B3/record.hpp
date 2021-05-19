#ifndef RECORD_HPP
#define RECORD_HPP
#include <string>

namespace lebedeva
{
	struct record_t
	{
	  std::string name;
		std::string phoneNumber;
	};

	std::ostream& operator<<(std::ostream& out, const record_t& rec);
	bool checkNumber(const std::string& number);
}

#endif

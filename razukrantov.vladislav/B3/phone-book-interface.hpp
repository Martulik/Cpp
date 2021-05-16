#ifndef PHONE_BOOK_INTERFACE
#define PHONE_BOOK_INTERFACE

#include <memory>
#include <map>
#include <string>

#include "phone-book.hpp"

namespace razukrantov
{
	class PhoneBookInterface
	{
	public:
		using note_t = razukrantov::PhoneBook::note_t;
		PhoneBookInterface(PhoneBook& book);
		void add(const note_t& note);

	private:
		std::unique_ptr< razukrantov::PhoneBook > book_;
		std::map < std::string, razukrantov::PhoneBook::iterator > bookmarks_;
	};
}

#endif

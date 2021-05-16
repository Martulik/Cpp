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
		using iteratorType = std::map < std::string, razukrantov::PhoneBook::iterator >::iterator;
		PhoneBookInterface(PhoneBook& book);
		void add(const note_t& note);
		void store(const std::string& bookMark, const std::string& newBookMark);
		void insertBefore(const std::string& bookMark, const note_t& note);
		void insertAfter(const std::string& bookMark, const note_t& note);
		void erase(const std::string& bookMark);
		void show(const std::string& bookMark, std::ostream& out);
		void move(const std::string& bookMark, const std::string& steps);

	private:
		std::unique_ptr< razukrantov::PhoneBook > book_;
		std::map < std::string, razukrantov::PhoneBook::iterator > bookmarks_;
	};
}

#endif

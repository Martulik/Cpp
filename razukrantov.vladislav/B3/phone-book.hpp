#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include <list>
#include <string>

namespace razukrantov
{
	class PhoneBook
	{
	public:
		struct note_t
		{
			std::string name;
			std::string number;
		};

		using iterator = std::list< note_t >::iterator;
		size_t size() const;
		bool empty() const;
		void show(std::ostream& out, iterator iterator) const;
		void moveNext(iterator iterator);
		void movePrev(iterator iterator);
		void insertAfter(iterator iterator, const note_t& note);
		void insertBefore(iterator iterator, const note_t& note);
		void replace(iterator iterator, const note_t& note);
		void pushBack(const note_t& note);
		void move(iterator iterator, int step) const;
		void erase(iterator iterator);
		iterator begin();
		iterator end();
	private:
		std::list< note_t > recondings_;
	};
}

#endif

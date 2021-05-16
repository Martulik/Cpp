#include "tasks.hpp"

#include <iostream>

#include "phone-book.hpp"
#include "phone-book-interface.hpp"

void razukrantov::taskPhoneBook(std::istream& in, std::ostream& out)
{
	razukrantov::PhoneBook phoneBook;
	razukrantov::PhoneBookInterface  interface(phoneBook);
	std::string string;
	while (std::getline(in, string))
	{
		std::stringstream input(string);
		std::string command;
		input >> command;
		if (command == "add")
		{

		}
		else if (command == "store")
		{

		}
		else if (command == "insert")
		{

		}
		else if (command == "delete")
		{

		}
		else if (command == "show")
		{

		}
		else if (command == "move")
		{

		}
		else
		{

		}
	}
}

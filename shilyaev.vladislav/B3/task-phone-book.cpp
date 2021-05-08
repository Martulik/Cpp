#include "task-phone-book.hpp"
#include <iostream>
#include <iterator>
#include <functional>
#include "tokenizer.hpp"
#include "phone-book.hpp"
#include "task-phone-book-exception.hpp"

namespace shilyaev {
  using CommandFunction = std::function< void(std::ostream &, const std::vector< std::string > &, PhoneBook &) >;

  bool isNameValid(const std::string &name)
  {
    return name[0] == '"' && name.back() == '"';
  }

  void add(std::ostream &, const std::vector< std::string > &arguments, PhoneBook &book)
  {
    if (arguments.size() != 3) {
      throw InvalidCommandException();
    }
    const std::string &number = arguments[1];
    const std::string &name = arguments[2];
    if (!isNameValid(name)) {
      throw InvalidCommandException();
    }
    book.pushBack({number, name.substr(1, name.length() - 2)});
  }

  void store(std::ostream &, const std::vector< std::string > &arguments, PhoneBook &book)
  {
    if (arguments.size() != 3) {
      throw InvalidCommandException();
    }
    const std::string &bookmarkName = arguments[1];
    const std::string &newBookmarkName = arguments[2];
    book.store(bookmarkName, newBookmarkName);
  }

  void insert(std::ostream &, const std::vector< std::string > &arguments, PhoneBook &book)
  {
    if (arguments.size() != 5) {
      throw InvalidCommandException();
    }
    const std::string &where = arguments[1];
    const std::string &bookmarkName = arguments[2];
    const std::string &number = arguments[3];
    const std::string &name = arguments[4];
    if (!isNameValid(name)) {
      throw InvalidCommandException();
    }
    const PhoneBook::Entry entry{number, name.substr(1, name.length() - 2)};
    if (where == "before") {
      book.insertBefore(bookmarkName, entry);
    } else if (where == "after") {
      book.insertAfter(bookmarkName, entry);
    } else {
      throw InvalidCommandException();
    }
  }

  void erase(std::ostream &, const std::vector< std::string > &arguments, PhoneBook &book)
  {
    if (arguments.size() != 2) {
      throw InvalidCommandException();
    }
    const std::string &bookmarkName = arguments[1];
    book.erase(bookmarkName);
  }

  void show(std::ostream &ostream, const std::vector< std::string > &arguments, const PhoneBook &book)
  {
    if (arguments.size() != 2) {
      throw InvalidCommandException();
    }
    const std::string &bookmarkName = arguments[1];
    const PhoneBook::Entry entry = book.getEntry(bookmarkName);
    ostream << entry.number << ' ' << entry.name << '\n';
  }

  void move(std::ostream &, const std::vector< std::string > &arguments, PhoneBook &book)
  {
    if (arguments.size() != 3) {
      throw InvalidCommandException();
    }
    const std::string &bookmarkName = arguments[1];
    const std::string &step = arguments[2];
    if (step == "first") {
      book.moveFirst(bookmarkName);
    } else if (step == "last") {
      book.moveLast(bookmarkName);
    } else {
      try {
        const int stepInt = std::stoi(step);
        book.move(bookmarkName, stepInt);
      } catch (const std::invalid_argument &) {
        throw InvalidStepException();
      }
    }
  }

  CommandFunction getCommandFunction(const std::string &commandName)
  {
    const static std::map< std::string, CommandFunction > functions{
      std::make_pair("add", add),
      std::make_pair("store", store),
      std::make_pair("insert", insert),
      std::make_pair("delete", erase),
      std::make_pair("show", show),
      std::make_pair("move", move),
    };
    try {
      return functions.at(commandName);
    } catch (const std::out_of_range &) {
      throw InvalidCommandException();
    }
  }

  int taskPhoneBook(std::istream &istream, std::ostream &ostream)
  {
    PhoneBook phoneBook;
    std::string command;
    while (std::getline(istream, command)) {
      std::vector< std::string > arguments = tokenize(command);
      try {
        getCommandFunction(arguments.front())(ostream, arguments, phoneBook);
      } catch (const InvalidCommandException &) {
        ostream << "<INVALID COMMAND>\n";
      } catch (const InvalidStepException &) {
        ostream << "<INVALID STEP>\n";
      } catch (const EmptyException &) {
        ostream << "<EMPTY>\n";
      } catch (const NoBookmarkException &) {
        ostream << "<INVALID BOOKMARK>\n";
      }
    }
    return istream.eof() ? 0 : 2;
  }
}

#include "task-phone-book.hpp"
#include <iostream>
#include <iterator>
#include "tokenizer.hpp"
#include "phone-book.hpp"

namespace shilyaev {
  const std::string INVALID_BOOKMARK_ERROR = "<INVALID BOOKMARK>";
  const std::string INVALID_COMMAND_ERROR = "<INVALID COMMAND>";
  const std::string INVALID_STEP_ERROR = "<INVALID STEP>";
  const std::string EMPTY_ERROR = "<EMPTY>";

  bool isNameValid(const std::string &name)
  {
    return name[0] == '"' && name.back() == '"';
  }

  void add(const std::vector< std::string > &arguments, PhoneBook &book)
  {
    const std::string &number = arguments[1];
    const std::string &name = arguments[2];
    if (!isNameValid(name)) {
      std::cout << INVALID_COMMAND_ERROR << '\n';
      return;
    }
    book.pushBack({number, name.substr(1, name.length() - 2)});
  }

  void store(const std::vector< std::string > &arguments, PhoneBook &book)
  {
    const std::string &bookmarkName = arguments[1];
    const std::string &newBookmarkName = arguments[2];
    book.store(bookmarkName, newBookmarkName);
  }

  void insert(const std::vector< std::string > &arguments, PhoneBook &book)
  {
    const std::string &where = arguments[1];
    const std::string &bookmarkName = arguments[2];
    const std::string &number = arguments[3];
    const std::string &name = arguments[4];
    if (!isNameValid(name)) {
      std::cout << INVALID_COMMAND_ERROR << '\n';
      return;
    }
    const PhoneBook::Entry entry{number, name.substr(1, name.length() - 2)};
    if (where == "before") {
      book.insertBefore(bookmarkName, entry);
    } else if (where == "after") {
      book.insertAfter(bookmarkName, entry);
    } else {
      std::cout << INVALID_COMMAND_ERROR << '\n';
    }
  }

  void erase(const std::vector< std::string > &arguments, PhoneBook &book)
  {
    const std::string &bookmarkName = arguments[1];
    book.erase(bookmarkName);
  }

  void show(const std::vector< std::string > &arguments, const PhoneBook &book)
  {
    const std::string &bookmarkName = arguments[1];
    const boost::optional< PhoneBook::Entry > entry = book.getEntry(bookmarkName);
    if (!entry) {
      std::cout << EMPTY_ERROR << '\n';
      return;
    }
    std::cout << entry->number << ' ' << entry->name << '\n';
  }

  void move(const std::vector< std::string > &arguments, PhoneBook &book)
  {
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
        std::cout << INVALID_STEP_ERROR << '\n';
      }
    }
  }

  void execute(const std::string &command, PhoneBook &phoneBook)
  {
    std::vector< std::string > arguments = tokenize(command);
    const std::string &commandName = arguments[0];
    try {
      if (commandName == "add" && arguments.size() == 3) {
        add(arguments, phoneBook);
      } else if (commandName == "store" && arguments.size() == 3) {
        store(arguments, phoneBook);
      } else if (commandName == "insert" && arguments.size() == 5) {
        insert(arguments, phoneBook);
      } else if (commandName == "delete" && arguments.size() == 2) {
        erase(arguments, phoneBook);
      } else if (commandName == "show" && arguments.size() == 2) {
        show(arguments, phoneBook);
      } else if (commandName == "move" && arguments.size() == 3) {
        move(arguments, phoneBook);
      } else {
        std::cout << INVALID_COMMAND_ERROR << '\n';
      }
    } catch (const std::out_of_range &) {
      std::cout << INVALID_BOOKMARK_ERROR << '\n';
    }
  }

  int taskPhoneBook()
  {
    PhoneBook phoneBook;
    std::string command;
    while (std::getline(std::cin, command)) {
      execute(command, phoneBook);
    }
    return std::cin.eof() ? 0 : 2;
  }
}

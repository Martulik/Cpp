#include "task-phone-book.hpp"
#include <map>
#include <iostream>
#include <iterator>
#include <boost/tokenizer.hpp>
#include "phone-book.hpp"

namespace shilyaev {
  const std::string INVALID_BOOKMARK_ERROR = "<INVALID BOOKMARK>";
  const std::string INVALID_COMMAND_ERROR = "<INVALID COMMAND>";
  const std::string INVALID_STEP_ERROR = "<INVALID STEP>";
  const std::string EMPTY_ERROR = "<EMPTY>";

  using Iterator = PhoneBook::Iterator;
  using BookmarkMap = std::map< std::string, Iterator >;

  void add(const std::vector< std::string > &arguments, PhoneBook &book, BookmarkMap &bookmarks)
  {
    const std::string &number = arguments[1];
    const std::string &name = arguments[2];
    Iterator iterator = book.pushBack({number, name});
    if (book.size() == 1) {
      for (auto &&bookmark : bookmarks) {
        bookmark.second = iterator;
      }
    }
  }

  void store(const std::vector< std::string > &arguments, BookmarkMap &bookmarks)
  {
    const std::string &bookmarkName = arguments[1];
    const std::string &newBookmarkName = arguments[2];
    bookmarks[newBookmarkName] = bookmarks.at(bookmarkName);
  }

  void insert(const std::vector< std::string > &arguments, PhoneBook &book, BookmarkMap &bookmarks)
  {
    const std::string &where = arguments[1];
    const std::string &bookmarkName = arguments[2];
    const std::string &number = arguments[3];
    const std::string &name = arguments[4];
    int iteratorDelta = 0;
    if (where == "after") {
      iteratorDelta = 1;
    } else if (where != "before") {
      std::cout << INVALID_COMMAND_ERROR << '\n';
      return;
    }
    Iterator iterator = bookmarks.at(bookmarkName);
    PhoneBook::Entry entry{number, name};
    if (book.empty()) {
      Iterator newIterator = book.pushBack(entry);
      for (auto &&bookmark : bookmarks) {
        bookmark.second = newIterator;
      }
    } else {
      book.insert(std::next(iterator, iteratorDelta), entry);
    }
  }

  void erase(const std::vector< std::string > &arguments, PhoneBook &book, BookmarkMap &bookmarks)
  {
    const std::string &bookmarkName = arguments[1];
    Iterator iteratorToErase = bookmarks.at(bookmarkName);
    Iterator newIterator = book.erase(iteratorToErase);
    if (newIterator == book.end()) {
      --newIterator;
    }
    for (auto &&bookmark : bookmarks) {
      if (bookmark.second == iteratorToErase) {
        bookmark.second = newIterator;
      }
    }
  }

  void show(const std::vector< std::string > &arguments, const PhoneBook &book, const BookmarkMap &bookmarks)
  {
    const std::string &bookmarkName = arguments[1];
    const Iterator bookmark = bookmarks.at(bookmarkName);
    if (book.empty()) {
      std::cout << EMPTY_ERROR << '\n';
      return;
    }
    std::cout << bookmark->number << ' ' << bookmark->name << '\n';
  }

  Iterator safeAdvance(Iterator iterator, int n, const Iterator &begin, const Iterator &end)
  {
    while (n > 0 && std::next(iterator) != end) {
      n--;
      iterator++;
    }
    while (n < 0 && iterator != begin) {
      n++;
      iterator--;
    }
    return iterator;
  }

  void move(const std::vector< std::string > &arguments, PhoneBook &book, BookmarkMap &bookmarks)
  {
    const std::string &bookmarkName = arguments[1];
    const std::string &step = arguments[2];
    Iterator &bookmark = bookmarks.at(bookmarkName);
    if (step == "first") {
      bookmark = book.begin();
    } else if (step == "last") {
      bookmark = std::prev(book.end());
    } else {
      try {
        const int stepInt = std::stoi(step);
        bookmark = safeAdvance(bookmark, stepInt, book.begin(), book.end());
      } catch (const std::invalid_argument &) {
        std::cout << INVALID_STEP_ERROR << '\n';
      }
    }
  }

  void execute(const std::string &command, PhoneBook &phoneBook, BookmarkMap &bookmarks)
  {
    const boost::escaped_list_separator< char > separator('\\', ' ', '\"');
    const boost::tokenizer< boost::escaped_list_separator< char > > tokenizer(command, separator);
    std::vector< std::string > arguments;
    std::copy(tokenizer.begin(), tokenizer.end(), std::back_inserter(arguments));
    if (arguments.empty()) {
      std::cout << INVALID_COMMAND_ERROR << '\n';
      return;
    }
    const std::string &commandName = arguments[0];
    try {
      if (commandName == "add" && arguments.size() == 3) {
        add(arguments, phoneBook, bookmarks);
      } else if (commandName == "store" && arguments.size() == 3) {
        store(arguments, bookmarks);
      } else if (commandName == "insert" && arguments.size() == 5) {
        insert(arguments, phoneBook, bookmarks);
      } else if (commandName == "delete" && arguments.size() == 2) {
        erase(arguments, phoneBook, bookmarks);
      } else if (commandName == "show" && arguments.size() == 2) {
        show(arguments, phoneBook, bookmarks);
      } else if (commandName == "move" && arguments.size() == 3) {
        move(arguments, phoneBook, bookmarks);
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
    BookmarkMap bookmarks;
    bookmarks["current"];
    std::string command;
    while (std::getline(std::cin, command)) {
      execute(command, phoneBook, bookmarks);
    }
    return std::cin.eof() ? 0 : 2;
  }
}

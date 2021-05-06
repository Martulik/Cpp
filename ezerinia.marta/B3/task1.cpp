#include "task1.hpp"
#include <string>
#include <istream>
#include "tools.hpp"

namespace lab = ezerinia;

void lab::task1()
{
  lab::UserInterface phoneBook;
  std::string string;

  while (std::getline(std::cin, string)) {
    if (std::cin.fail()) {
      throw std::runtime_error("Read fail");
    }
    std::stringstream input(string);
    std::string command;
    input >> command;
    if (command == "add") {
      add(phoneBook, input);
    } else if (command == "store") {
      store(phoneBook, input);
    } else if (command == "insert") {
      insert(phoneBook, input);
    } else if (command == "delete") {
      deleteRecord(phoneBook, input);
    } else if (command == "show") {
      show(phoneBook, input);
    } else if (command == "move") {
      move(phoneBook, input);
    } else {
      invalidCommand(std::cout);
    }
  }
}

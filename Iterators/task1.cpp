#include "task1.hpp"
#include <sstream>
#include "UserInterface.hpp"

namespace lab = ezerinia;

void lab::task1(std::istream &in, std::ostream &out)
{
  lab::UserInterface interface(out);
  std::string string;
  while (std::getline(in, string)) {
    if (in.fail()) {
      throw std::runtime_error("Read fail");
    }
    std::stringstream input(string);
    std::string command;
    input >> command;
    if (command == "add") {
      interface.add(input);
    } else if (command == "store") {
      interface.store(input);
    } else if (command == "insert") {
      interface.insert(input);
    } else if (command == "delete") {
      interface.deleteRecord(input);
    } else if (command == "show") {
      interface.show(input);
    } else if (command == "move") {
      interface.move(input);
    } else {
      invalidCommand(out);
    }
  }
}

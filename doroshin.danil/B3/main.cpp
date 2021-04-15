#include <iostream>
#include <sstream>
#include <string>
#include "phone-book.hpp"

namespace dan = doroshin;

std::istream& quotedString(std::istream& in, std::string& res)
{
  res.clear();
  while(in.get() != '"') {
    if(!in) {
      return in;
    }
  }
  while(true) {
    char next = in.get();
    if(in.good()) {
      if(next == '\\') {
        res += in.get();
      }
      else if(next != '"') {
        res += next;
      }
      else {
        break;
      }
    }
    else {
      in.setstate(std::ios::failbit);
    }
  }
  return in;
}

int main()
{
  dan::PhoneBook book;
  std::string line_;
  while(std::getline(std::cin, line_).good()) {
    std::istringstream line(line_);

    std::string command;
    line >> command;
    if(command == "add") {
      int number;
      std::string name;
      line >> number;
      if(!line) {
        std::cerr << "Invalid phone number\n";
        return 2;
      }
      if(quotedString(line, name)) {
        book.add({ number, std::move(name) });
      }
      else {
        std::cerr << "Invalid name\n";
        return 2;
      }
    }
    else if(command == "store") {
      std::string from, to;
      line >> from >> to;
      book.store(from, to);
    }
    else if(command == "insert") {
      std::string where, mark, name;
      int number;
      line >> where >> mark >> number;
      if(!quotedString(line, name)) {
        std::cerr << "Invalid name\n";
        return 2;
      }
      if(where == "before") {
        book.insert_before(mark, { number, std::move(name) });
      }
      if(where == "after") {
        book.insert_after(mark, { number, std::move(name) });
      }
      else {
        std::cout << "<INVALID COMMAND>\n";
        continue;
      }
    }
    else if(command == "delete") {
      std::string mark;
      line >> mark;
      book.delete_contents(mark);
    }
    else if(command == "show") {
      std::string mark;
      line >> mark;
      std::cout << book.show(mark).second << '\n';
    }
    else if(command == "move") {
      std::string mark, steps;
      line >> mark >> steps;
      try {
        int i_steps = std::stoi(steps);
        book.move(mark, i_steps);
      }
      catch(const std::invalid_argument&) {
        if(steps == "first") {
          book.move_front(mark);
        }
        else if(steps == "last") {
          book.move_back(mark);
        }
        else {
          std::cout << "<INVALID STEP>\n";
        }
      }
    }
    else {
      std::cout << "<INVALID COMMAND>\n";
    }
  }
  return 2;
}

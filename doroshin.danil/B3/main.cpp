#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "phone-book.hpp"
#include "factorials.hpp"

namespace dan = doroshin;

std::istream& quotedString(std::istream& in, std::string& res)
{
  res.clear();
  while(in.get() != '"') {
    if(!in) {
      return in;
    }
  }
  while(!in.eof()) {
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

int task1()
{
dan::PhoneBook book;
  std::string line_;
  while(std::getline(std::cin, line_).good() && !line_.empty()) {
    std::istringstream line(line_);

    std::string command;
    line >> command;
    try {
      if(command == "add") {
        dan::PhoneBook::Number number;
        std::string name;
        line >> number;
        if(!line) {
          std::cout << "<INVALID COMMAND>\n";
          continue;
        }
        if(line.peek() != ' ') {
          std::cout << "<INVALID COMMAND>\n";
          continue;
        }
        if(quotedString(line, name)) {
          book.add({ number, std::move(name) });
        }
        else {
          std::cout << "<INVALID COMMAND>\n";
          continue;
        }
      }
      else if(command == "store") {
        std::string from, to;
        line >> from >> to;
        book.store(from, to);
      }
      else if(command == "insert") {
        std::string where, mark, name;
        dan::PhoneBook::Number number;
        line >> where >> mark >> number;
        if(!line) {
          std::cout << "<INVALID COMMAND>\n";
          continue;
        }
        if(line.peek() != ' ') {
          std::cout << "<INVALID COMMAND>\n";
          continue;
        }
        if(!quotedString(line, name)) {
          std::cout << "<INVALID COMMAND>\n";
          continue;
        }
        if(where == "before") {
          book.insert_before(mark, { number, std::move(name) });
        }
        else if(where == "after") {
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
        try {
          dan::PhoneBook::Entry entry = book.show(mark);
          std::cout << std::setfill('0') << std::setw(12) << entry.first << ' ' << entry.second << '\n';
          std::cout.fill(' ');
        }
        catch(const std::out_of_range& e) {
          std::cout << e.what() << '\n';
        }
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
    catch(const dan::InvalidBookmarkException& e) {
      std::cout << e.what() << '\n';
    }
  }
  return 0;
}

int main(int argc, char* argv[])
{
  if(argc != 2) {
    std::cerr << "No task number\n";
    return 1;
  }
  if(argv[1][1] != '\0') {
    std::cerr << "Extra symbols in task number\n";
    return 1;
  }
  int task = argv[1][0] - '0';
  if(task == 1) {
    return task1();
  }
  else if(task == 2) {
    dan::Factorials fact(1, 10);
    std::ostream_iterator< dan::Factorials::value_t > out(std::cout, " ");
    std::copy(fact.begin(), fact.end(), out);
    std::cout << '\n';
    std::copy(std::make_reverse_iterator(fact.end()), std::make_reverse_iterator(fact.begin()), out);
    std::cout << '\n';
  }
  else {
    std::cerr << "Unknown task\n";
    return 1;
  }
  return 0;
}

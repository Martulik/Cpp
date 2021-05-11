#include <iostream>
#include <sstream>
#include <string>
#include "lab-exceptions.hpp"
#include "phone-book.hpp"
#include "factorials.hpp"

namespace dan = doroshin;

int task1(std::istream& in, std::ostream& out)
{
  dan::PhoneBook book;
  std::string line_;
  while(std::getline(in, line_).good() && !line_.empty()) {
    std::istringstream line(line_);

    std::string command;
    line >> command;
    try {
      if(command == "add") {
        dan::Entry entry;
        line >> entry;
        if(!line) {
          throw dan::InvalidCommandException();
        }
        else {
          book.add(std::move(entry));
        }
      }
      else if(command == "store") {
        std::string from, to;
        line >> from >> to;
        book.store(from, to);
      }
      else if(command == "insert") {
        std::string where, mark;
        dan::Entry entry;
        line >> where >> mark >> entry;
        if(!line) {
          throw dan::InvalidCommandException();
        }
        if(where == "before") {
          book.insert_before(mark, std::move(entry));
        }
        else if(where == "after") {
          book.insert_after(mark, std::move(entry));
        }
        else {
          throw dan::InvalidCommandException();
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
        dan::Entry entry = book.show(mark);
        out << entry << '\n';
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
            throw dan::InvalidStepException();
          }
        }
      }
      else {
        throw dan::InvalidCommandException();
      }
    }
    catch(const dan::PhoneBookException& e) {
      out << e.what() << '\n';
    }
    catch(const dan::InvalidCommandException& e) {
      out << e.what() << '\n';
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
    return task1(std::cin, std::cout);
  }
  else if(task == 2) {
    constexpr dan::Factorials fact(1, 10);
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

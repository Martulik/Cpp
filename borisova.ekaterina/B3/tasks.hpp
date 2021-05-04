#ifndef TASKS_HPP
#define TASKS_HPP

#include "interface.hpp"
namespace borisova
{
  void doTask1();
  void doTask2();
  bool correctName(Note& src);
  bool correctNumder(Note& src);

  void add(std::istream& in);
  void store(std::string& oldMark, std::string& newMark);
  void insertBefore(std::string& bookMark, Note& src);
  void insertAfter(std::string& bookMark, Note& src);
  void deleteMark(std::string& bookMark);
  void show(std::string& bookMark);
  void move(std::string& bookmark, int n);
}

#endif

#ifndef B3_USERINTERFACE_HPP
#define B3_USERINTERFACE_HPP

#include "Book.hpp"

namespace ezerinia {
  class UserInterface {
  public:
    explicit UserInterface(std::ostream &stream);
    std::string getMarkName(std::string markName);
    void add(std::stringstream &input);
    void store(std::stringstream &input);
    void insert(std::stringstream &input);
    void deleteRecord(std::stringstream &input);
    void show(std::stringstream &input);
    void move(std::stringstream &input);
  private:
    Book book_;
    std::ostream &stream_;
  };

  void invalidCommand(std::ostream &out);
  void invalidBookmark(std::ostream &out);
  void empty(std::ostream &out);
  void invalidStep(std::ostream &out);
}
#endif

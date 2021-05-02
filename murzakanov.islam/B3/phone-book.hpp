#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include <list>
#include <string>

namespace murzakanov
{
  class PhoneBook
  {
  public:
    struct note_t
    {
      std::string number;
      std::string name;
    };

    using iterator = std::list< note_t >::iterator;
    using const_iterator = std::list< note_t >::const_iterator;

    void insertAfter(iterator it, const note_t& note);
    void insertBefore(iterator it, const note_t& note);
    void deleteNote(iterator it);
    void push_back(const note_t& note);
    void replace(iterator it, const note_t& note);
    void show(std::ostream& out, iterator it) const;
    size_t size() const;
    bool isEmpty() const;

    iterator begin();
    iterator end();
  private:
    std::list< note_t > book_;
  };
}
#endif

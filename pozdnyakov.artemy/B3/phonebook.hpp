#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP


namespace pozdnyakov
{
  class Phonebook
  {
  public:
    using value_type = std::pair< int, std::string >;
    using iterator = std::list< entryPair >::iterator;
    using const_iterator = std::list< entryPair >::const_iterator;
    Phonebook() = default;
    iterator begin();
    iterator end();
    const_iterator cbegin();
    const_iterator cend();
    void pushBack(value_type& val);
    iterator insertBefore(const_iterator position, const value_type& val);
    iterator insertAfter(const_iterator position, const value_type& val);
    iterator erase(iterator it);
    void replace(iterator it)
    void move(iterator it, int n);
  private:
    std::list< entryPair > book_;
  };
}

#endif

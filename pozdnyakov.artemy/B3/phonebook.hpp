#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP


namespace pozdnyakov
{
  using entryPair = std::pair< std::string, std::string >;
  class Phonebook: public std::list< entryPair >
  {
  public:
    void move(iterator iter, int n);
  };
}

#endif

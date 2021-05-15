#ifndef B5_WORDS_HPP
#define B5_WORDS_HPP
#include <iosfwd>
#include <vector>
#include <string>
namespace ivanova
{
  class Words
  {
  public:
    Words() = default;
    ~Words() = default;
    friend std::istream &operator >> (std::istream &in, Words &list);
    friend std::ostream &operator << (std::ostream &out, Words str);

  private:
    std::vector < std::string > vector_;
  };
}
#endif

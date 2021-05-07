#ifndef NOTE_HPP
#define NOTE_HPP

#include <string>

namespace borisova
{
  struct Note
  {
    std::string name_;
    std::string number_;
  };

  bool correctName(std::string& name);
  bool correctNumder(std::string& number);
  std::ostream& operator<<(std::ostream& out, const Note& iter);
}

#endif

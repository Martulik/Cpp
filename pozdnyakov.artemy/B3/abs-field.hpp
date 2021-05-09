#ifndef ABS_FIELD_HPP
#define ABS_FIELD_HPP

#include <string>

namespace pozdnyakov
{
  class AbsField
  {
  public:
    virtual ~AbsField() = default;
    virtual bool isField(std::string field) const = 0;
  };
}

#endif

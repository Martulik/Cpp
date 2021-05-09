#ifndef FIELDS_HPP
#define FIELDS_HPP

#include "abs-field.hpp"
#include <vector>

namespace pozdnyakov
{
  class Command: public AbsField
  {
  public:
    Command() = default;
    ~Command() override = default;
    bool isField(std::string field) const override;
  private:
    const std::vector< std::string > commands_
    {
      "add",
      "store",
      "insert",
      "delete",
      "show",
      "move"
    };
  };

  class CommandParam: public AbsField
  {
  public:
    CommandParam() = default;
    ~CommandParam() override = default;
    bool isField(std::string field) const override;
  private:
    const std::vector< std::string > params_
    {
      "after",
      "before"
    };
  };

  class PhoneNumber: public AbsField
  {
  public:
    PhoneNumber() = default;
    ~PhoneNumber() override = default;
    bool isField(std::string field) const override;
  };

  class Name: public AbsField
  {
  public:
    Name() = default;
    ~Name() override = default;
    bool isField(std::string field) const override;
  };

  class String: public AbsField
  {
  public:
    String() = default;
    ~String() override = default;
    bool isField(std::string) const override;
  };

  class Int: public AbsField
  {
  public:
    Int() = default;
    ~Int() override = default;
    bool isField(std::string field) const override;
  };

  class MoveParam: public AbsField
  {
  public:
    MoveParam() = default;
    ~MoveParam() override = default;
    bool isField(std::string field) const override;
  private:
    const std::vector< std::string > params_;
  };

  bool isNumber(char c);
}

#endif

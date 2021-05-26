#ifndef FIELD_HANDLERS_HPP
#define FIELD_HANDLERS_HPP

#include <vector>
#include <string>

namespace pozdnyakov
{
  struct add_command_t
  {
    bool operator()(std::string field) const;
  private:
    const std::vector< std::string > commands
    {
      "add",
      "insert"
    };
  };

  struct command_t
  {
    bool operator()(std::string field) const;
  private:
    const std::vector< std::string > commands
    {
      "store",
      "delete",
      "show"
    };
  };

  struct insert_param_t
  {
    bool operator()(std::string field) const;
  private:
    const std::vector< std::string > params
    {
      "before",
      "after"
    };
  };

  struct move_param_t
  {
    bool operator()(std::string field) const;
  private:
    const std::vector< std::string > params
    {
      "first",
      "last"
    };
  };

  struct name_t
  {
    bool operator()(std::string field) const;
  };

  struct int_t
  {
    bool operator()(std::string field) const;
  };

  struct string_t
  {
    bool operator()(std::string) const;
  };

  struct move_command_t
  {
    bool operator()(std::string field) const;
  private:
    std::vector< std::string > commands
    {
      "move"
    };
  };
}

#endif

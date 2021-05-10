#include "field-handlers.hpp"
#include <algorithm>
#include <cctype>

namespace poz = pozdnyakov;

bool poz::add_command_t::operator()(std::string field) const
{
  return std::find(commands.begin(), commands.end(), field) != commands.end();
}

bool poz::command_t::operator()(std::string field) const
{
  return std::find(commands.begin(), commands.end(), field) != commands.end();
}

bool poz::insert_param_t::operator()(std::string field) const
{
  return std::find(params.begin(), params.end(), field) != params.end();
}

bool poz::move_param_t::operator()(std::string field) const
{
  bool isString = std::find(params.begin(), params.begin(), field) != params.end();
  return isString || std::all_of(field.begin(), field.end(), ::isdigit);
}

bool poz::name_t::operator()(std::string) const
{
  return true;
}

bool poz::int_t::operator()(std::string field) const
{
  return std::all_of(field.begin(), field.end(), ::isdigit);
}

bool poz::string_t::operator()(std::string) const
{
  return true;
}

#include <cstdlib>
#include <cstring>
#include <functional>
#include <map>

#include "task1.hpp"
#include "task2.hpp"
#include "task3.hpp"
#include "task4.hpp"
#include "errors.hpp"

namespace lab = ezerinia;

bool isDigit(const char *src)
{
  for (size_t i = 0; i < strlen(src); i++) {
    if (src[i] == ' ' || !isdigit(src[i])) {
      return false;
    }
  }
  return true;
}

template< typename T >
std::function< bool(T, T) > getSortMode(const char *mode)
{
  const char ascending[] = "ascending";
  const char descending[] = "descending";
  if (!strcmp(mode, ascending)) {
    return std::less< T >();
  } else if (!strcmp(mode, descending)) {
    return std::greater< T >();
  }
  return nullptr;
}

int main(int argc, char *argv[])
{
  std::map< lab::error, std::string > errors{
    {lab::error::success, {}},
    {lab::error::taskNumber, "Incorrect number for task\n"},
    {lab::error::numberArgs, "Wrong number or arguments\n"},
    {lab::error::sortMode, "Incorrect sort mode\n"},
    {lab::error::taskFailed, "Task failed\n"},
    {lab::error::input, "Incorrect input\n"}
  };

  lab::error err = (argc > 1) ? lab::error::success : lab::error::numberArgs;
  err = lab::isNoErrors(err) && isDigit(argv[1]) && atoi(argv[1]) > 0
        && atoi(argv[1]) < 5 ? lab::error::success : lab::error::taskNumber;
  int taskNumber = lab::isNoErrors(err) ? atoi(argv[1]) : 0;

  if (taskNumber == 1 && argc == 3) {
    const std::function< bool(int, int) > &sort_mode = getSortMode< int >(argv[2]);
    err = sort_mode ? lab::task1(sort_mode) : lab::error::sortMode;
  } else if (taskNumber == 2 && argc == 3) {
    err = lab::task2(argv[2]);
  } else if (taskNumber == 3 && argc == 2) {
    err = lab::task3();
  } else if (taskNumber == 4 && argc == 4) {
    const std::function< bool(double, double) > &sort_mode = getSortMode< double >(argv[2]);
    err = sort_mode && isDigit(argv[3]) ? lab::task4(sort_mode, atoi(argv[3])) : lab::error::sortMode;
  } else {
    err = lab::error::numberArgs;
  }

  if (!lab::isNoErrors(err)) {
    std::cerr << errors[err];
  }
  return static_cast< int >(err);
}

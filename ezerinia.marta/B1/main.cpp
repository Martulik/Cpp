#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

#include "task1.hpp"
#include "task2.hpp"
#include "task3.hpp"
#include "task4.hpp"

namespace lab = ezerinia;

int code = 0;
std::string error = "no errors";

bool checkIsDigit(const char *src)
{
  for (size_t i = 0; i < strlen(src); i++) {
    if (src[i] == ' ' || !isdigit(src[i])) {
      return false;
    }
  }
  return true;
}

template< typename T >
std::function< bool(T, T) > getSortMode(char *mode)
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

void setError(std::string src)
{
  error = src;
  code = 1;
}

int main(int argc, char *argv[])
{
  bool enterTask = false;
  if (argc > 1 && checkIsDigit(argv[1]) && atoi(argv[1]) > 0 && atoi(argv[1]) < 5) {
    if (atoi(argv[1]) == 1 && argc == 3) {
      enterTask = true;
      if (getSortMode< double >(argv[2])) {
        code = lab::task1(getSortMode< double >(argv[2]));
      } else {
        setError("Incorrect sort mode\n");
      }
    }

    if (atoi(argv[1]) == 2 && argc == 3) {
      code = lab::task2(argv[2]);
      enterTask = true;
    }

    if (atoi(argv[1]) == 3 && argc == 2) {
      code = lab::task3();
      enterTask = true;
    }

    if (atoi(argv[1]) == 4 && argc == 4) {
      enterTask = true;
      if (atoi(argv[3]) > 0 && checkIsDigit(argv[3]) && getSortMode< double >(argv[2])) {
        code = lab::task4(getSortMode< double >(argv[2]), atoi(argv[3]));
        enterTask = true;
      } else {
        setError("Incorrect arguments\n");
      }
    }

  } else {
    error = "Not enough arguments or incorrect task number\n";
    enterTask = true;
    code = 1;
  }

  if (!enterTask) {
    setError("Wrong number or arguments\n");
  }
  if (error != "no errors") {
    std::cerr << error;
  }
  return code;
}

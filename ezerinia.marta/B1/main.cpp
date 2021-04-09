#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

#include "task1.hpp"
#include "task2.hpp"
#include "task3.hpp"
#include "task4.hpp"

namespace lab = ezerinia;
//
//int code = 0;
//std::string error = "no errors";
//
//bool checkIsDigit(const char *src)
//{
//  for (size_t i = 0; i < strlen(src); i++) {
//    if (src[i] == ' ' || !isdigit(src[i])) {
//      return false;
//    }
//  }
//  return true;
//}
//
//bool checkSortMode(char *mode)
//{
//  if (!strcmp(mode, "ascending") || !strcmp(mode, "descending")) {
//    return true;
//  }
//  return false;
//}
//
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

//void setError(std::string src)
//{
//  error = src;
//  code = 1;
//}
//
//int main(int argc, char *argv[])
//{
//  bool enterTask = false;
//  if (argc > 1 && checkIsDigit(argv[1]) && atoi(argv[1]) > 0 && atoi(argv[1]) < 5) {
//
//    if (atoi(argv[1]) == 1 && argc == 3) {
//      if (checkSortMode(argv[2])) {
//        code = lab::task1(getSortMode< double >(argv[2]));
//        enterTask = true;
//      } else {
//        setError("Incorrect sort mode\n");
//      }
//    }
//
//    if (atoi(argv[1]) == 2 && argc == 3) {
//      code = lab::task2(argv[2]);
//      enterTask = true;
//    }
//
//    if (atoi(argv[1]) == 3 && argc == 2) {
//      code = lab::task3();
//      enterTask = true;
//    }
//
//    if (atoi(argv[1]) == 4 && argc == 4) {
//      if (atoi(argv[3]) > 0 && checkIsDigit(argv[3]) && checkSortMode(argv[2])) {
//        code = lab::task4(getSortMode< double >(argv[2]), atoi(argv[3]));
//        enterTask = true;
//      } else {
//        setError("Incorrect arguments\n");
//      }
//    }
//
//  } else {
//    error = "Not enough arguments or incorrect task number\n";
//    code = 1;
//  }
//
//  if (!enterTask) {
//    setError("Wrong number or arguments\n");
//  }
//  if (error != "no errors") {
//    std::cerr << error;
//  }
//  return code;
//}

bool check_space(const char *src)
{
  for (size_t i = 0; i < strlen(src); i++) {
    if (src[i] == ' ') {
      return true;
    }
  }
  return false;
}

int main(int argc, char *argv[])
{
  int code = 0;
  if (argc > 1) {
    if (check_space(argv[1])) {
      std::cerr << "Task number should not have space\n";
      return 1;
    }
    switch (atoi(argv[1])) {
    case 1:
      if (argc == 3) {
        if (getSortMode< double >(argv[2]) == nullptr) {
          std::cerr << "Wrong sort mode\n";
          return 1;
        }
        code = lab::task1(getSortMode< double >(argv[2]));
      } else {
        std::cerr << "Wrong number of arguments for task 1\n";
        return 1;
      }
      break;

    case 2:
      if (argc == 3) {
        code = lab::task2(argv[2]);
      } else {
        std::cerr << "Wrong number of arguments for task 2\n";
        return 1;
      }
      break;

    case 3:
      if (argc == 2) {
        code = lab::task3();
      } else {
        std::cerr << "Wrong number of arguments for task 3\n";
        return 1;
      }
      break;

    case 4:
      if (argc == 4) {
        int size = atoi(argv[3]);
        if (size <= 0 || check_space(argv[3])) {
          std::cerr << "Wrong size of vector\n";
          return 1;
        }
        if (getSortMode< double >(argv[2]) == nullptr) {
          std::cerr << "Wrong sort mode\n";
          return 1;
        }
        code = lab::task4(getSortMode< double >(argv[2]), size);
      } else {
        std::cerr << "Wrong number of arguments for task 4\n";
        return 1;
      }
      break;
    default:
      std::cerr << "Wrong number of task\n";
      return 1;
    }
  } else {
    std::cerr << "Not enough arguments\n";
    return 1;
  }

  return code;
}
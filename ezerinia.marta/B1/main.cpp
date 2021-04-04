#include <iostream>
#include <cstdlib>
#include <cstring>

#include "tasks.hpp"

bool check_space(const char *src)
{
  for (size_t i = 0; i < strlen(src); i++) {
    if (src[i] == ' ') {
      return true;
    }
  }
  return false;
}

int get_sort_mode(char *mode)
{
  const char ascending[] = "ascending";
  const char descending[] = "descending";
  if (!strcmp(mode, ascending)) {
    return 0;
  } else if (!strcmp(mode, descending)) {
    return 1;
  } else {
    return -1;
  }
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
        int sort_mode = get_sort_mode(argv[2]);
        if (sort_mode < 0) {
          std::cerr << "Wrong sort mode\n";
          return 1;
        }
        code = task1(sort_mode);
      } else {
        std::cerr << "Wrong number of arguments for task 1\n";
        return 1;
      }
      break;

    case 2:
      if (argc == 3) {
        code = task2(argv[2]);
      } else {
        std::cerr << "Wrong number of arguments for task 2\n";
        return 1;
      }
      break;

    case 3:
      if (argc == 2) {
        code = task3();
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
        int sort_mode = get_sort_mode(argv[2]);
        if (sort_mode < 0) {
          std::cerr << "Wrong sort mode\n";
          return 1;
        }
        code = task4(sort_mode, size);
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

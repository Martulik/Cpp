#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <fstream>

#include "tasks.hpp"

bool checkSpace(const char *src)
{
  for (int i = 0; i < strlen(src); i++) {
    if (src[i] == ' ') {
      return 0;
    }
  }
  return 1;
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
  if (argc > 1) {
    if (!checkSpace(argv[1])) {
      std::cerr << "Task number should not have space\n";
      return 1;
    }
    switch (atoi(argv[1])) {
    case 1:
      if (argc == 3) {
        std::vector< int > collection_numbers;
        int number = 0;
        while (std::cin && !(std::cin >> number).eof()) {
          if (std::cin.fail() || std::cin.bad()) {
            std::cerr << "Wrong input\n";
            return 1;
          }
          collection_numbers.push_back(number);
        }
        int sort_mode = get_sort_mode(argv[2]);
        if (sort_mode < 0) {
          std::cerr << "Wrong sort mode\n";
          return 1;
        }
        task1(collection_numbers, sort_mode);
      } else {
        std::cerr << "Wrong number of arguments for task 1\n";
        return 1;
      }
      break;

    case 2:
      if (argc == 3) {
        std::ifstream inputFile(argv[2]);
        if (!inputFile) {
          std::cerr << "File does not exist \n";
          return 1;
        }
        task2(argv[2]);
      } else {
        std::cerr << "Wrong number of arguments for task 2\n";
        return 1;
      }
      break;

    case 3:
      if (argc == 2) {
        std::vector< int > vec;
        int n = 1;
        while (n != 0) {
          std::cin >> n;
          if ((std::cin.eof() && !vec.empty()) || (!std::cin)) {
            std::cerr << "Zero not found\n";
            return 1;
          }
          vec.push_back(n);
        }
        task3(vec);
      } else {
        std::cerr << "Wrong number of arguments for task 3\n";
        return 1;
      }
      break;

    case 4:
      if (argc == 4) {
        int size = atoi(argv[3]);
        if (size <= 0 || !checkSpace(argv[3])) {
          std::cerr << "Wrong size of vector\n";
          return 1;
        }
        int sort_mode = get_sort_mode(argv[2]);
        if (sort_mode < 0) {
          std::cerr << "Wrong sort mode\n";
          return 1;
        }
        task4(sort_mode, size);
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

  return 0;
}

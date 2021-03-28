#include <stdexcept>
#include <iostream>

int main(int argc, char* argv[])
{
  try
  {
    if ((argc < 2) || (argc > 4))
    {
      throw(std::invalid_argument("Incorrect count of arguments"));
    }
    switch (atoi(argv[1]))
    {
    case 1:
      if (argc != 3)
      {
        throw(std::invalid_argument("Incorrect count of arguments for task 1"));
      }
      // task1(argv[2]);
      break;
    case 2:
      if (argc != 3)
      {
        throw(std::invalid_argument("Incorrect count of arguments for task 2"));
      }
      // task2(argv[2]);
      break;
    case 3:
      if (argc != 2)
      {
        throw(std::invalid_argument("Incorrect count of arguments for task 3"));
      }
      // task3;
      break;
    case 4:
      if (argc != 4)
      {
        throw(std::invalid_argument("Incorrect count of arguments for task 4"));
      }
      // task4(argv[2], atoi(argv[3]));
      break;
    default:
      throw(std::invalid_argument("Incorrect task number"));
      break;
    }
  }
  catch (std::invalid_argument& error)
  {
    std::cerr << error.what();
    return 1;
  }

  return 0;
}

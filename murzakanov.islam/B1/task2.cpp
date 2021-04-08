#include "tasks.hpp"
#include <iostream>
#include <vector>
#include <fstream>

void murzakanov::task2(std::string& fileName)
{
  std::ifstream input;
  input.open(fileName);
  if (!input.is_open())
  {
    throw;
  }
  int n = 0;
  char x = 0;
  while (input >> x && !input.eof())
  {
    n++;
  }
  input.clear();
  input.seekg(0);
  char* arr = new char[n];
  for (int i = 0; i < n; i++)
  {
    input.get(arr[i]);
  }
  std::vector< char > vec(arr, arr+n);
  for (int i = 0; i < n; i++)
  {
    std::cout << vec[i];
  }
  delete[] arr;
}

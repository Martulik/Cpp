#include <vector>
#include <fstream>
#include <string>
#include <iostream>

void task2(const std::string& fileName)
{
  std::ifstream input;
  input.open(fileName);
  if (!input.is_open())
  {
    throw;
  }
  int n = 0;
  int x = 0;
  while (input >> x && !input.eof())
  {
    n++;
  }
  input.close();
  input.open(fileName);
  int* arr = new int[n];
  for (int i = 0; i < n; i++)
  {
    input >> arr[i];
  }
  std::vector< int > vec(arr, arr+n);
  std::vector< int >::iterator it = vec.begin();
  std::vector< int >::iterator end = vec.end();
  while (it != end)
  {
    std::cout << *it << " ";
    it++;
  }
  std::cout << "\n";
  delete[] arr;
}

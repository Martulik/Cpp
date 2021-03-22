#include <iostream>
#include <iomanip>
#include <fstream>
#include <limits>
#include <memory>
#include <random>
#include "task1.hpp"

namespace dan = doroshin;

std::streamsize fileLength(std::ifstream& file)
{
  std::streampos save_pos = file.tellg();
  file.seekg(0, std::ios_base::beg);
  file.ignore(std::numeric_limits<std::streamsize>::max());
  std::streamsize length = file.gcount();
  file.clear();
  file.seekg(save_pos);
  return length;
}

// Task 2
void readFile(std::string filename)
{
  std::ifstream in(filename);
  if(!in.is_open()) {
    std::cerr << "Could not open file\n";
    return;
  }
  size_t len = fileLength(in);
  std::unique_ptr< char[] > c_buf = std::make_unique< char[] >(len);
  in.read(c_buf.get(), len);
  std::vector< char > v_buf(c_buf.get(), c_buf.get() + len);
  for(char c: v_buf) {
    std::cout << c;
  }
}

// Task 3
void filterInput()
{
  using It = typename std::vector< int >::iterator;
  std::vector< int > values;
  while(true) {
    int num = 0;
    std::cin >> num;
    if(std::cin.eof() || std::cin.fail()) {
      std::cerr << "Could not input the next number";
    }
    if(num == 0)
      break;
    values.push_back(num);
  }
  if(values.empty())
    return;

  if(values.back() == 1) {
    for(It i = values.begin(); i != values.end();) {
      if(*i % 2 == 0) {
        i = values.erase(i);
      }
      else {
        i++;
      }
    }
  } else if(values.back() == 2) {
    for(It i = values.begin(); i != values.end(); ++i) {
      if(*i % 3 == 0) {
        i = values.insert(++i, 1);
        i = values.insert(++i, 1);
        i = values.insert(++i, 1);
      }
    }
  }
  for(int num: values) {
    std::cout << num << ' ';
  }
  std::cout << '\n';
}

void fillRandom(double* array, size_t size)
{
  std::random_device rd;
  std::default_random_engine gen(rd());
  std::uniform_real_distribution< double > dist(-1.0, 1.0);

  for(size_t i = 0; i < size; ++i) {
    array[i] = dist(gen);
  }
}

template< dan::Ordering::Way Order >
void testRandom(const size_t size)
{
  std::unique_ptr< double[] > array = std::make_unique< double[] >(size);
  double* raw_ptr = array.get();
  fillRandom(raw_ptr, size);
  std::cout << std::fixed << std::setprecision(5);
  for(size_t i = 0; i < size; ++i) {
    std::cout << array[i] << ' ';
  }
  std::cout << '\n';
  dan::insert_sort< double, dan::ArrayPtrStrat< double >, dan::Ordering::ordering_op< Order > >
      (raw_ptr, raw_ptr, raw_ptr + size);
  for(size_t i = 0; i < size; ++i) {
    std::cout << array[i] << ' ';
  }
  std::cout << '\n';
}

int main(int argc, char* argv[])
{
  if(argc < 2) {
    std::cerr << "Provide the task number\n";
    return 0;
  }
  const int task_num = argv[1][0] - '0';
  switch (task_num)
  {
  case 1:
    {
      std::vector< int > values;
      do {
        int num;
        std::cin >> num;
        if(std::cin.fail()) {
          std::cerr << "Not a number\n";
          return 0;
        }
        values.push_back(num);
      } while(!std::cin.eof());
      // std::forward_list< int > l_values(values.begin(), values.end());
      if(argc < 3) {
        std::cerr << "Provide a sorting order";
        return 0;
      }
      std::string order = argv[2];
      if(order == "ascending") {
        doSort< dan::VectorIndexStrat< int >, dan::Ordering::Way::Ascending >(values);
        doSort< dan::VectorAtStrat< int >, dan::Ordering::Way::Ascending >(values);
        // doSort< dan::ListIterStrat< int >, dan::Ordering::Way::Ascending >(l_values);
      }
    }
    break;
  case 2:
    {
      if(argc < 3) {
        std::cerr << "Provide a filename";
        return 0;
      }
      std::string filename = argv[2];
      readFile(filename);
    }
    break;
  case 3:
    filterInput();
    break;
  case 4:
    {
      if(argc < 3) {
        std::cerr << "Provide a sorting order";
        return 0;
      }
      std::string order = argv[2];
      if(argc < 4) {
        std::cerr << "Provide an array length";
        return 0;
      }
      size_t size = atoll(argv[3]);
      if(order == "ascending") {
        testRandom< dan::Ordering::Way::Ascending >(size);
      }
      else if (order == "descending") {
        testRandom< dan::Ordering::Way::Descending >(size);
      }
    }
    break;
  default:
    std::cerr << "Unknown task\n";
    break;
  }
  return 0;
}

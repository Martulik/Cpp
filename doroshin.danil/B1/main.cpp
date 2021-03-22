#include <iostream>
#include <fstream>
#include <limits>
#include <memory>
#include "insert-sort.hpp"
#include "sort-strategies.hpp"

namespace dan = doroshin;

template< typename Strat, dan::Ordering::Way order >
void doSort(typename Strat::container_t values)
{
  dan::insert_sort< int, Strat, dan::Ordering::ordering_op< order > >
      (values, Strat::begin(values), Strat::end(values));
  for(int num: values) {
    std::cout << num << ' ';
  }
  std::cout << '\n';
}

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
  default:
    std::cerr << "Unknown task\n";
    break;
  }
  return 0;
}

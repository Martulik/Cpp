#include "task2.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <memory>
#include "lab-exception.hpp"

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

void doroshin::readFile(std::string filename)
{
  std::ifstream in(filename);
  if(!in.is_open()) {
    throw LabException("Could not open file");
  }
  size_t len = fileLength(in);
  std::unique_ptr< char[] > c_buf = std::make_unique< char[] >(len);
  in.read(c_buf.get(), len);
  std::vector< char > v_buf(c_buf.get(), c_buf.get() + len);
  for(char c: v_buf) {
    std::cout << c;
  }
}

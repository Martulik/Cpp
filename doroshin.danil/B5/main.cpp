#include <iostream>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <vector>
#include <set>
#include "shape.hpp"

namespace dan = doroshin;

int task1(std::istream& in, std::ostream& out)
{
  std::set< std::string > dict;
  while(in) {
    std::string word;
    in >> std::ws >> word;
    if(!word.empty()) {
      dict.emplace(std::move(word));
    }
  }
  for(auto&& word: dict) {
    out << word << '\n';
  }
  return 0;
}

int task2(std::istream& in, std::ostream& out, std::ostream& err)
{
  std::vector< dan::Shape > shapes;
  // 1. Input
  while(!in.eof()) {
    dan::Shape s;
    in >> std::ws >> s;
    if(in.fail() && !in.eof()) {
      err << "Invalid shape\n";
      return 1;
    }
    if(!s.points_.empty()) {
      shapes.push_back(s);
    }
  }
  // 2. Count vertices
  int total_vertices = std::accumulate(shapes.begin(), shapes.end(), 0,
    [](int total, const dan::Shape& shape) {
      return total + shape.points_.size();
    }
  );
  // 3. Count shapes
  struct Stats
  {
    int triangles, squares, rectangles;
  } shape_stats;
  shape_stats = std::accumulate(shapes.begin(), shapes.end(), Stats{0, 0, 0},
    [](Stats total, const dan::Shape& shape) {
      if(shape.points_.size() == 3) {
        total.triangles++;
      }
      else if(shape.points_.size() == 4) {
          total.rectangles++;
        if(dan::isSquare(shape)) {
          total.squares++;
        }
      }
      return total;
    }
  );
  // 4. Delete pentagons
  shapes.erase(std::remove_if(shapes.begin(), shapes.end(),
    [](const dan::Shape& shape) {
      return shape.points_.size() == 5;
    }
    ), shapes.end()
  );
  // 5. Get any point
  std::vector< dan::Point > points;
  points.reserve(shapes.size());
  std::transform(shapes.begin(), shapes.end(), std::back_inserter(points),
    [](const dan::Shape& shape) {
      return shape.points_.front();
    }
  );
  // 6. Sort by number of vertices
  std::sort(shapes.begin(), shapes.end(),
    [](const dan::Shape& lhs, const dan::Shape& rhs) {
      if(lhs.points_.size() == 4 && rhs.points_.size() == 4) {
        return dan::isSquare(lhs);
      }
      return lhs.points_.size() < rhs.points_.size();
    }
  );
  // 7. Output
  out << "Vertices: " << total_vertices << '\n'
      << "Triangles: " << shape_stats.triangles << '\n'
      << "Squares: " << shape_stats.squares << '\n'
      << "Rectangles: " << shape_stats.rectangles << '\n';
  out << "Points: ";
  std::ostream_iterator< dan::Point > output_p(out, " ");
  std::copy(points.begin(), points.end(), output_p);
  out << '\n';
  out << "Shapes:\n";
  std::ostream_iterator< dan::Shape > output_s(out, "\n");
  std::copy(shapes.begin(), shapes.end(), output_s);
  return 0;
}

int main(int argc, char* argv[])
{
  if(argc != 2) {
    std::cerr << "Provide a task number\n";
    return 1;
  }
  if(argv[1][1] != '\0') {
    std::cerr << "Extra characters in task number\n";
    return 1;
  }
  if(argv[1][0] == '1') {
    return task1(std::cin, std::cout);
  }
  else if(argv[1][0] == '2') {
    return task2(std::cin, std::cout, std::cerr);
  }
  else {
    std::cerr << "Unknown task number\n";
    return 1;
  }
  return 0;
}

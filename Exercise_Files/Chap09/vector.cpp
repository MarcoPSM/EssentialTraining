// vector.cpp by Bill Weinman [bw.org]
// updated 2022-06-04
// MarcoPSM 2023-10-21
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::cout << "vector from initializer list:\n";
  std::vector<int> vi1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  printf("size: %d\n", vi1.size());
  printf("front: %d\n", vi1.front());
  printf("back: %d\n", vi1.back());
  std::cout << '\n';

  // iterator
  std::cout << "iterator:\n";
  auto itbegin = vi1.begin();
  auto itend = vi1.end();
  for (auto it = itbegin; it < itend; ++it) {
    printf("%d ", *it);
  }
  std::cout << '\n';

  printf("element 5: %d\n", vi1[5]);
  printf("element 5: %d\n", vi1.at(5));

  std::cout << "range-based for loop:\n";
  for (const auto &i : vi1) {
    printf("%d ", i);
  }
  std::cout << "\n\n";

  std::cout << "insert 42 at begin + 5:\n";
  vi1.insert(vi1.begin() + 5, 42);
  printf("size: %d\n", vi1.size());
  printf("element 5: %d\n", vi1.at(5));

  std::cout << "erase at begin + 5:\n";
  vi1.erase(vi1.begin() + 5);
  printf("size: %d\n", vi1.size());
  printf("element 5: %d\n", vi1.at(5));

  std::cout << "push_back 47:\n";
  vi1.push_back(47);
  printf("size: %d\n", vi1.size());
  printf("vi1.back(): %d\n", vi1.back());
  std::cout << '\n';

  // from C-array
  const size_t size{10};
  int ia[size]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::cout << "vector from C-array:\n";
  std::vector<int> vi2(ia, ia + size);
  for (const auto &i : vi2) {
    printf("%d ", i);
  }
  std::cout << "\n\n";

  // vector of strings
  std::cout << "vector of strings:" << std::endl;
  std::vector<std::string> vs{"one", "two", "three", "four", "five"};
  for (const auto &v : vs) {
    printf("%s\n", v.c_str());
  }
}

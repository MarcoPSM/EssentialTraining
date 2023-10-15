// auto-type2.cpp by Bill Weinman [bw.org]
// updated 2022-05-25
// MarcoPSM 2023-10-15
#include <iostream>
#include <typeinfo>
#include <vector>

int main() {
  std::vector<int> vi{1, 2, 3, 4, 5};
  // for (std::vector<int>::iterator it = vi.begin(); it != vi.end(); ++it) {
  for (auto it = vi.begin(); it != vi.end(); ++it) {
    printf("int is %d\n", *it);
    printf("type of it is %s\n", typeid(it).name());
    std::cout << "type of it is " << typeid(it).name() << std::endl;
  }
}

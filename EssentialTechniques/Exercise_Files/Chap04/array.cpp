// array.cpp by Bill Weinman [bw.org]
// updated 2022-05-25
// MarcoPSM 2023-10-15
#include <iostream>

int main() {
  int array[]{1, 2, 3, 4, 5};
  for (const int &i : array) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}

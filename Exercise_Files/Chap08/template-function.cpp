// template-function.cpp by Bill Weinman [bw.org]
// updated 2022-06-04
// MarcoPSM 2023-10-21
#include <iostream>

template <typename T> T maxof(T a, T b) { return a > b ? a : b; }

int main() {
  int x{47};
  int y{73};
  auto z = maxof<int>(x, y);
  printf("max is %d\n", z);
  return 0;
}

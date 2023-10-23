// for.cpp by Bill Weinman [bw.org]
// updated 2022-06-15
// MarcoPSM 2023-10-15
#include <iostream>

int main() {
  int array[]{1, 2, 3, 4, 5};

  for (int i{0}; i < 5; ++i) {
    printf("element %d is %d\n", i, array[i]);
  }
}

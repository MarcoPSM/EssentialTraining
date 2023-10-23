// pointers.cpp by Bill Weinman [bw.org]
// updated 2022-05-21
// MarcoPSM 2023-10-15
#include <iostream>

int main() {
  int x{7};
  int y{42};
  int *ip = &x;

  printf("The value of x is %d\n", x);
  printf("The value of y is %d\n", y);
  printf("The value of *ip is %d\n", *ip);
}

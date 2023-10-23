// operators.cpp by Bill Weinman [bw.org]
// updated 2022-06-17
// MarcoPSM 2023-10-19
#include <iostream>

int main() {
  auto x = 5;
  auto y = 45;
  printf("x is %d\n", x);
  printf("y is %d\n", y);

  x = y;
  x = y + x;
  x = y * x;
  x = 15;
  x = y / x;
  x = y % x;
  printf("x is %d\n", x);

  // Compound operators
  x += y;

  // bool
  bool a = true;
  bool b{true};
  printf("Size of a is %d bits\n", sizeof(b) * 8);

  if (!a != !b) {
    std::cout << "true" << std::endl;
  } else {
    std::cout << "false" << std::endl;
  }

  // Increment and decrement
  int z = 5;
  std::cout << ++z << std::endl;
  std::cout << z++ << std::endl;
}

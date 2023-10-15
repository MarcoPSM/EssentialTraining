// qualifiers.cpp by Bill Weinman [bw.org]
// updated 2022-06-16
// MarcoPSM 2023-10-15
/* Types of qualifiers
CV Qualifiers   Storage Duration
  const           static
  mutable         register
  volatile        extern
*/
#include <iostream>

int func() {
  static int x{7};
  return ++x;
}

int main() {
  const int i{42};
  std::cout << "The integer is " << i << std::endl;
  std::cout << "The func returns " << func() << std::endl;
  std::cout << "The func returns " << func() << std::endl;
  std::cout << "The func returns " << func() << std::endl;
}

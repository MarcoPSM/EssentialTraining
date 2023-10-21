// 06-solution.cpp by Bill Weinman [bw.org]
// updated 2022-06-01
// MarcoPSM 2023-10-19
#include <iostream>

unsigned long factorial(unsigned long n) {
  auto result = n;
  while (n > 1) {
    result *= --n;
  }
  return result;
}

int main() {
  unsigned long n{5};
  printf("Factorial of %d is %d\n", n, factorial(n));
}

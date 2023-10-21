// recursive-factorial.cpp by Bill Weinman <http://bw.org/>
// updated 2022-06-01
// MarcoPSM 2023-10-19
#include <iostream>

unsigned long factorial(unsigned long n) {
  if (n < 2)
    return 1;
  return n * factorial(n - 1);
}

int main() {
  unsigned long n{5};
  printf("Factorial of %d is %d\n", n, factorial(n));
}

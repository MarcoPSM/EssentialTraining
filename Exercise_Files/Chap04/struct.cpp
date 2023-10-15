// struct.cpp by Bill Weinman [bw.org]
// updated 2022-06-16
// MarcoPSM 2023-10-15
#include <iostream>

struct S {
  int i{};
  double d{};
  const char *s{};
};

int main() {
  S s1{3, 47.9, "string one"};
  s1.d = 73.0;
  auto *sp = &s1;
  sp->i = 4;
  printf("s1: %d, %f, %s\n", s1.i, s1.d, s1.s);
}

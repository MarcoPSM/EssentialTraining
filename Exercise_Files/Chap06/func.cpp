// func.cpp by Bill Weinman <http://bw.org/>
// updated 2020-06-24
// MarcoPSM 2023-10-19
#include <iostream>

void func() {
  int a = 5;
  static int b = 5;
  printf("a=%d b=%d\n", ++a, ++b);
}

void otherfunc(const int &a) {
  //++a;
  printf("a=%d\n", a);
}

int main() {
  std::cout << "this is main()\n";
  func();
  func();
  func();

  int a{47};
  otherfunc(a);
  printf("a=%d\n", a);
}

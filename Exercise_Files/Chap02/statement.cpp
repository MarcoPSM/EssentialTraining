// statement.cpp by Bill Weinman [bw.org]
// updated 2022-05-19
#include <format> // only available in c++20
#include <iostream>

using std::cout;
using std::format;

int main() {
  int x;
  x = 42;

  auto str = format("x is {}\n", x);
  cout << str;
}

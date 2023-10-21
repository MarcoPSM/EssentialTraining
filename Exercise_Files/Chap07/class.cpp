// class.cpp by Bill Weinman <http://bw.org/>
// updated 2022-06-01
// MarcoPSM 2023-10-19
#include <iostream>

// a very simple class
class C1 {
  int c1val{};

public:
  void setvalue(int value) { c1val = value; }
  int getvalue() {
    std::cout << "mutable getter" << std::endl;
    return c1val;
  }
  int getvalue() const {
    std::cout << "const getter" << std::endl;
    return c1val;
  }
};

int main() {
  C1 obj1;
  obj1.setvalue(47);
  const C1 obj2 = obj1;
  printf("obj1 value is %d\n", obj1.getvalue());
  printf("obj2 value is %d\n", obj2.getvalue());
}

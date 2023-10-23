// constructors.cpp by Bill Weinman [bw.org]
// updated 2022-06-18
// MarcoPSM 2023-10-19
#include <iostream>
#include <string>

using std::string;

const string unk{"unknown"};
const string clone_prefix{"clone-"};

// -- interface --
class Animal {
  string a_type{};
  string a_name{};
  string a_sound{};

public:
  Animal(); // default constructor
  Animal(const string &type, const string &name, const string &sound);
  Animal(const Animal &);            // copy constructor
  ~Animal();                         // destructor
  Animal &operator=(const Animal &); // copy/assignment operator
  void print() const;
};

// -- implementation --
Animal::Animal() : a_type(unk), a_name(unk), a_sound(unk) {
  std::cout << "default constructor\n";
}

Animal::Animal(const string &type, const string &name, const string &sound)
    : a_type(type), a_name(name), a_sound(sound) {
  std::cout << "constructor with arguments\n";
}

Animal::Animal(const Animal &a) {
  std::cout << "copy constructor\n";
  a_name = clone_prefix + a.a_name;
  a_type = a.a_type;
  a_sound = a.a_sound;
}

Animal::~Animal() {
  // printf("destructor: %d the %d\n", a_name, a_type);
  std::cout << "destructor: " << a_name << " the " << a_type << std::endl;
}

Animal &Animal::operator=(const Animal &o) {
  std::cout << "assignment operator\n";
  if (this != &o) {
    a_name = clone_prefix + o.a_name;
    a_type = o.a_type;
    a_sound = o.a_sound;
  }
  return *this;
}

void Animal::print() const {
  // printf("%s the %s says %s\n", a_name.c_str(), a_type.c_str(),
  // a_sound.c_str());
  std::cout << a_name << " " << a_type << " " << a_sound << std::endl;
}

int main() {
  Animal a{};
  a.print();
  const Animal b("goat", "bob", "baah");
  b.print();

  const Animal c = b;
  c.print();

  a = c;
  a.print();

  std::cout << "end of main\n";
  return 0;
}

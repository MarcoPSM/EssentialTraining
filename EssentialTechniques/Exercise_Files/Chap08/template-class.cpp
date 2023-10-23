// template-class.cpp by Bill Weinman [bw.org]
// updated 2022-06-21
// MarcoPSM 2023-10-21
#include <exception>
#include <iostream>
#include <memory>
#include <string>

namespace bw {

// simple exception class
class S_err : public std::exception {
  const char *msg;

public:
  S_err() = delete; // no default constructor
  explicit S_err(const char *s) noexcept : msg(s) {}
  const char *what() const noexcept { return msg; }
};

// simple fixed-size LIFO stack template
template <typename T> class Stack {
  static const int default_size{10};
  static const int max_size{1000};
  int S_size{};
  int S_top{};
  std::unique_ptr<T[]> S_ptr{};

public:
  explicit Stack(int s = default_size);
  ~Stack() {
    if (S_ptr)
      S_ptr.release();
  }
  T &push(const T &);
  T &pop();
  bool is_empty() const { return S_top < 0; }
  bool is_full() const { return S_top >= S_size - 1; }
  int top() const { return S_top; }
  int size() const { return S_size; }
};

// Stack<T> constructor
template <typename T> Stack<T>::Stack(int s) {
  if (s > max_size || s < 1)
    throw S_err("invalid stack size");
  else
    S_size = s;
  S_ptr.reset(new T[S_size]);
  S_top = -1;
}

template <typename T> T &Stack<T>::push(const T &i) {
  if (is_full())
    throw S_err("stack full");
  return S_ptr[++S_top] = i;
}

template <typename T> T &Stack<T>::pop() {
  if (is_empty())
    throw S_err("stack empty");
  return S_ptr[S_top--];
}

} // namespace bw

int main() {
  bw::Stack<int> si{5};
  bw::Stack<std::string> ss{5};

  try {
    printf("si size: %d\n", si.size());
    printf("si top: %d\n", si.top());

    for (int i : {1, 2, 3, 4, 5}) {
      si.push(i);
    }

    printf("si top after pushes: %d\n", si.top());
    printf("si is %sfull\n", si.is_full() ? "" : "not ");

    while (!si.is_empty()) {
      printf("popped %d\n", si.pop());
    }

    printf("ss size: %d\n", ss.size());
    printf("ss top: %d\n", ss.top());

    for (const char *s : {"one", "two", "three", "four", "five"}) {
      ss.push(s);
    }

    printf("ss top after pushes: %d\n", ss.top());
    printf("ss is %sfull\n", ss.is_full() ? "" : "not ");

    while (!ss.is_empty()) {
      printf("popped %s\n", ss.pop().c_str());
    }
  } catch (bw::S_err &e) {
    std::printf("Stack error: %s\n", e.what());
    return 1;
  }
}
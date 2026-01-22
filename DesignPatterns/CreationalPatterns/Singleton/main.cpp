#include <iostream>
#include <mutex>
#include <string>
#include <thread>

class Singleton {
  private:
    static Singleton *instance;
    static std::mutex mutex_;

  protected:
    Singleton(const std::string value) : value_(value) {
    }
    ~Singleton() {
    }
    std::string value_;

  public:
    Singleton(Singleton &other) = delete;
    void operator=(const Singleton &) = delete;
    static Singleton *GetInstance(const std::string &value);
    void DoSomething() {
        std::cout << "Doing some business logic" << std::endl;
    }
    std::string value() const {
        return value_;
    }
};

Singleton *Singleton::instance{nullptr};
std::mutex Singleton::mutex_;

Singleton *Singleton::GetInstance(const std::string &value) {
    // This lock stays in place until the function exits
    // and garantees that only one thread can access this method at a time
    std::lock_guard<std::mutex> lock(mutex_);
    if (instance == nullptr) {
        instance = new Singleton(value);
    }
    return instance;
}

void ThreadOne() {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton *singleton = Singleton::GetInstance("FOO");
    std::cout << singleton->value() << "\n";
    singleton->DoSomething();
}

void ThreadTwo() {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton *singleton = Singleton::GetInstance("BAR");
    std::cout << singleton->value() << "\n";
    singleton->DoSomething();
}

int main() {
    std::cout << "Singleton Pattern Demo\n";

    std::cout << "If you see the same value, then singleton was reused (yay!\n"
              << "If you see different values, then 2 singletons were created "
                 "(booo!!)\n\n"
              << "RESULT:\n";
    std::thread t1(ThreadOne);
    std::thread t2(ThreadTwo);
    t1.join();
    t2.join();

    return 0;
}
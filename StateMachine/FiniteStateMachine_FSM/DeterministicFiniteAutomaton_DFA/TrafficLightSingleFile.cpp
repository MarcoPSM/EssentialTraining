/*
g++ -o TrafficLight TrafficLight.cpp
./TrafficLight
*/

#include <iostream>
#include <string>

enum class State { Green, Yellow, Red };

class TrafficLight {
public:
  TrafficLight() : currentState(State::Red) {}

  void changeState() {
    switch (currentState) {
    case State::Green:
      currentState = State::Yellow;
      break;
    case State::Yellow:
      currentState = State::Red;
      break;
    case State::Red:
      currentState = State::Green;
      break;
    }
  }

  std::string getState() const {
    switch (currentState) {
    case State::Green:
      return "Green";
    case State::Yellow:
      return "Yellow";
    case State::Red:
      return "Red";
    }
    return "Unknown";
  }

private:
  State currentState;
};

int main() {
  TrafficLight light;

  for (int i = 0; i < 6; ++i) {
    std::cout << "Current State: " << light.getState() << std::endl;
    light.changeState();
  }

  return 0;
}

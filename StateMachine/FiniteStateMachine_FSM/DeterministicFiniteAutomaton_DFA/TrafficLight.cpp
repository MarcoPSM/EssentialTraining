#include "TrafficLight.hpp"

TrafficLight::TrafficLight() : currentState(State::Red) {}

void TrafficLight::changeState() {
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

std::string TrafficLight::getState() const {
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

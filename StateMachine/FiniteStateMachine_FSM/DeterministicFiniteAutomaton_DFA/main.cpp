/*
g++ -o TrafficLight main.cpp TrafficLight.cpp
./TrafficLight
*/
#include "TrafficLight.hpp"
#include <iostream>

int main() {
  TrafficLight light;

  for (int i = 0; i < 9; i++) {
    std::cout << "Current State: " << light.getState() << std::endl;
    light.changeState();
  }

  return 0;
}

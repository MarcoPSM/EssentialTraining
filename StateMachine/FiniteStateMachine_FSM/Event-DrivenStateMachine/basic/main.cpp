#include "StateMachine.hpp"
#include <fstream>
#include <iostream>

int main() {
  StateMachine sm;
  std::ifstream inputFile("events.txt");
  std::string event;

  if (!inputFile) {
    std::cerr << "Error opening file." << std::endl;
    return 1;
  }

  std::cout << "Initial State: " << sm.getCurrentState() << std::endl;
  while (std::getline(inputFile, event)) {
    sm.handleEvent(event);
    std::cout << "Current State: " << sm.getCurrentState() << std::endl;
  }

  inputFile.close();
  return 0;
}

// To compile and run the program:
// g++ -o state_machine main.cpp StateMachine.cpp
// ./state_machine

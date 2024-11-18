#include "NOPState.hpp"
#include "StateMachine.hpp"
#include <fstream>
#include <iostream>

int main() {
  // Initialize the state machine with the initial state
  StateMachine sm(std::make_unique<NOPState>());
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
// g++ -o state_machine main.cpp StateMachine.cpp NOPState.cpp PNOState.cpp
// POState.cpp PWTState.cpp
// ./state_machine

/*
To build with cmake use the following commands:
$ rm -r build
$ mkdir build
$ cd build
$ cmake ..
$ cmake

cmake will compile both executables: state_machine and StateMachineTest
it's possible to build only one of them using the following command:
$ cmake state_machine
$ cmake StateMachineTest

To run the tests:
$ ./StateMachineTest
To run the program:
$ ./state_machine
*/

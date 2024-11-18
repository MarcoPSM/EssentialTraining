#include "NOPState.hpp"
#include "PNOState.hpp"
#include "POState.hpp"
#include "StateMachine.hpp"
#include <iostream>

void NOPState::handleEvent(StateMachine &machine, const std::string &event) {
  if (event == "E1") {
    machine.setState(std::make_unique<PNOState>());
  } else if (event == "E2") {
    machine.setState(std::make_unique<POState>());
  } else {
    std::cerr << "Invalid event for NOP state: " << event << std::endl;
  }
}

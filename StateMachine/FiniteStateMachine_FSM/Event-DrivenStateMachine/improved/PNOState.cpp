#include "PNOState.hpp"
#include "NOPState.hpp"
#include "POState.hpp"
#include "StateMachine.hpp"
#include <iostream>

void PNOState::handleEvent(StateMachine &machine, const std::string &event) {
  if (event == "E3") {
    machine.setState(std::make_unique<NOPState>());
  } else if (event == "E4") {
    machine.setState(std::make_unique<POState>());
  } else if (event == "E5") {
    machine.setState(std::make_unique<PNOState>());
  } else {
    std::cerr << "Invalid event for PNO state: " << event << std::endl;
  }
}

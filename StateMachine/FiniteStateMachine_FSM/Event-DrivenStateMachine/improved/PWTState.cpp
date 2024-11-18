#include "PWTState.hpp"
#include "NOPState.hpp"
#include "PNOState.hpp"
#include "POState.hpp"
#include "StateMachine.hpp"
#include <iostream>

void PWTState::handleEvent(StateMachine &machine, const std::string &event) {
  if (event == "E9") {
    machine.setState(std::make_unique<NOPState>());
  } else if (event == "E10") {
    machine.setState(std::make_unique<PNOState>());
  } else if (event == "E11") {
    machine.setState(std::make_unique<POState>());
  } else {
    std::cerr << "Invalid event for PWT state: " << event << std::endl;
  }
}

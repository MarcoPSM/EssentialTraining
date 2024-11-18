#include "POState.hpp"
#include "NOPState.hpp"
#include "PWTState.hpp"
#include "StateMachine.hpp"
#include <iostream>

void POState::handleEvent(StateMachine &machine, const std::string &event) {
  if (event == "E6") {
    machine.setState(std::make_unique<NOPState>());
  } else if (event == "E7") {
    machine.setState(std::make_unique<PWTState>());
  } else if (event == "E8") {
    machine.setState(std::make_unique<POState>());
  } else {
    std::cerr << "Invalid event for PO state: " << event << std::endl;
  }
}

#include "StateMachine.hpp"
#include <iostream>

StateMachine::StateMachine() : currentState(NOP) {}

void StateMachine::handleEvent(const std::string &event) {
  if (currentState == NOP) {
    if (event == "E1")
      transitionTo(PNO);
    else if (event == "E2")
      transitionTo(PO);
    else {
      unknownEvent();
    }
  } else if (currentState == PNO) {
    if (event == "E3")
      transitionTo(NOP);
    else if (event == "E4")
      transitionTo(PO);
    else if (event == "E5")
      transitionTo(PNO);
    else {
      unknownEvent();
    }
  } else if (currentState == PO) {
    if (event == "E6")
      transitionTo(NOP);
    else if (event == "E7")
      transitionTo(PWT);
    else if (event == "E8")
      transitionTo(PO);
    else {
      unknownEvent();
    }
  } else if (currentState == PWT) {
    if (event == "E9")
      transitionTo(NOP);
    else if (event == "E10")
      transitionTo(PNO);
    else if (event == "E11")
      transitionTo(PO);
    else {
      unknownEvent();
    }
  }
}

std::string StateMachine::getCurrentState() const {
  switch (currentState) {
  case NOP:
    return "NOP";
  case PNO:
    return "PNO";
  case PO:
    return "PO";
  case PWT:
    return "PWT";
  default:
    return "Unknown";
  }
}

void StateMachine::unknownEvent() { std::cout << "Unknown Event" << std::endl; }

void StateMachine::transitionTo(State newState) { currentState = newState; }

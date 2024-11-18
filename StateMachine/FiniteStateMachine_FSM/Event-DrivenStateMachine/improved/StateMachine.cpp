#include "StateMachine.hpp"
#include <iostream>

StateMachine::StateMachine(std::unique_ptr<State> initialState)
    : currentState(std::move(initialState)) {}

void StateMachine::handleEvent(const std::string &event) {
  currentState->handleEvent(*this, event);
}

std::string StateMachine::getCurrentState() const {
  return currentState->getName();
}

void StateMachine::setState(std::unique_ptr<State> newState) {
  currentState = std::move(newState);
}

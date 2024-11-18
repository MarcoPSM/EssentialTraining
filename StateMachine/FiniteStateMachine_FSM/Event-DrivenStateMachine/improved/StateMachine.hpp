#ifndef STATEMACHINE_HPP
#define STATEMACHINE_HPP

#include "State.hpp"
#include <memory>
#include <string>

class StateMachine {
public:
  explicit StateMachine(std::unique_ptr<State> initialState);
  void handleEvent(const std::string &event);
  std::string getCurrentState() const;

  void setState(std::unique_ptr<State> newState);

private:
  std::unique_ptr<State> currentState;
};

#endif // STATEMACHINE_HPP

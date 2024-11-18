#ifndef STATEMACHINE_HPP
#define STATEMACHINE_HPP

#include <string>

enum State { NOP, PNO, PO, PWT };

class StateMachine {
public:
  StateMachine();
  void handleEvent(const std::string &event);
  std::string getCurrentState() const;

private:
  State currentState;
  void transitionTo(State newState);
  void unknownEvent();
};

#endif // STATEMACHINE_HPP

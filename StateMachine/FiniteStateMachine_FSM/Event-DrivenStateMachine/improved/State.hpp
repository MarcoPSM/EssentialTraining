#ifndef STATE_HPP
#define STATE_HPP

#include <string>

class StateMachine;

class State {
public:
  virtual ~State() {}
  virtual void handleEvent(StateMachine &machine, const std::string &event) = 0;
  virtual std::string getName() const = 0;
};

#endif // STATE_HPP

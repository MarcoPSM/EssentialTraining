#ifndef NOPSTATE_HPP
#define NOPSTATE_HPP

#include "State.hpp"

class NOPState : public State {
public:
  void handleEvent(StateMachine &machine, const std::string &event) override;
  std::string getName() const override { return "NOP"; }
};

#endif // NOPSTATE_HPP

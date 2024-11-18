#ifndef POSTATE_HPP
#define POSTATE_HPP

#include "State.hpp"

class POState : public State {
public:
  void handleEvent(StateMachine &machine, const std::string &event) override;
  std::string getName() const override { return "PO"; }
};

#endif // POSTATE_HPP

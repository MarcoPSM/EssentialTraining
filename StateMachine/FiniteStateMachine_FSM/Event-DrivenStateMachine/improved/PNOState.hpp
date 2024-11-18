#ifndef PNOSTATE_HPP
#define PNOSTATE_HPP

#include "State.hpp"

class PNOState : public State {
public:
  void handleEvent(StateMachine &machine, const std::string &event) override;
  std::string getName() const override { return "PNO"; }
};

#endif // PNOSTATE_HPP

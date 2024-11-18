#ifndef PWTSTATE_HPP
#define PWTSTATE_HPP

#include "State.hpp"

class PWTState : public State {
public:
  void handleEvent(StateMachine &machine, const std::string &event) override;
  std::string getName() const override { return "PWT"; }
};

#endif // PWTSTATE_HPP

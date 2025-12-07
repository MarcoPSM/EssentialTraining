#ifndef NRDOWNLINKSCHEDULER_HPP
#define NRDOWNLINKSCHEDULER_HPP

#include "ModulationStrategy.hpp"
#include <iostream>
#include <memory>

class NRDownlinkScheduler {
  private:
    std::unique_ptr<ModulationStrategy> modulationStrategy;

  public:
    void setModulationStrategy(std::unique_ptr<ModulationStrategy> strategy) {
        modulationStrategy = std::move(strategy);
    }

    void performModulation() const {
        if (modulationStrategy) {
            std::cout << "Selecting modulation scheme: "
                      << modulationStrategy->getModulationType() << std::endl;
            modulationStrategy->modulate();
        } else {
            std::cout << "No modulation strategy defined!" << std::endl;
        }
    }
};

#endif // NRDOWNLINKSCHEDULER_HPP
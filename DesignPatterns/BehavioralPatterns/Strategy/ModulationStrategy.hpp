#ifndef MODULATION_STRATEGY_HPP
#define MODULATION_STRATEGY_HPP

#include <string>

class ModulationStrategy {
  public:
    virtual ~ModulationStrategy() = default;
    virtual void modulate() const = 0;
    virtual std::string getModulationType() const = 0;
};

#endif // MODULATION_STRATEGY_HPP
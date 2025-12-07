#ifndef MODULATION_STRATEGIES_HPP
#define MODULATION_STRATEGIES_HPP

#include "ModulationStrategy.hpp"
#include <iostream>

// QPSK
class QPSKModulation : public ModulationStrategy {
  public:
    void modulate() const override {
        std::cout << "Modulating using QPSK (low rate, high robustness)."
                  << std::endl;
    }
    std::string getModulationType() const override { return "QPSK"; }
};

// 16-QAM
class QAM16Modulation : public ModulationStrategy {
  public:
    void modulate() const override {
        std::cout
            << "Modulating using 16-QAM (moderate rate, medium robustness)."
            << std::endl;
    }
    std::string getModulationType() const override { return "16-QAM"; }
};

// 64-QAM
class QAM64Modulation : public ModulationStrategy {
  public:
    void modulate() const override {
        std::cout << "Modulating using 64-QAM (high rate, low robustness)."
                  << std::endl;
    }
    std::string getModulationType() const override { return "64-QAM"; }
};

#endif // MODULATION_STRATEGIES_HPP
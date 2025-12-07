/*
  "A lot of modern programming languages have functional type support that
   lets you implement different versions of an algorithm inside a set of
   anonymous functions. Then you could use these functions exactly as you’d
   have used the strategy objects, but without bloating your code with extra
   classes and interfaces."
   https://refactoring.guru/design-patterns/strategy

    This example demonstrates the Strategy pattern using functional programming
*/

#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>

// Functional type for the modulation strategy
using ModulationFunction = std::function<void()>;

/*
  #### Option 1: Using functions for each modulation scheme: ####
*/
// Modulation functions
void modulateQPSK() {
    std::cout << "Modulating using QPSK (low rate, high robustness)."
              << std::endl;
}

void modulateQAM16() {
    std::cout << "Modulating using 16-QAM (moderate rate, medium robustness)."
              << std::endl;
}

void modulateQAM64() {
    std::cout << "Modulating using 64-QAM (high rate, low robustness)."
              << std::endl;
}

/*
  #### End Option 1 ####
*/

/*
  #### Option 2: Using lambdas for each modulation scheme: ####
*/
auto modulateQPSK2 = []() {
    std::cout << "Modulating using QPSK (low rate, high robustness)."
              << std::endl;
};

auto modulateQAM162 = []() {
    std::cout << "Modulating using 16-QAM (moderate rate, medium robustness)."
              << std::endl;
};

auto modulateQAM642 = []() {
    std::cout << "Modulating using 64-QAM (High rate, low robustness)."
              << std::endl;
};
/*
  #### End Option 2 ####
*/

// The context now uses a std::function to store the current strategy:
class NRDownlinkScheduler {
  private:
    ModulationFunction modulationFunction;
    std::string currentModulationType;

  public:
    void setModulationStrategy(ModulationFunction function,
                               const std::string &type) {
        modulationFunction = function;
        currentModulationType = type;
    }

    void performModulation() const {
        if (modulationFunction) {
            std::cout << "Selecting modulation scheme: "
                      << currentModulationType << std::endl;
            modulationFunction();
        } else {
            std::cout << "No modulation strategy defined!" << std::endl;
        }
    }
};

// Now we can use both lambdas and normal functions, and they work equally well.
// Simulating dynamic selection based on SINR, using lambdas:
int main() {
    NRDownlinkScheduler scheduler;

    // Condição: SINR baixo (ex: < 5 dB)
    scheduler.setModulationStrategy(modulateQPSK2, "QPSK");
    scheduler.performModulation();

    // Condição: SINR médio (ex: 10 dB)
    scheduler.setModulationStrategy(modulateQAM162, "16-QAM");
    scheduler.performModulation();

    // Condição: SINR alto (ex: > 20 dB)
    scheduler.setModulationStrategy(modulateQAM642, "64-QAM");
    scheduler.performModulation();

    return 0;
}

// g++ strategy_functional.cpp -o strategy_functional && ./strategy_functional

/*
Use Regular Functions if:
- The strategies are complex or reusable in multiple parts of the code.
- You want to maximize readability and long-term maintainability.
- You need critical performance (avoiding std::function).

Use Lambdas if:
- The strategies are simple and local (e.g., only used in the scheduler).
- You need to capture local variables (e.g., 5G configuration parameters).
- You want to define behaviors inline for rapid prototyping.
*/
#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>

// Functional type for the modulation strategy
using ModulationFunction = std::function<void()>;

// Definition of Strategies. Named lambdas for each modulation scheme
auto modulateQPSK = []() {
    std::cout << "Modulating using QPSK (low rate, high robustness)."
              << std::endl;
};

auto modulateQAM16 = []() {
    std::cout << "Modulating using 16-QAM (moderate rate, medium robustness)."
              << std::endl;
};

auto modulateQAM64 = []() {
    std::cout << "Modulating using 64-QAM (high rate, low robustness)."
              << std::endl;
};
// More strategies can be added here, such as 256-QAM, 512-QAM, etc.

// The context is not affected by the number of modulation types that exist.
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

int askUserForModulation() {
    int choice;
    std::cout << "Which modulation scheme do you want to use:\n";
    std::cout << "1 -> QPSK\n";
    std::cout << "2 -> 16-QAM\n";
    std::cout << "3 -> 64-QAM\n";
    std::cout << "Choose: ";
    std::cin >> choice;
    return choice;
}

// A map that links the user's choice to the corresponding strategy.
std::unordered_map<int, std::pair<ModulationFunction, std::string>>
    modulationMap = {
        {1, {modulateQPSK, "QPSK"}},
        {2, {modulateQAM16, "16-QAM"}},
        {3, {modulateQAM64, "64-QAM"}},
        // You can add more strategies here, like:
        // {4, {modulateQAM256, "256-QAM"}},
};

int main() {
    NRDownlinkScheduler scheduler;

    int userChoice = askUserForModulation();

    // Search for the corresponding strategy in the map
    auto it = modulationMap.find(userChoice);
    if (it != modulationMap.end()) {
        scheduler.setModulationStrategy(it->second.first, it->second.second);
        scheduler.performModulation();
    } else {
        std::cout << "Invalid choice!" << std::endl;
    }

    return 0;
}

// g++ strategy_functional_user_choice.cpp -o strategy_functional_user_choice
// ./strategy_functional_user_choice
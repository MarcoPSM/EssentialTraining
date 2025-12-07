#include "ModulationStrategies.hpp"
#include "NRDownlinkScheduler.hpp"

int main() {
    NRDownlinkScheduler scheduler;

    // Condição: SINR baixo (ex: < 5 dB)
    scheduler.setModulationStrategy(std::make_unique<QPSKModulation>());
    scheduler.performModulation();

    // Condição: SINR médio (ex: 10 dB)
    scheduler.setModulationStrategy(std::make_unique<QAM16Modulation>());
    scheduler.performModulation();

    // Condição: SINR alto (ex: > 20 dB)
    scheduler.setModulationStrategy(std::make_unique<QAM64Modulation>());
    scheduler.performModulation();

    return 0;
}

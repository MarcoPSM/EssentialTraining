# Example of implementing the Strategy design pattern. 

Example of the Strategy pattern for C++, using the dynamic modulation scheme selection (MCS) context in 5G NR DL. In C++, we use abstract classes and polymorphism to implement the pattern.

### How to run 
g++ ModulationStrategy.hpp ModulationStrategies.hpp NRDownlinkScheduler.hpp main.cpp -o strategy && ./strategy
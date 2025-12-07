# Example of implementing the Strategy design pattern. 

Example of the Strategy pattern for C++, using the dynamic modulation scheme selection (MCS) context in 5G NR DL. In C++, we use abstract classes and polymorphism to implement the pattern.

### How to run 
```bash
g++ ModulationStrategy.hpp ModulationStrategies.hpp NRDownlinkScheduler.hpp main.cpp -o strategy && ./strategy
```

## Functional approach of the pattern
It also contains two extra examples for the functional approach: 
- strategy_functional.cpp
- strategy_functional_user_choice.cpp
I considered this approach because it has some advantages:
- More concise code: It is not necessary to create classes and interfaces for 
each strategy.
- Flexibility: You can use normal functions, lambdas, or even function objects (functors).
- Performance: Lambdas in C++ are generally optimized by the compiler, resulting 
in efficient code.

### How to run 
```bash
g++ strategy_functional.cpp -o strategy_functional && ./strategy_functional
g++ strategy_functional_user_choice.cpp -o strategy_functional_user_choice && ./strategy_functional_user_choice
```
# Event-Driven State Machine in C++

## Description

This project implements an Event-Driven State Machine in C++ using the State design pattern. The state machine has four states (`NOP`, `PNO`, `PO`, `PWT`) and responds to eleven events (`E1` to `E11`). The state transition logic is modularized into separate classes, making the code easier to maintain and extend.

## Project Structure

- `State.hpp`: Base interface for all states.
- `StateMachine.hpp` / `StateMachine.cpp`: Implementation of the state machine.
- `NOPState.hpp` / `NOPState.cpp`: Implementation of the `NOP` state.
- `PNOState.hpp` / `PNOState.cpp`: Implementation of the `PNO` state.
- `POState.hpp` / `POState.cpp`: Implementation of the `PO` state.
- `PWTState.hpp` / `PWTState.cpp`: Implementation of the `PWT` state.
- `main.cpp`: Main function that reads events from a file and processes the state machine.

## How to Compile and Run

1. **Compile the code**:
    g++ -o state_machine main.cpp StateMachine.cpp NOPState.cpp PNOState.cpp POState.cpp PWTState.cpp

2. **Run the program**:
    sh ./state_machine

## Input File

The program reads events from a file named `events.txt`, where each line contains an event. Example content of `events.txt`:

## Output

For each processed event, the program prints the current state of the state machine. Example output:

## Improvements Implemented

1. **Modularization and Extensibility**:
    - The state transition logic is separated into distinct classes, making the code easier to maintain and extend.

2. **Use of Design Patterns**:
    - Implementation of the State design pattern, where each state is represented by a distinct class, promoting separation of responsibilities.

3. **Error Handling and Validation**:
    - Validation to ensure only valid events are processed and implementation of error messages for invalid events.

## Contribution

Feel free to contribute with improvements or new features. To do so, fork the repository, create a branch for your changes, and submit a pull request.

## License

This project is licensed under the MIT License. See the `LICENSE` file for more details.

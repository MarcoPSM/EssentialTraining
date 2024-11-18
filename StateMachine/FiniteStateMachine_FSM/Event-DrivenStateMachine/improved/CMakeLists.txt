cmake_minimum_required(VERSION 3.10)
project(StateMachine)

set(CMAKE_CXX_STANDARD 17)

# Adicionar os arquivos de origem
add_executable(state_machine main.cpp StateMachine.cpp NOPState.cpp
                             PNOState.cpp POState.cpp PWTState.cpp)

# Incluir o diretório raiz para os arquivos de cabeçalho
include_directories(${CMAKE_SOURCE_DIR})

# Adicionar Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.11.0.zip)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Adicionar os testes
add_executable(
  StateMachineTest tests/StateMachineTest.cpp StateMachine.cpp NOPState.cpp
                   PNOState.cpp POState.cpp PWTState.cpp)
target_link_libraries(StateMachineTest gtest_main)

include(GoogleTest)
gtest_discover_tests(StateMachineTest)
